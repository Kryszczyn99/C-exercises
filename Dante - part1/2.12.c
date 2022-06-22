#include <stdio.h>
#include <math.h>

int main (){
	float a,b,c,delta;
	printf("Program liczy funkcje kwadratowa\n");
	printf("Podaj a: ");
	scanf("%f",&a);
	printf("Podaj b: ");
	scanf("%f",&b);
	printf("Podaj c: ");
	scanf("%f",&c);
	
	if(a!=0){
		
		delta=pow(b,2)-(4*a*c);
		if(delta<0){
			printf("brak");
		}else if(delta==0){
			printf("jeden pierwiastek: %f",-b/(2*a));
		}else{
			printf("dwa pierwiastki: %f %f",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
		}
	}
	if (a==0 && b==0 && c==0){
		printf("nieskonczonosc");
		return 0;
	}
		if(a==0 && b==0){
		printf("brak");
		return 0;
	}
	if(a==0){
		printf("jeden pierwiastek: %f", (-c)/(b));
		return 0;
	}
	return 0;	
}
