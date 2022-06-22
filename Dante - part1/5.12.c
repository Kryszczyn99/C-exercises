#include <stdio.h>
#define N 1000
#define G 0

int main() 
{
    int tablica[N+1];
    int tabIndex;
    printf("Podaj liczby: ");
    for(tabIndex=G; tabIndex<N; tabIndex=tabIndex+1)
    {
    	int y=scanf("%d",&tablica[tabIndex]);
    	if(getchar()!=' ')
    	if(y!=1)
    	{
    		printf("Incorrect input\n");
    		return 1;
		}
		if(tabIndex==G && tablica[tabIndex]==G)
		{
			printf("Brak danych\n");
			return G;
		}
	if(tablica[tabIndex]==G) break;
	}
	int tabIndex2;
	tabIndex2=tabIndex;
	float sumowanie=G;
	int wieksze=G;
	int mniejsze=G;
	tabIndex=G;
	while(tabIndex<tabIndex2)
	{
		sumowanie+=tablica[tabIndex];
		tabIndex=tabIndex+1;
	}
	printf("%.2f \n",sumowanie/tabIndex2);
	for(tabIndex=G; tabIndex<tabIndex2; tabIndex++)
	{
		if(tablica[tabIndex]>sumowanie/tabIndex2)
		{
			wieksze+=tablica[tabIndex];
		}
	}
	printf("%d \n",wieksze);
	tabIndex=G;
	while(tabIndex<tabIndex2)
	{
		if(tablica[tabIndex]<sumowanie/tabIndex2)
		{
			mniejsze+=tablica[tabIndex];
		}
		tabIndex=tabIndex+1;
	}
	printf("%d \n",mniejsze);
    return G;   
}
