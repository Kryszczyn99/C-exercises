#include <stdio.h>

int main (void){
	int a;
	printf("Podaj liczbe a: ");
	if(scanf("%d",&a)!=1){
		printf("Incorrect input");
		return 1;
	}else if(a>0){
		printf("dodatnia");
	}else if(a<0){
		printf("ujemna");
	}else{
		printf("zerowa");
	}
	return 0;
}
