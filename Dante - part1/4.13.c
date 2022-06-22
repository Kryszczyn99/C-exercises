#include <stdio.h>

int main (void)
{
	float a,b;
	printf("Program liczy roznice dwoch liczb\n");
	a=0;
	b=0;
	printf("Podaj a: ");
	if(scanf("%f",&a)!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	if(a==0)
	{
		return 0;
	}
	while(1)
	{
		printf("Podaj b: ");
		if(scanf("%f",&b)!=1)
		{
			printf("Incorrect input\n");
			return 1;
		}
		if(b==0)
		{
			return 0;
		}
		printf("%f\n",b-a);
		a=b;
	}
		
	return 0;
}
