#include <stdio.h>


int main() {
  float T[100];
  printf("Podaj ilosc liczb: ");
  int a;
  int y=scanf("%d",&a);
  if(y!=1)
  {
  	printf("Incorrect input\n");
  	return 1;
  }
  if(a>100 || a<=0) return printf("Incorrect input data\n"),2;
  float *wsk=T;
  printf("Podaj liczby: ");
  for(int i=0;i<a;i++,wsk++)
  {
    int x=scanf("%f", wsk);
    if(x!=1)
    {
      printf("Incorrect input\n");
      return 1;
    }
  }
  float *wsk2=wsk;
  for(wsk=T;wsk<wsk2;wsk2--) printf("%f ",*(wsk2-1));
  float suma=0,srednia,ilosc_liczb=0;
  printf("\n");
  wsk=T;
  for(int i=0;i<a;i++,wsk++)
  {
    suma+=*wsk;
    ilosc_liczb+=1;
  }
  printf("Suma wynosi : %.2f\n",suma);
  srednia=suma/ilosc_liczb;
  printf("Srednia wynosi : %.2f\n",srednia);
  return 0;
}
