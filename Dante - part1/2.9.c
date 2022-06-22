#include <stdio.h>

int main (void){
	int x,y;
	printf("Podaj liczbe a: ");
	if(scanf("%d",&x)!=1){
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj liczbe b: ");
	if(scanf("%d",&y)!=1){
		printf("Incorrect input");
		return 1;
	}
	printf("x+y=%d\n",x+y);
	printf("x-y=%d\n",x-y);
	printf("x*y=%d\n",x*y);
	if(y==0){
		printf("Operation not permitted");
	}else{
		printf("x/y=%d",x/y);
	}
	return 0;
}
