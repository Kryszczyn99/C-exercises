#include <stdio.h>

int sign(int value)
{
	int T=0;
	return (T<value)-(T>value);
}
int main ()
{
	int T;
	printf("Podaj argument: ");
	int y=scanf("%d",&T);
	switch(y)
	{
	
		case 0: printf("Incorrect input\n");
		return 1;
		case 1: break;
	}
	switch(sign(T))
	{
		case 1: printf("positive\n");
		break;
		case 0: printf("zero\n");
		break;
		default: printf("negative\n");
		break;
	}
	return 0;
}
