#include<stdio.h>

unsigned long factorial_rec (int n)
{
	if(n<0 || n>20) return 0;
	if(n<=1) return 1;
	else return (n*factorial_rec(n-1));
	}
int main()
{
	int n;
	unsigned long s;
	printf("Podaj n: ");
	int y=scanf("%d",&n);
	if(n<0 || n>20)
	{
 	 	printf("incorrect input data\n");
	  	return 2;
	}
	else if(y!=1)
	{
  		printf("Incorrect input\n");
  		return 1;
	}
	s=factorial_rec(n);
	printf("Wynik to: %lu",s);
	return 0;
}
