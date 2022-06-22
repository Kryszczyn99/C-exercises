#include <stdio.h>

double km2lm (double distance)
{
	if(distance>=0)
	{
		return distance/1.609344;		
	}
	return -1;
}
double km2nm (double distance)
{
	if(distance>=0)
	{
		return distance/1.851852;
	}
	return -1;
}
int main ()
{
	double a;
	printf("Podaj dystans w km: ");
	int y=scanf("%lf",&a);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(a<0)
	{
		printf("Incorrect input data\n");
		return 2;
	}
	
	printf("%.3lf mile morskie\n",km2nm(a));
	printf("%.3lf mile ladowe\n",km2lm(a));
	
	return 0;
}
