#include <stdio.h>

int main (void)
{
	float d;
	printf("Podaj dwie liczby: ");
	switch(scanf("%f",&d))
	{
		case 0:
			printf("Incorrect input\n");
			return 1;
		default:
			break;	
	}
	float e;
	switch(scanf("%f",&e))
	{
		case 0:
			printf("Incorrect input\n");
			return 1;
		default:
			break;	
	}
	char znak;
	printf("Podaj symbol: ");
	scanf(" %c",&znak);
	switch(znak)
	{
		case '-':
			printf("%.0f",d-e);
			return 0;
		case '+':
			printf("%.0f",d+e);
			return 0;
		case '*':
			printf("%.0f",d*e);
			return 0;
		case '/':
			break;	
		default:
			printf("Incorrect input\n");
			return 1;
	}
	int x=e;
	switch(x)
	{
		case 0:
			printf("Illegal operation\n");
			return 2;
		default:
			printf("%.2f",d/e);
	}
	return 0;
}
