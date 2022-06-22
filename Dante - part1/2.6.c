#include <stdio.h>

int main (void){
	int a,b;
	printf("Podaj liczbe: ");
	if(scanf("%d",&a)!=1){
		printf("Incorrect input");
		return 1;
	}printf("Podaj liczbe: ");
	if(scanf("%d",&b)!=1){
		printf("Incorrect input");
		return 1;
	}
	if(a==0 || b==0){
		printf("Operation not permitted");
		return 1;
	}else if(a%b==0){
		printf("%d is divisible by %d",a,b);
	}else{
		printf("%d is not divisible by %d",a,b);
	}
	
	
	
	
	
	
	return 0;
}
