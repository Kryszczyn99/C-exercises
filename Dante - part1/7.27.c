#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int tablica[5][10];
	printf("Podaj macierz 5 na 10: \n");
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			int skan=scanf("%d",&tablica[i][j]);
			if(skan!=1)
			{
				printf("Incorrect input\n");
				return 1;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",tablica[j][i]);
		}
		printf("\n");
	}
	return 0;
}
