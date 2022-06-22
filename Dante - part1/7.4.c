#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main (void)
{
	int i,j,k;
	srand(time(NULL));
	for(k=0;k<2;k++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				printf("%d ",rand());
			}
			printf("\n");
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	return 0;
}
