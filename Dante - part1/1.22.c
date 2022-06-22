#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)  {
	float a;
	int b;
	printf("Podaj liczbe >>");
	scanf("%f",&a);
	printf("Podaj ile liczb po przecinku:");
	scanf("%d",&b);
	printf("a=%.*f",b,a);
	return 0;
}
