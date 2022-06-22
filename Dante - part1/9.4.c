#include <stdio.h>

int find_any(const char tab[], const char tab2[]);
int rfind_any(const char tab[], const char tab2[]);


int main ()
{ 
    char znaki[1001];
    char tablica[1001];
    printf("Ciag wyrazow: \n");
        scanf("%1000[^\n]",tablica);
        while(getchar()!='\n');
    printf("Podaj szukane znaki: ");
        scanf("%1000[^\n]",znaki);
        while(getchar()!='\n');
    printf("first %d\n",find_any(tablica,znaki));
    printf("last %d\n",rfind_any(tablica,znaki));
    return 0;
}

int find_any(const char tab[], const char tab2[])
{
    int i=0,j,ilosc1=0,ilosc2=0;
    while(tab2[i]!='\0')
	{
	 ilosc2=ilosc2+1;
	 i=i+1;  
	}
	i=0;
    while(tab[i]!='\0')
	{
	  ilosc1=ilosc1+1;
	  i=i+1; 
	}	
    for(i=0;i<ilosc1;i++)
    {
        for(j=0;j<ilosc2;j++)
        {
            if(tab[i]==tab2[j]) return i;
          }
      }
    return -1;     
}     
int rfind_any(const char tab[], const char tab2[])
{
    int i=0,j,ilosc1=0,ilosc2=0;
    while(tab2[i]!='\0') 
	{
		ilosc2=ilosc2+1;
		i=i+1; 
	}
	i=0;
    while(tab[i]!='\0')
	{
	 	ilosc1=ilosc1+1;
	 	i=i+1;
	}
    for(i=ilosc1;i>=0;i--)
    {
      for(j=0;j<ilosc2;j++)
      {
        if(tab[i]==tab2[j]) return i;
      }
    }
    return -1;     
}    
