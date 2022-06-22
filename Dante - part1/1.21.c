#include <stdio.h>

int main (void)
{
	float cel,fahr,kelvin;
	printf("Wprowadz celcjusze>>");
	scanf("%f",&cel);
	kelvin=cel+273.15;
	printf("%f\n",kelvin);
	fahr=32+(9.0/5*cel);
	printf("%f",fahr);
	return 0;
}
