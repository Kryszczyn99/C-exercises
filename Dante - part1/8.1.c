#include <stdio.h>

int test1(int a)
{
	return a;
}
int main ()
{
	int a;
	printf("Podaj argument: ");
	int y=scanf("%d",&a);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Wynik funkcji: %d",test1(a));
	return 0;
}
