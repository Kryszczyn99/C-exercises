#include <stdio.h>

int main ()
{
    float tabka[16]={10, 11, 4, 5, 6, 12, 16, 1, 2, 3, 13, 14, 15, 7, 8, 9};
    int i=0;
    while(i<16)
    {
        printf("%f\n", tabka[i]);
        i = i +2;
    }
    return 0;
}
