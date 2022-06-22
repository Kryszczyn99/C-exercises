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
	int max;
	for(i=0;i<5;i++)
	{
		max=tablica[i][0];
		for(j=0;j<5;j++)
		{
			if(max<tablica[i][j]) max=tablica[i][j];
		}
		printf("%d ",max);
	}
	int max2;
	for(i=0;i<5;i++)
	{	
		max2=tablica[0][i];
		for(j=0;j<5;j++)
		{
			if(max2<tablica[j][i]) max2=tablica[j][i];
		}
		printf("%d ",max2);
	}
	return 0;
}
