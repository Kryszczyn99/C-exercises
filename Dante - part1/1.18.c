#include <stdio.h>
#include <math.h>

int main(void) {
	float a,b,c,d,f;
	printf("Wprowadz a>>");
	scanf("%f",&a);
	printf("Wprowadz b>>");
	scanf("%f",&b);
	printf("Wprowadz c>>");
	scanf("%f",&c);
	printf("Wprowadz d>>");
	scanf("%f",&d);
	printf("Wprowadz f>>");
	scanf("%f",&f);
	printf("%.4f",(a+b+c+d+f)/5);
	return 0;	
}
