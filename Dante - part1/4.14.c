#include <stdio.h>

int main (void)
{
	float a,max,min,b,suma;
	printf("Program pobiera od uzytkownika 100liczb i sprawdza max ,i min\n");
	a=0;
	int i;
	suma=0;
	max=0;
	min=0;
	for(i=0;i<100;i++)
	{	printf("Podaj liczbe: ");
		if(scanf("%f",&a)!=1)
		{
			printf("Incorrect input");
			return 1;
		}
		if(a>b)
		{
			max=a;
			min=b;
		}else if(a<b)
		{
			max=b;
			min=a;
		}
		
		printf("Podaj liczbe: ");
		if(scanf("%f",&b)!=1)
		{
			printf("Incorrect input");
			return 1;
		}
		if(a>b)
		{
			max=a;
			min=b;
		}else if(a<b)
		{
			max=b;
			min=a;
		}
	suma+=a;
	suma+=b;
	}
	printf("Srednia: %.2f\n",suma/100);
	printf("Max: %f",max);
	printf("Min: %f",min);
	
	
	return 0;
}
