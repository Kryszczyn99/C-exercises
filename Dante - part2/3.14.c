#include <stdio.h>
#include <ctype.h>


int main ()
{
    char tab[31]={0};
    printf("Podaj sciezke do pliku: \n");
    scanf("%30[^\n]s",tab);
    FILE *plik1;
    plik1=fopen(tab,"a"); // mo?na a+ 
    if(plik1==NULL)
    {
        plik1=fopen(tab,"w");
        if(plik1==NULL)
        {
            return printf("Couldn't create file\n"),5;
        } 
    } 
    int c = getchar();
    if (c != '\n') 
    {
        while (c != '\n')   c = getchar();
    }
    printf("Podaj tekst: \n");
    int k=0;
    char znak;
    while(1)
    {
        while(1)
        {
            scanf("%c",&znak);
            if(znak=='\n') break;
            fprintf(plik1,"%c",znak);
            k++;
        }
        if(k==0) break;
        else fprintf(plik1,"%c",znak);
        k=0;
    }
    fclose(plik1);
    printf("File saved\n");
    return 0;   
}
