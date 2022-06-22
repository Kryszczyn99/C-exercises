#include <stdio.h>

int sqr(int a)
{
	return a*a;
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
	printf("Wynik funkcji: %d",sqr(a));
	return 0;
}
