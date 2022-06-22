#include <stdio.h>

long long binary_exponentiation(long long a,unsigned int n);

int main(void)
{
	printf("Podaj liczbe: ");
	long long x;
	if(scanf("%lld",&x)!=1)   return printf("Incorrect input"),1;
	printf("Podaj liczbe: ");
	unsigned int n;
	if(scanf("%u",&n)!=1)   return printf("Incorrect input\n"),1;
	long long k=binary_exponentiation(x,n);
	printf("Wynik: %lld\n",k);
	return 0;
}

long long binary_exponentiation(long long a,unsigned int n)
{
	if(n==0)  return 1;
	if(n%2==0) return  binary_exponentiation(a*a,n/2);
	else return binary_exponentiation(a*a,n/2)*a;
}
