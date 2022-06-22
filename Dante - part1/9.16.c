#include <stdio.h>

int add_comas(long long a, char output[], int size)
{
	
	int i;
	long long b;
	int tablica[50];
	for(i=size;i>=0;i--)
  	{
      	b=a%10;
      	tablica[i]=b;
      	a=a-b;
      	a=a/10;
  	}
  	int k=0;
  	int g=0;
  	for(i=0;i<size;i++)
  	{
  		if(tablica[i]==0 && k==0) k=0;
  		else if(tablica[i]!=0)
  		{
  			output[g]=tablica[i];
  			k=1;
  			g+=1;
		}
		else if(tablica[i]==0 && k==1)
		{
			output[g]=tablica[i];
			g+=1;
		}
	}
	druk(tablica,50);
	return 0;
}

void druk(int output[], int size)
{
	int i;
	for(i=0;i<size;i++) printf("%d ",output[i]);
}

void druk2(char output[],int size)
{
	int i;
	for(i=0;i<size;i++) printf("%c ",output[i]);	
}

int main ()
{
	printf("Podaj liczbe: ");
	long long a;
	int y=scanf("%lld",&a);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	char tab[50];
	add_comas(a,tab,50);
	druk2(tab,50);
	return 0;
}
