#include <stdio.h>

int main ()
{
	int tab[101];
	int tabIndex=0;
	printf("Podaj liczby: ");
    for(tabIndex=0; tabIndex<100; tabIndex++)
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
    if(tabIndex==100) break;
    }	
    printf("Podaj dodatkowa liczbe: ");
    int dodatkowa;
    int z=scanf("%d",&dodatkowa);
    if(z!=1)
    {
    	printf("Incorrect input\n");
    	return 1;
	}
	int i;
	int mniejsze;
	for(i=0,mniejsze=0;i<tabIndex;i++)
	{
		if(tab[i]>dodatkowa) mniejsze++;
	}
	int k;
	int wieksze;
	for(k=0,wieksze=0;k<tabIndex;k++)
	{
		if(tab[k]<dodatkowa) wieksze++;
	}
	printf("%d\n",wieksze);
	printf("%d\n",mniejsze);

	return 0;
}
