#include <stdio.h>

int main ()
{
	int tablica23[11];
	int i;
	for(i=0;i<11;i=1+i)
	{
		tablica23[i]=i;
	}
	for(i=0;i<11;i=i+1)
	{
		printf("%d ",tablica23[i]);
	}
	printf("\n");
	return 0;
}
