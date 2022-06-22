#include <stdio.h>

long power_rec(int a, int n)
{
	if(n<0) return 0;
	if(n>0)	return power_rec(a,n-1)*a;
	else return 1;
}

int main ()
{
	printf("Podaj a: ");
	int x;
	int z=scanf("%d",&x);
	if(z!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	int b;
	printf("Podaj n: ");
	int y=scanf("%d",&b);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(b<0)
	{
		printf("Incorrect input data\n");
		return 2;
	}
	printf("Wynik: %ld",power_rec(x,b));
	return 0;
}
