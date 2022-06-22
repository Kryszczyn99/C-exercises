#include <stdio.h>
#define N 10

int main ()
{
	float tablica[10];
	int i;
	for(i=0;i<N;i=2+i)
	{
		printf("Podaj liczbe: ");
			if(scanf("%f%f",&tablica[i],&tablica[i+1])!=2)
			{
				printf("Input data type error\n");
				return 1;
			}
	}
	for(i=0;i<N;i=i+1)
	{
		printf("tablica[%d]: %f\n",i,tablica[i]);
	}
	
	
	return 0;
}
