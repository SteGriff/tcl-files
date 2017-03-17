#include <stdio.h>
#include <stdlib.h>

double Reciprocate(double Input, double *Numerator, int Depth){

  printf("In %e, Num %f, Dp %i\n",Input, *Numerator, Depth);
  ++Depth;
  double This;
  This=*Numerator/Input;
  int IntThis=This;
  float FThis=This;
  
  if(FThis==IntThis){
    printf("Out %f\n",This);
    return This;
  }
  else if(Depth>6){
    printf("Not accurate enough!\n");
    
    printf("Out %f\n",This);
    return This;
  }
  else{
    double FractionPart=This-IntThis;
    *Numerator=Reciprocate(FractionPart,Numerator,Depth);
    
    printf("Out %f\n",This);
    return This * *Numerator;
    
  }
}

int main(int argc, char *argv[]){

	if(argc==2){
	  double argIn;
	  argIn = atof(argv[1]);
	  
	  double Num=1;
	  double Den = Reciprocate(argIn,&Num,0);
	  int N = Num;
	  int D = Den;
	  printf("  Ans= %i/%i\n",N,D);
	  return 0;
	}
	else{
	  printf("Usage: %s <decimal>\n",argv[0]);
	  return 0;
	}
}
