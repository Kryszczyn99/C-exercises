#include <stdio.h>
#include "vector_utils.h"
#include "Przesuniecie_o_wektor.h"


int main(void) {
  int Tablica[150];
  printf("Podaj wektor: ");
  int g=read_vector(Tablica,150,0);
  if(g==-1 || g==0) return printf("Not enough data available\n"),3;
  if(g==-2) return printf("Incorrect input\n"),1;
  printf("Podaj o ile ma byc przesuniete: ");
  int przesuniecie;
  int y=scanf("%d",&przesuniecie);
  if(y!=1)
  {
    printf("Incorrect input\n");
    return 1;
  }
  if(przesuniecie<0)
  {
    printf("Incorrect input data\n");
    return 2;
  }
  int kierunek;
  printf("Podaj kierunek: ");
  y=scanf("%d",&kierunek);
  if(y!=1)
  {
    printf("Incorrect input\n");
    return 1;
  }
  if(kierunek<0 || kierunek!=1 || kierunek !=2)
  {
    printf("Incorrect input data\n");
    return 2;
  }
  shift(Tablica,g,przesuniecie,kierunek);
  display_vector(Tablica,g);
  return 0;
}
