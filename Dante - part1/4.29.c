#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int i,a,b;
	b=0;
	srand(time(NULL));
	a=(rand() % 100);
	for(i=0;i<10;i++)
	{
		printf("Podaj liczbe: ");
		scanf("%d",&b);
		if(b>a)
		{
			printf("za duzo\n");
		}else if(b<a)
		{
			printf("za malo\n");
		}else
		{
			printf("wygrales\n");
			return 0;
		}
	}
	printf("przegrales\n");
	
	return 0;
}
