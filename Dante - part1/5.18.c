#include <stdio.h>
#define N 100

int main ()
{
	int tab[N+1];
	int tabIndex=0;
	printf("Podaj liczby: ");
    for(tabIndex=0; tabIndex<N; tabIndex++)
    {
        int y=scanf("%d",&tab[tabIndex]);
        if(getchar()!=' ')
        if(y!=1)
        {
            printf("Incorrect input\n");
            return 1;
        }
        if(tabIndex==0 && tab[tabIndex]==0)
        {
            printf("not enough data available\n");
            return 2;
        }
    	if(tab[tabIndex]==0) break;
    	if(tabIndex==N) break;
    
    }
    printf("TabIndex: %d\n",tabIndex);
	printf("%d ",tab[0]);	
	int i,k;
	for(i=1;i<=tabIndex;i++)
	{
		for(k=0;k<=tabIndex;k++)
		{
			if(tab[i]==tab[k])
			{
				printf("break\n");
			}
		}
		
	}
	
	
	return 0;
}
