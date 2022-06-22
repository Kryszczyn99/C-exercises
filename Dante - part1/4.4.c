#include <stdio.h>
#include <math.h>

int main()
{
    long long a,b;
    printf("Podaj liczbe a: ");
    int x=scanf("%lld",&a);
    if(x!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    else
    b=a%10;
    while (a!=0)
    {
        if(a/10==0)
        break;
        a/=10;
        if(a<10)
        printf("Pierwsza cyfra to %lld\n",a);
    }
    printf("Ostatnia cyfra to %lld",b);
    return 0;
}
