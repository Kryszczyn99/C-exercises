#include<stdio.h>
#include<math.h>

int main (){
	float x;
	printf("Wprowadz x: ");
		if(scanf("%f",&x)!=1){
			printf("Incorrect input");
			return 1;
		}
	float dluga = 5.0000000000000000;	
	float ulamek_1 = (1.0/2);
	float ulamek_2 = (3.0/4);
	float c = (((ulamek_1)*x-2)*(2-(ulamek_2)*x));
	if(x>=-dluga && x<=dluga){
		printf("%f",(2*pow(x,2))+(3*x)-1);
	}else if(x>dluga){
		printf("%f",c);
	}else{
		printf("%f",pow((x+5),2)-10);
	}
	
	
	return 0;
}
