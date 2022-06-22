#include <stdio.h>
#include <math.h>

int main (void)
{
	float a;
	printf("Wprowadz liczbe:");
	scanf("%f",&a);
	a=2*pow(a,3)-4*pow(a,2)+3*a-7;
	printf("%f",a);
	return 0;
}
