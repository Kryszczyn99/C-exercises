#include <stdio.h>
#include <stdint.h>
int main ()
{
	printf("Podaj liczbe: ");
	long long int a;
	int y=scanf("%lld",&a);
	if(y!=1) return printf("Input error\n"),~1+1;
	printf("%lld",~a+1);
	return 0;
}
