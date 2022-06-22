#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int tablica[10][10],q=0,g=0;
	printf("Podaj macierz 10 na 10: \n");
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			int skan=scanf("%d",&tablica[i][j]);
			if(skan!=1)
			{
				printf("Incorrect input\n");
				return 1;
			}
			if((i+j)%2==0)
			{
				q+=tablica[i][j];
			}else
			{
				g+=tablica[i][j];
			}
		}
	}
	if(q==0 || g==0)
	{
		printf("%d",0);
	}else
	{
		printf("%d",q-g);
		
	}
	return 0;
}
