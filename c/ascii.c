#include <stdio.h>

int main(){
  char mychar = 'A';
  int charnum = mychar;
  printf("%c is %i\n",mychar,charnum);
  charnum += 32;
  mychar = charnum;
  printf("%i is %c\n",charnum,mychar);
  return 0;
}
