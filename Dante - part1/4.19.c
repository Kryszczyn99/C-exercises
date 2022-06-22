#include <stdio.h>

int main (void)
{
	int p;
	printf("Podaj liczbe p: ");
	if(scanf("%d",&p)!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}

	if(2>p)
	{
		printf("NO");
		return 0;
	}
		
	int k;
	for(k=2;k<p;k++)
	{
		if(p % k==0)
		{
			printf("NO");
			return 0;
		}
		 
	}
	printf("YES");
	
	return 0;
}
