#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{

    int i, x, y;
    y=0;
    srand(time(0));
    for (i=1; i<=100; i++)
    {
        x = 10 + rand() % 11;
        y += x;
    }
    printf("%d ", y);





    return 0;
}
