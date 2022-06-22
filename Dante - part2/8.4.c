#include <stdio.h>
#include <stdlib.h>
#include "for_loop.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() 
{
    double poczatek;
    printf("Podaj dane (start,step,stop): ");
    int y=scanf("%lf",&poczatek);
    if(y!=1) return printf("Incorrect input"),1;
    double krok;
    y=scanf("%lf",&krok);
    if(y!=1) return printf("Incorrect input"),1;
    double koniec;
    y=scanf("%lf",&koniec);
    if(y!=1) return printf("Incorrect input"),1;
    //zabezpieczenie
    int flaga=0; //jesli bedzie 1 to jest blad
    if(krok>0)
    {
        if(poczatek>koniec) flaga=1;
    }
    else if(krok<0)
    {
        if(poczatek<koniec) flaga=1;
    }
    else if(krok==0) flaga=1;
    if(flaga==1) return printf("Incorrect input data"),2;
    printf("Podaj operacje: ");
    int operacja;
    int rozmiarek=4;
    int rozmiar=sizeof(void(*)(double));
    rozmiar=rozmiar*rozmiarek;
    y=scanf("%d",&operacja);
    if(y!=1) return printf("Incorrect input"),1;
    if(operacja>=0 && operacja<=3)
    {
        void(**funkcja)(double)=(void(**)(double))calloc(1,rozmiar);
        if(funkcja==NULL) return printf("Failed to allocate memory"),8;
        if(operacja==0)
        {
            *funkcja = print_value;
            for_loop(poczatek,krok,koniec,*(funkcja+0));
        } 
        if(operacja==1)
        {
            *(funkcja+1) = print_accumulated;
            for_loop(poczatek,krok,koniec,*(funkcja+1));
        }
        if(operacja==2)
        {
            *(funkcja+2) = print_square;
            for_loop(poczatek,krok,koniec,*(funkcja+2));
        }
        if(operacja==3)
        {
            *(funkcja+3) = print_abs;
            for_loop(poczatek,krok,koniec,*(funkcja+3));
        }
        free(funkcja);
        return 0;
    }
    return printf("Incorrect input data"),2;
}
