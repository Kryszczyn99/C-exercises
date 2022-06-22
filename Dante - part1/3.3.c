#include <stdio.h>

int main (void){
	
	int z1,z2;
	printf("Podaj dwie liczby calkowite: ");
	int p=scanf("%d %d",&z1,&z2);
	int q=(p<<1)+(z1>z2);
	switch (q)
{
	case 4:
		printf ("%d\n%d\n",z2,z1);
		break;
	case 5:
		printf("%d\n%d\n",z1,z2);
		break;
	default:
		printf("Incorrect input\n");
		return 1;	
	}	
	return 0;
}
