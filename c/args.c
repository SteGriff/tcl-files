#include <stdio.h>

int main(int argc, char *argv[]){
  printf("I have %i arguments:\n",argc);
  int i;
  for (i=0; i<argc; i++){
    printf("  %i: [%s]\n",i,argv[i]);
  }

  return 0;
}
