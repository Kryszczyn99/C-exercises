#include <stdio.h>

int main (void)
{
	float a,suma;
	int b;
	printf("Program liczy sume 10 liczb\n");
	suma=0;
	for(b=0;b<10;b++)
	{ printf("Podaj liczbe: ");
		while(scanf("%f",&a)!=1)
		{
			printf("Incorrect input");
			return 1;
		}
		suma+=a;
	}
	printf("%f",suma);
	
	
	
	return 0;
}
