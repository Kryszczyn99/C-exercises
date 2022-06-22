#include <stdio.h>

int main (void){
	int a;
	printf("Wprowadz ile punktow: ");
	if(scanf("%d",&a)!=1){
		printf("Incorrect input");
		return 1;
	}else if(a>=0 && a<=10){
		printf("Ocena 2");
	}else if(a>=11 && a<=13){
		printf("Ocena 3");
	}else if(a>=14 && a<=16){
		printf("Ocena 4");
	}else if(a>=17 && a<=20){
		printf("Ocena 5");
	}else{
		printf("Incorrect input");
		return 1;
	}
	
	
	
	return 0;
}
