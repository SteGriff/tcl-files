#include <stdio.h>

int someFunction(int x){
  return 2*x;
}
int main(){
  float x = 5.78;
  if((int)x == 5)
    printf("Yeah! %i\n",someFunction(x));
  else
    printf("No! %i\n",someFunction(x));
  return 0;
}
