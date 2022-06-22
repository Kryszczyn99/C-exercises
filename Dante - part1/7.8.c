#include <stdlib.h>
#include <stdio.h>
#define N 15
#define G 0

int main (void)
{
	int tablica[N][N];
	printf("Podaj macierz N na N: \n");
	int i=G,j;
	while(i<N)
	{
		for(j=G;j<N;j++)
		{
			int skan=scanf("%d",&tablica[i][j]);
			if(skan!=1)
			{
				printf("incorrect input\n");
				return 1;
			}
			if(tablica[i][j]<G || tablica[i][j]>=30)
			{
				printf("value out of range\n");
				return 2;
			}
		}
		i=i+1;
	}
	int k,m,s;
	i=G;
	while(i<N)
	{
		for(j=G;j<N;j=j+1)
		{
			s=G;
			for(k=G;k<N;k=k+1)
			{
				for(m=G;m<N;m=m+1)
				{
				 	if(tablica[i][j]==tablica[k][m]) s+=1;
				}
			}
			printf("%d ",s);
		
		}
		printf("\n");
		i=i+1;
	}
	return G;
}
