#include <stdio.h>

int main (void){
    float x,y;
	printf("Podaj pierwsza liczbe: ");
	if(scanf("%f",&x)!=1){
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj druga liczbe:");
	if(scanf("%f",&y)!=1){
		printf("Incorrect input");
		return 1;}
	printf("x+y=%f\n",x+y);
	printf("x-y=%f\n",x-y);
	printf("x*y=%f\n",x*y);
	if(y==0){
		printf("Operation not permitted");
	}else{
		printf("x/y=%f",x/y);
	}
	
	
	
	
	return 0;
}
