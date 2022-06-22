#include <stdlib.h>
#include <stdio.h>
#define N 5
#define G 0
#define P 4

int main (void)
{
	int tablica[N][N];
	printf("Podaj macierz N na N: \n");
	int i,j;
	for(i=G;i<N;i++)
	{
		for(j=G;j<N;j++)
		{
			int skan=scanf("%d",&tablica[i][j]);
			if(skan!=1)
			{
				printf("Incorrect input\n");
				return 1;
			}
		}
	}
	int tabek[N];
	i=G;
	while(i<N)
	{
		for(j=G;j<N;j++)
		{
			if(i==j) tabek[i]=tablica[i][j];
		}
		i=i+1;
	}
	int tabek2[N];
	for(i=G;i<N;i++)
	{
		for(j=G;j<N;j++)
		{
			if(i+j==P) tabek2[i]=tablica[i][j];
		}
	}
	i=G;
	while(i<N)
	{
		for(j=G;j<N;j++)
		{
			if(i+j==P) printf("%d ",tabek[i]);
			else if(i==j) printf("%d ",tabek2[i]);
			else printf("%d ",tablica[i][j]);
		}
		printf("\n");
		i=i+1;
	}
	return G;
}
