#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	float a,suma;
	int i,b;
	suma=0;
	b=0;
	srand(time(NULL));
	printf("Podaj liczbe liczb: ");
	if(scanf("%d",&b)!=1)
	{
		printf("Improper input data");
		return 1;
	}
	if(b<=10 && b>0)
	{
	for(i=0;i<b;i++)
	{
		a=(((((long double)rand()) / RAND_MAX) * 2 * 5) - 5);
		printf("%.6f\n",a);
		suma+=a;
	}
	printf("Suma: %.4f\n",suma);
	}else 
	{
		printf("Improper input data");
		return 1;
	}

	
	return 0;
}
