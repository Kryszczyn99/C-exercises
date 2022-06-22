#include <stdio.h>
#include <math.h>


int main ()
{
	printf("Podaj poczatek: ");
	int a;
	int x=scanf("%d",&a);
	if(x!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	int b;
	printf("Podaj koniec: ");
	int y=scanf("%d",&b);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(b<a)
	{
		printf("Incorrect input data\n");
		return 2;
	}
	int i,j;
	int wynik=0;
	for(i=a;i<b;i++)
	{
		float srednia=0;
		int suma=0;
		int ilosc=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			{
				suma+=j;
				ilosc+=1;
			}
		}
		srednia=(suma*1.0)/(ilosc*1.0);
		if(sqrt(i)>=srednia) wynik+=1;
	}
	printf("Wynikiem jest liczba: %d",wynik);
	return 0;
}
