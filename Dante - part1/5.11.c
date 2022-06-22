#include <stdio.h>
#define N 500
#define G 0
#define K 10

int main() 
{
  	int tab[N];
	int tabIndex=G;
  	int tablica[K+1]={G,G,G,G,G,G,G,G,G,G,G};
  	int x=G;
  	printf("Podaj liczby: ");
  	while (x!=-1)
	{
    	int y=scanf("%d", &x);
    	if (y==G) 
		{
      		printf("Incorrect input");
      		return 1;
    	}
   	 	if ((x>=G) && (x<=K))
		{
    		tab[tabIndex]=x;
			tabIndex++;
    	}
  	}
	int i;
  	for (i=G;i<tabIndex;i++) 
	{
   		tablica[tab[i]]=tablica[tab[i]]+1;
  	}
  	for(i=G;i<=K;i++) 
  	{
    	printf("%d - %d\n", i, tablica[i]);
  	}

  	return G;
}
