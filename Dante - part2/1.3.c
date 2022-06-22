#include <stdio.h>

int main() {
  int T[10];
  int *wsk=&T[0];
  int i;
  for(i=0;i<10;i++,wsk++)
  {
    *wsk=i;
    printf("%d ",*wsk);
  } 
  return 0;
}
