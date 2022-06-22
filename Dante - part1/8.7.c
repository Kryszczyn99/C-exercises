#include<stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main()
{
	float a,b;
	printf("Podaj liczbe: ");
	if(scanf("%f",&a)!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj pierwsza liczbe: ");
	if(scanf("%f",&b)!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	printf("Suma: %f\n",add(a,b));
	printf("Roznica: %f\n",subtract(a,b));
	printf("Iloczyn: %f\n",multiply(a,b));
	if(divide(a,b)==-1 && b==0) printf("operation not permitted\n");
	else printf("Iloraz: %f",divide(a,b));
	return 0;
	
}

float add(float a, float b)
{
	return a+b;	
}

float subtract(float a, float b)
{
	return a-b;	
}

float multiply(float a, float b)
{
	return a*b;	
}

float divide(float a, float b)
{
	if(b==0)
	{
		return -1;
	}
	return a/b;	
}
