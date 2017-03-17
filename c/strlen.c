#include <stdio.h>

int main(){
  char* string1="abcde";
  int i=0;
  for(i=0; string1[i]!='\0'; ++i){
    printf("Part %i, [%c], is %i to EOS\n",i,string1[i],string1[i]=='\0');
  }
  return 0;
}
