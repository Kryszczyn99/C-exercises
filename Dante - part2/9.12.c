#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
	printf("Podaj typ: ");
	int type;
	int y = scanf("%d", &type);
	if (y != 1) return printf("Incorrect input"), 1;
	if (type != 0 && type != 1) return printf("Incorrect input data"), 2;
	if (type == 0)
	{
		int l1, l2;
		printf("Podaj liczby: ");
		y = scanf("%d %d", &l1, &l2);
		if (y != 2) return printf("Incorrect input"), 1;
		int g = SQR(l1);
		int p = SQR(l2);
		printf("%d\n%d\n", g, p);
		int max=MAX(l1,l2);
		printf("%d\n",max);
		int min=MIN(l1,l2);
		printf("%d\n",min);
	}
	if (type == 1)
	{
		float l1, l2;
		printf("Podaj liczby: ");
		y = scanf("%f %f", &l1, &l2);
		if (y != 2) return printf("Incorrect input"), 1;
		float g = SQR(l1);
		float p = SQR(l2);
		printf("%f\n%f\n",g,p);
		float max=MAX(l1,l2);
		printf("%f\n",max);
		float min=MIN(l1,l2);
		printf("%f\n",min);
	}
	return 0;
}
