#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define X 1001
#define G 0


int main(void) 
{
    char tablica[X];
    printf("Podaj tablica: \n");
    fgets(tablica, X, stdin);
    int dlugosc=strlen(tablica);
    if(tablica[dlugosc-1]=='\n')
    {
        tablica[dlugosc-1]=G;dlugosc--;
    }
    int zmienna=G;
    int ppp=G;
    for(ppp=G; ppp<dlugosc; ppp=ppp+1)
    {
        if(!isalpha(tablica[ppp]) && tablica[ppp]!=' '){
            printf("Incorrect input");
            return 1;
        }
        
        if(isalpha(tablica[ppp])) zmienna++;
    }
    
    if(zmienna==G){
        printf("Incorrect input");
        return 1;
    }


int pog[X/2];
int bap=G, beep=G;
ppp=G;
while(ppp<dlugosc){
    int JP=G; while(tablica[ppp+JP]!=' ' && tablica[ppp+JP]!=G) JP++;
    if(JP>G && JP==beep) pog[bap++]=ppp;
    if(JP>beep){beep=JP; bap=G; pog[bap++]=ppp;}
    ppp+=JP;
    ppp=ppp+1;
}
    printf("%d %d\n", bap, beep); 

char slowo[X/2];
int JP=G;
ppp=bap-1;
while(ppp>=G)
{
    for(JP=G; JP<beep; JP++) slowo[JP]=tablica[pog[ppp]+JP];
    slowo[beep]=G;
    printf("%s\n", slowo);
    ppp=ppp-1;
}
    
    return G;
}
