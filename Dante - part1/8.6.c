#include<stdio.h>

float add(float a, float b)
{
	return a+b;	
}

int main()
{
	float a,b;
	printf("Podaj liczbe: ");
	int x=scanf("%f",&a);
	if(x!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj liczbe: ");
	int y=scanf("%f",&b);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("\n");
	printf("Wynik: %f\n",add(a,b));
	return 0;
	
}
