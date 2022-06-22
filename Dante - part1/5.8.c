#include <stdio.h>
#include <stdlib.h>
#define G 0
#define N 10
int main ()
{
	int tablica[N];
	int i;
	for(i=G;i<N;i=i+2)
	{
		printf("Podaj liczbe: ");
			if(scanf("%d%d",&tablica[i],&tablica[i+1])!=2)
			{
				printf("Input data type error\n");
				return 1;
			}
	}
	float srednia;
	srednia=G;
	for(i=G;i<N;i++)
	{
		srednia=srednia+tablica[i];
	}
	printf("%.4f\n",srednia/N);
	int max;
	max=tablica[G];
	i=G;
	while(i<N)
	{
		if(tablica[i]>max)
		{
			max=tablica[i];
		}
		i=i+1;
	}
	printf("%d\n",max);
	int min;
	min=tablica[G];
	for(i=G;i<N;i++)
	{
		if(tablica[i]<min)
		{
			min=tablica[i];
		}
	}
	printf("%d\n",min);
	return G;
}
