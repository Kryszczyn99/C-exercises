#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int even_odd(int s, int n);

int main()
{
    int a,b;
    printf("Podaj wartosc : ");
    if(scanf("%d",&a)!=1)   return printf("Incorrect input\n"),1;
    printf("Podaj numer wyrazu: ");
    if(scanf("%d",&b)!=1)   return printf("Incorrect input\n"),1;
    int k=even_odd(a,b);
    if(b<0) return printf("Incorrect input data\n"),2;
    printf("%d\n",k);
}

int even_odd(int s, int n)
{
    if(n<0) return 0;
    int k=even_odd(s,n-1);
    if(n==0) return s;
    else if(k%2==0) return k/2;
    return 3*k+1;
}
