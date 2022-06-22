#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Podaj dwie liczby: ");
    scanf("%d %d",&a,&b);

    
    printf("Maximum=%.0f\n",(a+b)/2.0+abs(a-b)/2.0);
    printf("Minimum=%.0f",(a+b)/2.0-abs(a-b)/2.0);
    return 0;
}

