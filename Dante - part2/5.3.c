#include <stdio.h>
#include "bit_set.h"

int main ()
{
	printf("podaj liczbe: ");
	union bit_set unia;
	int y=scanf("%hhu",&(unia.znak));
	if(y!=1) return printf("Incorrect input\n"),1;
	printf("%u %u %u %u %u %u %u %u",unia.bity.h,unia.bity.g,unia.bity.f,unia.bity.e,unia.bity.d,unia.bity.c,unia.bity.b,unia.bity.a);
	return 0;
}
