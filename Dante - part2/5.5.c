#include <stdio.h>

int main(void) {
  printf("Podaj liczbe: ");
  int number;
  int y=scanf("%d",&number);
  if(y!=1) return printf("Incorrect input\n"),1;
  int b;
  int liczba=0;
  while(number)
  {
    b=number%2;
    if(b==1) liczba+=1;
    number/=2;
  }
  if(liczba%2==0) printf("YES");
  else printf("NO");
  return 0;
}

