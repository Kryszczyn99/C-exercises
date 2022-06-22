#include <stdio.h>
#include <stdlib.h>


int main (){
	float x,y,z;
	char tablica;
	
	printf("Podaj pierwsza liczb:");
	if(scanf("%f",&x)!=1){
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj druga liczbe:");
	if(scanf("%f",&y)!=1){
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj symbol operacji:");
    if(scanf(" %c",&tablica)!=1){
		printf("Incorrect input");
		return 1;
	}

	if(tablica == '-'){
		z=x-y;
	    printf("%.0f",z);
	    return 0;
	}
	if(tablica == '+'){
		z=x+y;
		printf("%.0f",z);
		return 0;
	}
	if(tablica == '/'){
		if(y==0){
			printf("Operation not permitted");
			return 2;
		}
		z=x/y;
		printf("%.2f",z);
		return 0;
	}
	if(tablica == '*'){
    	z=x*y;
    	printf("%.0f",z);
    	return 0;
	}
	printf("Incorrect input");
	return 1;
}
