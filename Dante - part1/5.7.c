#include <stdio.h>
#define N 10
#define G 0
int main ()
{
	int tablica[N];
	int i;
	for(i=G;i<N;i=i+2)
	{
		printf("Podaj liczbe: ");
			if(scanf("%d%d",&tablica[i],&tablica[i+1])!=2)
			{
				printf("Input data type error\n");
				return 1;
			}
	}
	for(i=G;i<N;i=i+1)
	{
	    printf("%d",tablica[i]);
	    if(tablica[i]==2)
	    {
	    	printf(" prime\n");
		}
		if(tablica[i]<2)
		{
			printf(" other\n");
		}else
		{
			int d;
			for(d=2;d<tablica[i];d++)
			{
				if(tablica[i] % d==G)
				{
					printf(" composite\n");
					break;
				}
				if(d+1==tablica[i])
				{
					printf(" prime\n");
					break;
				}
			}
			
		}
	}
	
	
	return 0;
}
