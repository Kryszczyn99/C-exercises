#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{	
	srand(time(NULL));
	printf("%d\t", 30 + rand() % 10);
	
	
	return 0;
}
