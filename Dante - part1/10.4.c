#include <stdio.h>

unsigned long sum_rec(int n);

int main()
{
	printf("Podaj liczbe, dla ktorej chcesz policzyc sume: ");
	int n;
	if(scanf("%d",&n)!=1)	return printf("Incorrect input\n"),1;
	if(n<1)	return printf("Incorrect input data\n"), 2;
	printf("%lu",sum_rec(n));
	return 0;	
}
unsigned long sum_rec(int n)
{
	if(n<1)	return 0;
	
	return sum_rec(n-1)+n;
}
