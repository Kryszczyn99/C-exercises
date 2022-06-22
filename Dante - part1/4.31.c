#include <stdio.h>

int main ()
{
	printf("Program sumuje wartoœæ funkcji \n");
	double cds=1e-4;
	double p=0;
	int c=1;
	while(1)
	{
		double k=(double)1.0/(c*(c+1));
		if(k<=cds) break;
		p+=k;
		c++;
	}
	printf("%d %.4f\n",c-1,p);
	
	
	return 0;
}
