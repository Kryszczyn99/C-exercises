#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main ()
{
	float a,b;
	printf("wprowadz a:");
	scanf("%f",&a);
	printf("wprowadz b:");
	scanf("%f",&b);
	float c;
	c=sqrt(pow(a,2)+pow(b,2));
	printf("%.2f\n",c);
	float kat_1,kat_2;
	kat_1=a/b;
	kat_2=b/a;
	printf("kat_1=%.2f\n",atan(kat_1)*180/PI);
	printf("kat_2=%.2f\n",atan(kat_2)*180/PI);
	return 0;
}
