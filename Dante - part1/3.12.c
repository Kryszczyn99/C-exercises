#include <stdio.h>

int main (void)
{
	float a;
	printf("Podaj kwote: ");
	switch((scanf("%f",&a)))
	{
		
		case 1:
			break;
		default:
			printf("Incorrect input\n");
			return 1;
	}
	switch(a>0)
	{
		default:
			printf("Incorrect input\n");
			return 1;
		case 1:
			break;
	}
	char znak;
	printf("Podaj symbol operacji: ");
	scanf(" %c",&znak);
	switch(znak)
	{
		case 'e':
			printf("%.2f",a/4.2074);
			break;
		case 'f':
			printf("%.2f",a/4.7073);
			break;
		case 'd':
			printf("%.2f",a/3.5382);
			break;	
		default:
			printf("Incorrect input\n");
			return 1;
	}
	
	
	return 0;
}
