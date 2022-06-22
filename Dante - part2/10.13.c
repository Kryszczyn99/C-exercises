#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define integer 4
#include "word_count.h"


int main(int argc, char** argv) 
{
	
	int argumenty=argc;
	char *filename=*(argv+1);
	if(argumenty <= 2) return printf("Not enough arguments"),9;
	int i=2;
	while(1)
	{
		if(i==argumenty) break;
		int error;
		int *err=&error;
		int *wynik;
		char *wsk=*(argv+i);
	    wynik = count_words(filename,err, 1, wsk);
	    if(*err == 3) return printf("Failed to allocate memory"),8;
	    if(*err == 2) return printf("Couldn't open file"),4;
		printf("%d\n", *wynik);
		free(wynik);
		i+=1;
	}
  	return 0;
}



