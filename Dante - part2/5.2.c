//unsigned short int
//binarnym zapisem 2 bajtow
#include <stdio.h>
#include "word_set.h"

int main ()
{
	printf("Podaj liczbe: ");
	union word_set uniaa;
	int y=scanf("%d",&(uniaa.liczba));
	if(y==0) return printf("Incorrect input\n"),1;
	printf("%d %d",*uniaa.tab,*(uniaa.tab+1));
	return 0;
}
