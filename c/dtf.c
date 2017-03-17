#include <stdio.h>
#include <stdlib.h>

double Reciprocate(double Input, double *Numerator, int Depth){

  ++Depth;
  double This;
  This=*Numerator/Input;
  int IntThis=This;
  float FThis=This;
  
  if(FThis==IntThis)
    return This;
  else if(Depth==10){
    printf("Your recurring decimal was not precise enough.\n");
    return This;
  }
  else{
    double FractionPart=This-IntThis;
    *Numerator=Reciprocate(FractionPart,Numerator,Depth);
    return This * *Numerator;
  }
}

int main(int argc, char *argv[]){

	if(argc==2){
	  double argIn;
	  argIn = atof(argv[1]);
	  
	  double Num=1;
	  int D = Reciprocate(argIn,&Num,0);
	  int N = Num;
	  printf("%i/%i\n",N,D);
	  return 0;
	}
	else{
	  printf("Usage: %s <decimal>\n",argv[0]);
	  return 0;
	}
}
