#include<stdio.h>

float quadratic_equation(float a, float b, float c, float x)
{
	return a*x*x+b*x+c;
}

int main()
{
	float x,a,b,c;
	printf("Podaj to rownanie: \n");
	if(scanf("%fx^2%fx%f",&a,&b,&c)!=3)
	{
		printf("Incorrect input\n");
		return 1;	
	}
	printf("Podaj liczbe x: ");
	if(scanf("%f",&x)!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	printf("\n");
	printf("Twoj wynik: %f\n",quadratic_equation(a,b,c,x));
	return 0;
}
