#include <stdio.h>

long int fibonacci(int n);	

int main ()
{
	printf("Podaj n: ");
	int n;
	int y=scanf("%d",&n);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(n<0)
	{
		printf("Incorrect input data");
		return 2;
	}
	printf("Wynik: %ld",fibonacci(n));
	return 0;
}


long int fibonacci(int n)
{
	if(n<0) return -1;
	if(n==0) return 0;
	if(n==1) return 1;
	if(n>1) return (fibonacci(n-1)+fibonacci(n-2));
	else return -1;
	
}

