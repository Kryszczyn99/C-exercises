#include <stdio.h>

int main (void){
	int x;
	printf("Podaj liczbe x: ");
	if(scanf("%d",&x)!=1){
		printf("Incorrect input");
		return 1;
	}else if(x==0){
		printf("Equal to zero");
	}else{
		printf("Not equal to zero");
	}
	
	return 0;
}
