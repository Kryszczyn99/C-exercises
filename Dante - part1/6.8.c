#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
	char tablica[1000];
	
	printf("Podaj liczbe: \n");
	fgets(tablica, 1000,stdin);
	if(strlen(tablica)>100)
	{
		printf("Input is too long\n");
		return 2;
	}
	

	
	
	
	return 0;
}
