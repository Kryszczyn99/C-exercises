#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int T[20];
  int *wsk=T;
  srand(time(NULL));
  int i;
  for(i=0;i<20;i++,wsk++)  *wsk=rand() % 20;
  wsk=T;
  for(i=0;i<20;i++,wsk++) printf("%d ",*wsk);
  printf("\n");
  wsk=T;
  for(i=0;i<10;i++,wsk+=2) printf("%d ",*wsk);
  return 0;
}
