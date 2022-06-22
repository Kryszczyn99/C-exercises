#include <stdio.h>

int GCD(int a, int b)
{
	if(a<0) a=a*(-1);
	if(b<0) b=b*(-1);
	if(b==0) return a;
	else if(b>1) return GCD(b,a % b);
	return 1;
}

int main ()
{
	printf("Podaj a: ");
	int a;
	int y=scanf("%d",&a);
	if(y!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	int b;
	printf("Podaj b: ");
	int x=scanf("%d",&b);
	if(x!=1)
	{
		printf("Incorrect input");
		return 1;
	}
	printf("%d",GCD(a,b));
	return 0;
}
