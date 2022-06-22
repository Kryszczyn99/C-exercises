#include <stdio.h>
#include <math.h>

int main(void) {
	int a,b,c;
	printf("Wprowadz a>>");
	scanf("%d",&a);
	printf("Wprowadz b>>");
	scanf("%d",&b);
	printf("Wprowadz c>>");
	scanf("%d",&c);
	float d;
	d=sqrt(pow(a,2)+pow(b,2)+pow(c,2));
	printf("%.2f",d);
	return 0;	
}
