#include <stdio.h>

int main()
{
    int i;
    char tekst[] = {'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0'};
    for(i=0;i<13;i++)
    {
        putc(tekst[i],stdout);
        printf(" %d %c \n",tekst[i],tekst[i]);
    }
    return 0;
}
