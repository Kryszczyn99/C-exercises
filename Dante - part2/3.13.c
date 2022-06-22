#include <stdio.h>
#include <ctype.h>

int main ()
{
    char tab[31]={0};
    printf("Podaj sciezke do pliku: \n");
    scanf("%30[^\n]s",tab);
    FILE *plik1;
    plik1=fopen(tab,"rb");
    if(plik1==NULL)
    {
        return printf("Couldn't open file\n"),4;
    } 
    int g=getc(plik1);
    while(1)
    {
    	if(g==EOF) break;
    	printf("%d\n",g);
    	g=getc(plik1);
	}
    
    
    fclose(plik1);
    return 0;
} 
