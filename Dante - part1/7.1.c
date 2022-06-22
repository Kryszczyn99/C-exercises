#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i,j;
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			printf("%d ",i*j);
		}
		printf("\n");
	}
	return 0;
}
