#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b=1000;
    printf("Podaj liczbe od 0 do 10: ");
    scanf("%d",&b);
    switch(b)
    {
        case 0: printf("zero\n");
                break;
        case 1: printf("jeden\n");
                break;
        case 2: printf("dwa\n");
                break;
        case 3: printf("trzy\n");
                break;
        case 4: printf("cztery\n");
                break;
        case 5: printf("piec\n");
                break;
        case 6: printf("szesc\n");
                break;
        case 7: printf("siedem\n");
                break;
        case 8: printf("osiem\n");
                break;
        case 9: printf("dziewiec\n");
                break;
        case 10: printf("dziesiec\n");
                break;
        default: printf("Incorrect input\n");
                return 1;                                                                                    
    }
    return 0;
}
