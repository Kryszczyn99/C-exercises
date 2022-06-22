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

int ile_kwadratow(int tab[][5],int number)
{
	int k,l;
	int i,j;
	int ilosc=0;
	int ile_pierwszych=0;
	for(k=0;k<3;k++)
	{
	  	for(l=0;l<3;l++)
	  	{
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(is_prime(tab[i+k][j+l])==1)	ile_pierwszych+=1;
					
					}
				}
				if(number==ile_pierwszych) ilosc+=1;
				ile_pierwszych=0;
		}
	}
	return ilosc;
}

void wspolrzedne(int tab[][5],int number)
{
	int k,l;
	int i,j,b=0,g,h;
	int ile_pierwszych=0;
	for(k=0;k<3;k++)
	{
	  	for(l=0;l<3;l++)
	  	{
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(b==0)
						{
							g=i+k;
							h=j+l;
						}
						if(is_prime(tab[i+k][j+l])==1)   ile_pierwszych+=1;
						b+=1;
					}
				}
				if(number==ile_pierwszych)	printf("%d %d\n",g+1,h+1);
				ile_pierwszych=0;
				b=0;
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
	int k,l;
	int max_pierwsze=0;
	int ile_pierwszych=0;
	int zmienna=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(tablica[i][j]>=0) zmienna+=1;
		}
	}
	if(zmienna==0)
	{
		printf("0");
		return 0;
	}
	for(k=0;k<3;k++)
	{
	  	for(l=0;l<3;l++)
	  	{
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(is_prime(tablica[i+k][j+l])==1)	ile_pierwszych+=1;
					}
				}
				if(max_pierwsze<=ile_pierwszych) max_pierwsze=ile_pierwszych;
				ile_pierwszych=0;
		}
	}
	int p=ile_kwadratow(tablica,max_pierwsze);
	printf("%d\n",p);
	wspolrzedne(tablica,max_pierwsze);
	return 0;
}
