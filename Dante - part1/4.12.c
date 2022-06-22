#include <stdio.h>

int main (void)
{
	int n;
	printf("Podaj liczbe: ");
	if(scanf("%d",&n)!=1 || n>21 || n<0)
	{
		printf("Incorrect input");
		return 1;
	}
	int a;
	long long silnia;
	silnia=1;
	for(a=1;a<=n;a++)
	{
		silnia*=a;
	}
	printf("%lld",silnia);
	
	return 0;
}
