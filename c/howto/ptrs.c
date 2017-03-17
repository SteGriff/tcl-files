#include <stdio.h>

void increment(int *xaddr){
	*xaddr += 1;
}
int main(){
	int x=9;
	int y=(int)&x;
	printf("%i address is %i\n",x,y);
	increment(&x);
	printf("x is now %i\n",x);
	return 0;
}
