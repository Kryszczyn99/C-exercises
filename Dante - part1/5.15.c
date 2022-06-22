#include <stdio.h>
#define N 1000
#define G 0

int main ()
{
	int tab[N];
	int tabIndex=G;
	int x=1;
	printf("Podaj liczby: \n");
	while(x!=G)
	{
		int y=scanf("%d",&x);
		if(y==G)
		{
      		printf("Incorrect input");
      		return 1;			
		}
		if(tabIndex==N) break;
		tab[tabIndex]=x;
		tabIndex++;
	}
	tabIndex-=2;
	if(tabIndex==G || tabIndex==-1)
	{
        printf("not enough data available");
        return 2;		
	}
	int i;
	float b;
	if(tabIndex>40)
	{
		tabIndex=1+tabIndex;
		for(i=G;i<tabIndex;i++)
		{
			b=(float)(tab[i]+tab[i+1])/2;
			printf("%.2f ",b);
		}
		return G;
	}
	i=G;
	while(i<tabIndex)
	{
		b=(float)(tab[i]+tab[i+1])/2;
		printf("%.2f ",b);
		i=i+1;
	}
	return G;
}
