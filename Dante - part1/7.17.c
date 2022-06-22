#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    int tablica[5][5], i, j, p=0;
    printf("Podaj macierz 5 na 5: \n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
        int skan=scanf("%d",&tablica[i][j]);

        if(skan!=1)
        {
                printf("Incorrect input\n");
                return 1;
        }
        if(i==0)
        {
            	p+=tablica[i][j];
        }
        else if(j==0)
        {
            	p+=tablica[i][j];
        }
        else if(i==4)
        {
                p+=tablica[i][j];
        }
        else if(j==4)
        {
            	p+=tablica[i][j];
        }
        }
    }

    printf("%d",p);

    return 0;
}
