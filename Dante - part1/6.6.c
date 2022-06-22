#include <stdio.h>
#include <string.h>

int main(void)
{
    char imie[11];
    printf("Podaj imie: \n");
    if(scanf("%10s", imie)!=1)
    {
        printf("Incorrect incput\n");
        return 1;
    }
    int dlugosc=strlen(imie)-1;
    if(imie[dlugosc]=='a')
        printf("Imie zenskie\n");
    else
        printf("Imie meskie\n");
    return 0;
}
