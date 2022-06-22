#include <stdio.h>

int is_prime(int number)
{
  	if(number<=1) return 0;
	int i;
	for(i=2;i<number;i++)
	{
		if(number%i==0) return 0;
	}
	return 1;
}

int ilosc(int tab[][5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j==0 || i==0 || j==4 || i==4)
			{
				if(i==0 && j==0)
				{
						
				}
				else if(i==0 && j==4)
				else if(i==4 && j==0)
				else if(i==4 && j==4)
			}
		}
	}
}


int main ()
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
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j==0 || i==0 || j==4 || i==4)
			{
				if((i==0 && j==0) || (i==0 && j==4) || (i==4 && j==0) || (i==4 && j==4))
			}
		}
	}
	
	return 0;
}
