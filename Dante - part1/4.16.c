#include <stdio.h>

int main (void)
{
	float b,iloczyn;
	printf("Program liczy iloczyn liczb uzytkownika\n");
	iloczyn=1;
	while(1)
	{
		printf("Podaj liczbe: ");
		if(scanf("%f",&b)!=1)
		{
			printf("Incorrect input");
			return 0;
		}
		iloczyn*=b;
		printf("Wynik: %.2f \n",iloczyn);
	}	
	
	return 0;
}
