#include<stdio.h>

int add(int a, int b)
{
	return a+b;	
}

int main()
{
	int a,b;
	printf("Podaj liczbe: ");
	int x=scanf("%d",&a);
	if(x!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj liczbe: ");
	int y=scanf("%d",&b);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("\n");
	printf("Wynik: %d\n",add(a,b));
	return 0;
	
}
