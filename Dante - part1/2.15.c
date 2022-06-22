#include <stdio.h>
#include <math.h>


int main (){
	float a,b;
	printf("Wprowadz a: ");
	if(scanf("%f",&a)!=1){
		printf("Incorrect input");
		return 1;}
	printf("Wprowadz b: ");
	if(scanf("%f",&b)!=1){
		printf("Incorrect input");
		return 1;}
	if((a+b)*(a-b)==pow(a,2)+pow(b,2)){
		printf("tozsamosc jest prawdziwa");
	}else{
		printf("tozsamosc nie jest prawdziwa");
	}
	
	
	
	return 0;
}
