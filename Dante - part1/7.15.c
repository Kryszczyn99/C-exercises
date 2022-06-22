#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int tablica[5][5];
	printf("Podaj macierz 5 na 5: \n");
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			int skan=scanf("%d",&tablica[i][j]);
			if(skan!=1)
			{
				printf("Incorrect input\n");
				return 1;
			}
		}
	}
	int przekatna1=0,przekatna2=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i+j==4)
			{
				przekatna2+=tablica[i][j];
			}
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==j)
			{
				przekatna1+=tablica[j][i];
			}
		}
	}
	printf("%d %d",przekatna1,przekatna2);
	return 0;
}
