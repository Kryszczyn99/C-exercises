#include <stdio.h>

int main ()
{
	printf("Podaj liczbe: ");
	int a;
	int y=scanf("%d",&a);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	int i;
	int zmienna=0;
	for(i=1;i<a;i++)
	{
		if((a-1)%i==0)
		{
			zmienna+=1;
		}
		else if((a-1)%i) break;
	}
	
	printf("%d",zmienna);
	return 0;
}
