#include <stdio.h>

int clamp(int v, int lo, int hi)
{
	if(lo<hi)
	{
		if(v<=lo) return lo;
		else if(v>=hi) return hi;
		else return v;
	}
	if(hi<=lo)
	{
		if(v<=hi) return hi;
		else if(v>=lo) return lo;
		else return v;
	}
	return 0;
}

int main ()
{
	printf("Podaj licze: \n");
	int a;
	int x=scanf("%d",&a);
	if(x!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj pierwsza granice: \n");
	int b;
	int y=scanf("%d",&b);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj druga granice: \n");
	int c;
	int z=scanf("%d",&c);
	if(z!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("%d",clamp(a,b,c));
	return 0;
}
