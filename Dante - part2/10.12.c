#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char** argv) 
{
	int i=1;
	int rozmiar=argc;
  	if(rozmiar<=i) return printf("Not enough arguments"),9;
	int suma=0;
	for(;i<=rozmiar-1;i++)
	{
		int size=strlen(*(argv+i));
		int f=0;
		int flaga=0;
		while(f<size)
		{
			if(flaga==1 && *(*(argv+i)+f)=='-') return printf("Incorrect input"),1;
			if(isdigit(*(*(argv+i)+f)));
			else if(*(*(argv+i)+f)=='-') flaga=1;
			else return printf("Incorrect input"),1;
			f++;
		}
		int liczba;
		int p=sscanf(*(argv+i), "%d", &liczba);
		if(p!=1) return printf("Incorrect input"),1;
		suma += liczba;
	}
	printf("%d\n", suma);
	return 0;
}
