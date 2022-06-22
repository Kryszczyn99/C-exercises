#include <stdio.h>
#include <string.h>

int main(void)
{
    char tablica[1001];
    int ilosc=0,xx,a=0,e=0,i=0,o=0,u=0,y=0,A=0,E=0,I=0,O=0,U=0,Y=0;
    printf("Podaj slowo: \n");
    if(scanf("%1000[^\n]", tablica)!=1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    int dlugosc=strlen(tablica);
    for(xx=0; xx<=dlugosc-1; ++xx)
    {
        if(tablica[xx]=='A') A++;
        else if(tablica[xx]=='a') a++;
        else if(tablica[xx]=='E') E++;
        else if(tablica[xx]=='e') e++;
        else if(tablica[xx]=='I') I++;
        else if(tablica[xx]=='i') i++;
        else if(tablica[xx]=='O') O++;
        else if(tablica[xx]=='o') o++;
        else if(tablica[xx]=='U') U++;
        else if(tablica[xx]=='u') u++;
        else if(tablica[xx]=='y') y++;
        else if(tablica[xx]=='Y') Y++;
    }
    if(a!=0) ilosc++;
    if(e!=0) ilosc++;
    if(i!=0) ilosc++;
    if(o!=0) ilosc++;
    if(u!=0) ilosc++;
    if(A!=0) ilosc++;
    if(E!=0) ilosc++;
    if(I!=0) ilosc++;
    if(O!=0) ilosc++;
    if(U!=0) ilosc++;
    if(Y!=0) ilosc++;
    if(y!=0) ilosc++;


    printf("%d\n", ilosc);

    return 0;
}
