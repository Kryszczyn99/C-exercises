#include <stdio.h>
#define N 10

int main ()
{
	int tablica[N];
	int i;
	for(i=0;i<N;i=i+2)
	{
		printf("Podaj liczbe: ");
			if(scanf("%d%d",&tablica[i],&tablica[i+1])!=2)
			{
				printf("Input data type error\n");
				return 1;
			}
	}
	for(i=0;i<N;i=i+1)
	{
		printf("%d",tablica[i]);
		if(tablica[i] % 2)
		{
			printf(" odd\n");
		}else
		{
			printf(" even\n");
		}
	}
	
	
	return 0;
}
