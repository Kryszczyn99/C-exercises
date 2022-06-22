#include<stdio.h>
#define PI 3.141592
float circumference(float d)
{
	float b;
	if(d<=0)
	{
		return -1;
	}
	b=PI*d;
	return b;	
}

int main()
{
	float d,a;
	printf("Podaj d: \n");
	int y=scanf("%f",&d);
	if(y!=1) d=0;
	a=circumference(d);
	if(a==-1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("%f",a);
	return 0;
	
}
