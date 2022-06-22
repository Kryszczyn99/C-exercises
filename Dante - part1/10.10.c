#include <stdio.h>

int sum_of_digits(long long number)
{	
	if(number<0) number*=-1;
	if(number==0) return 0;
	return number%10 + sum_of_digits(number/10);
}

int main ()
{
	long long n;
	printf("Podaj n: ");
	int y=scanf("%lld",&n);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Wynik: %d",sum_of_digits(n));
	return 0;
}
