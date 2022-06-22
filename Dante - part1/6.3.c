#include <stdio.h>
#define N 30

int main()
{
    char tablica[N+1];
    printf("Podaj swoja godnosc: \n");
    scanf("%30s",tablica);
    printf("Witaj %s!\n",tablica);
    return 0;
}
