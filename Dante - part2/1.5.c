#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  double T[20];
  double *wsk=T;
  srand(time(NULL));
  int i;
  for(i=0;i<20;i++,wsk++)  *wsk=(rand() / (double)RAND_MAX);
  wsk=T;
  for(i=0;i<20;i++,wsk++) printf("%.1lf ",*wsk);
  printf("\n");
  wsk=T;
  for(i=0;i<10;i++,wsk+=2) printf("%.1lf ",*wsk);
  return 0;
}
