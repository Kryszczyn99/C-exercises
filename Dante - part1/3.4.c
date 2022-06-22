#include <stdio.h>

int main (void){
	
	int z1;
	printf("Podaj liczbe calkowita X: ");
	
     int p=!scanf("%d",&z1);
	int bop=(p<<2)+((z1>0)<<1)+(z1==0);
	switch (bop)
{
	case 2:
		printf ("%d is positive\n",z1);
		break;
	case 1:
		printf("%d is equal to 0\n",z1);
		break;
	case 0:
		printf("%d is negative\n",z1);	
		break;
	default:
		printf("Incorrect input\n");
		return 1;	
	}	
	return 0;
}

