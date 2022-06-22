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
	int suma;
	int tab[5];
	for(i=0;i<5;i++)
	{
		suma=0;
		for(j=0;j<5;j++)
		{
			suma+=tablica[j][i];
		}
		tab[i]=suma;
	}
	int max=tab[0];
	int k=0;
	for(i=0;i<5;i++)
	{
		if(max==tab[i]) k+=1;
		if(max<tab[i]) max=tab[i], k+=1;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(tab[i]==max)
			{
				printf("%d ",tablica[j][i]);
			}

		}
		printf("\n");
	}
	return 0;
}

