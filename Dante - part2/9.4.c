#include <stdint.h>
#include <stdio.h>
#include <math.h>

int function(int i, uint64_t a)
{
	if (i == -1) return 0;
	int l = i % 8;
	long long int p = 2LL;
	p/=2;
	unsigned int w=(a & (p << i))!=0;
	printf("%d", w);
	if (l);
	else printf(" ");
	int g = i - 1;
	return function(g, a);
}

int main()
{
	uint64_t a;
	printf("Podaj wartosc: ");
	int y = scanf("%lu", &a);
	if (y == 0) return printf("Incorrect input\n"), 1;
	int i = pow(8, 2) - 1;
	function(i, a);
	return 0;
}
