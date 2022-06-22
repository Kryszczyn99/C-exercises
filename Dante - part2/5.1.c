//sdfas dsfjfiosad ds fksdaf asf sad
// sdfsda fsad fsadfasd fsadfsafa testuje tylko bez komentarza
#include <stdio.h>
#include "byte_set.h"


int main ()
{
	printf("Podaj liczbe: ");
	union byte_set unia;
	int y=scanf("%d",&(unia.liczba));
	if(y==0) return printf("Incorrect input\n"),1;
	printf("%d %d %d %d",*unia.tab,*(unia.tab+1),*(unia.tab+2),*(unia.tab+3));
	return 0;
}
