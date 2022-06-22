#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		printf("%d ",10 + rand() % 11 );
	}
	
	
	return 0;
}
