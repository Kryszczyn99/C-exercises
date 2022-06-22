#include <stdio.h>

int main (void)
{
	int X;
	printf("Podaj liczbe: ");
	switch( 2*(scanf("%d",&X))+ 2*(X % 2) + (X>0) + (X<0))
	{
		case 5:
			printf("%d is odd",X);
			break;
		case 4:
			printf("%d is even",X);
			break;
		case 3:
			printf("%d is even",X);
			break;
		case 2:
			printf("%d is even",X);
			break;
		case 0:
			printf("Incorrect input\n");
			return 1;
		default:
			printf("%d is even",X);
			break;
	}
	
	return 0;
}
