#include<stdio.h>

float poly(float x)
{
	return 5*x*x+12.55*x+0.75;
}

int main()
{
	float x;
	printf("Podaj liczbe: ");
	if(scanf("%f",&x)!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("\n");
	printf("Wynik: %f\n",poly(x));
	return 0;
}
