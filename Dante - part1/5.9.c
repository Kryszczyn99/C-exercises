#include <stdio.h>
#include <math.h>
#define N 100
#define G 0

int main() 
{
    int tabIndex=G;
    int tab[N];
    int x=G;
    printf("Podaj liczby: ");
    if(scanf("%d",&tab[G])!=1)
    {
        printf("Incorrect input");
        return 1;    	
	}
	tabIndex=1;
    while (x!=-1)
    {
        int y=scanf("%d", &x);
        if (y==G) 
        {
            printf("Incorrect input");
            return 1;
        }
        if(tabIndex==N) break;
        if (x!=-1)
        {
            tab[tabIndex]=x;
            tabIndex++;
        }
    }
    if(tabIndex<G)
    {
    	tabIndex*=-1;
	}
    printf("%d\n",tabIndex);
    

    int i;
    int zmienna;
	zmienna=tab[G];
	i=G;
    while(i<tabIndex)
    {
    	
		if(zmienna>tab[i])
		{
			zmienna=tab[i];
		}
		i=i+1;
		
	}
    printf("%d\n",zmienna);
    i=G;
	while(i<tabIndex)
	{
		if(zmienna<tab[i])
		{
			zmienna=tab[i];
		}
		i=i+1;
	}
	printf("%d\n",zmienna);
    float srednia=G;
    i=G;
    while(i<tabIndex)
    {
        srednia+=tab[i];
        i=i+1;
    }
    printf("%f\n",srednia/tabIndex);
    int suma=G;
    for(i=G;i<tabIndex;i++)
    {
        suma+=tab[i];
    }
    printf("%d\n",suma);
    int fflush(FILE * stream);
    return G;   
}

