#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int a)
{
    int b;
    if(a<=1)
        return 0;
    for(b=2;b<=sqrt(a);b++)
    {
        if(a%b==0)
        return 0;
    }
    return 1;
}
int is_twin(int a, int b)
{       
    if((a+2==b || a-2==b) && is_prime(a)==1 && is_prime(b)==1 ) return 1;
    return 0;
}
int main()
{
    int a,b;
    printf("Podaj poczatek przedzialu: ");
    if (scanf("%d",&a)!=1) 
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj koniec przedzialu: ");
    if (scanf("%d",&b)!=1) 
    {
        printf("Incorrect input");
        return 1;
    }
    if(a>b)
    {
        printf("Incorrect input");
        return 1;
    }
    int i,c=0;
    for(i=a;i<=b;i++)
    {
        if(is_twin(i,i+2) && i+2<=b)
        {
         printf("%d, %d\n",i,i+2);
        c+=1;
       }
    }
    if(c==0)
    {
        printf("Nothing to show\n");
    }
    return 0;
}
