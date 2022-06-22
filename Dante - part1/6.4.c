#include <stdio.h>
#include <string.h>

int main()
{
    char tablica[1001];
    printf("Podaj napis: \n");
    scanf("%1000[^\n]", tablica);
    int dlugosc=strlen(tablica);
    printf("%d\n", dlugosc);
    return 0;
}
