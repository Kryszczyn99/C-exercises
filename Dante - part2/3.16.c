#include <stdio.h>
#include <ctype.h>

int main ()
{
    char tab[31]={0};
    printf("Podaj sciezke do pliku: \n");
    scanf("%30[^\n]s",tab);
    FILE *plik1;
    plik1=fopen(tab,"r"); 
    if(plik1==NULL)
    {
        plik1=fopen(tab,"w");
    	if(plik1==NULL)    return printf("Couldn't create file\n"),5;
    	printf("File created\n");
    	fclose(plik1);
    	return 0;
    } 
    printf("File already exists!\n");
	fclose(plik1);
 	return 0;   
}
