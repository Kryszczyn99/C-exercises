#include <stdio.h>
#include <stdarg.h>

int stats(int *sum, float *avg, int num,...)
{
	if(sum==NULL || avg==NULL || num<=0) return 1;
	*sum=0;
	*avg=0;
	va_list ap; 
	va_start(ap, num); 
	int i=0;
	for (; i < num; i++)
	{
		int val = va_arg(ap, int);
		*sum += val;
	}
	va_end(ap);
	*avg=(float)*sum/i;
	return 0;
}


int main ()
{
	printf("Podaj ile chcesz liczb: ");
	int liczba;
	int y=scanf("%d",&liczba);
	if(y!=1) return printf("Incorrect input"),1;
	if(liczba<=0 || liczba>3) return printf("Incorrect input data"),2;
	printf("Podaj liczby: ");
	int a=0,b=0,c=0;
	if(liczba==1)
	{
		y=scanf("%d",&a);
		if(y!=1) return printf("Incorrect input"),1;
	}
	if(liczba==2)
	{
		y=scanf("%d",&a);
		if(y!=1) return printf("Incorrect input"),1;
		y=scanf("%d",&b);
		if(y!=1) return printf("Incorrect input"),1;
		
	}
	if(liczba==3)
	{
		y=scanf("%d",&a);
		if(y!=1) return printf("Incorrect input"),1;
		y=scanf("%d",&b);
		if(y!=1) return printf("Incorrect input"),1;
		y=scanf("%d",&c);
		if(y!=1) return printf("Incorrect input"),1;
	}
	int sum=0;
	float srednia=0;
	stats(&sum,&srednia,liczba,a,b,c);
	printf("%d %f\n",sum,srednia);
}
