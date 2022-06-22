#include <stdio.h>

int main ()
{
	int tab[1001];
	int n;
	int i;
	printf("Podaj liczby: \n");
	for(i=1;i<1000;i++)
	{
		int y=scanf("%d",&tab[i]);
		if(getchar()!=' ')
		if(y!=1)
		{
			printf("Incorrect input\n");
			return 1;
		}
		if((i==1 || i==2) && tab[i]==0)
		{
			printf("not enough data available\n");
			return 2;
		}
		if(tab[i]==0) break;
	}
	i=i-1;
	int minus=0;
	if(i%2)
	{
		for(n=0;n<i;n++,i--)
		{
			minus=tab[i]-tab[n];
			printf("%d ",minus);
			printf("NP");
		}
	}else
	{
		for(n=0;n<i;n++,i--)
		{
			minus=tab[i-1]-tab[i-n];
			printf("%d ",minus);
		}
	}
	return 0;
}
