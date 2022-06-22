#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	int y;
	srand(time(NULL));
	for(y=0;;)
	{
		y=(((((long double)rand()) / RAND_MAX) * 2 * 1000) - 1000);
		printf("%d\n",y);
		if(y>=100 && y<=200)
		{
			break;
		}
	}
	
	
	return 0;
}	
