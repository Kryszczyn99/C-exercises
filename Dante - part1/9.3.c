#include <stdio.h>

int find_string(const char tab[], const char tab2[]);   
int rfind_string(const char tab[], const char tab2[]);
  
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
    printf("%d\n",find_string(tablica,znaki));
    printf("%d\n",rfind_string(tablica,znaki));
    return 0;
}

int find_string(const char tab[], const char tab2[])
{
    int i,j,k=0,ilosc=0,g=0,p=0;
    for(i=0;tab2[i]!='\0';i=i+1) ilosc++;
    if(tab[0]=='\n' && tab2[0]=='\n' ) return 0;
    if((tab[0]=='\n' && tab2[0]!='\n') && (tab[1]==tab2[0])) return 1;
    if(ilosc==1)
    {
        for(i=0;tab[i]!='\0';i=i+1)
        {
            if(tab2[0]==tab[i]) return i;
        }
    }
    for(i=0;i<ilosc;i=i+1)
    {
        for(j=0;tab[j]!='\0';j=j+1)
        {
            if(tab2[i]==tab[j])
            {
                g=(j+1);
                for(k=(i+1);k<=ilosc;k=k+1)
                {
                    if(tab2[k]==tab[g]) p+=1;
                    if(p==ilosc-1) return j;
                    g+=1;
                }
                p=0;
            }
        }
    }
    return -1;     
}     
int rfind_string(const char tab[], const char tab2[])
{
    int i,j,k=0,g=0,p=0,ilosc2=0,ilosc1=0,zmienna=0;
    for(i=0;tab2[i]!='\0';i=i+1) ilosc2++;  
    for(i=0;tab[i]!='\0';i=i+1) ilosc1++;    
    if(ilosc2==1)
    {
        for(i=ilosc1;i>=0;i--)
        {
            if(tab2[0]==tab[i]) return i;
        }
    } 
    if(ilosc2==1) return -1; 
    if(ilosc2==ilosc1)
    {
        for(i=0;tab[i]!='\0';i=i+1)
        {
            if(tab[i]==tab2[i]) zmienna+=1;
            
        } 
        
    }
    if(zmienna==ilosc2) return 0;
    for(i=ilosc2;i>=0;i--)
    {
        for(j=ilosc1;j>=0;j--)
        {
            if(tab2[i]==tab[j])
            {
                p+=1;
                g=(j-1);
                for(k=(i-1);k>=0;k--)
                {   
                    if(tab2[k]==tab[g]) p+=1;
                    if(p==ilosc2) return g;
                    g-=1;
                }
                p=0;
            }
        }
    }
    return -1;
}
