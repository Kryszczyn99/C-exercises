#include<stdio.h>

int main(void)
{
    char q;
    printf("A - Breakfast, Lunch and Dinner\n");
    printf("B - Lunch and Dinner only\n");
    printf("C - Dinner only\n");
   	printf("Podaj litere posilku: ");
    scanf("%c",&q);
    switch(q)
    {
        case 'A':
			printf("You chose Breakfast, Lunch and Dinner as your meal plan.\n");

        default:
        	;
    }
    switch(q)
    {
        case 'B':
			printf("You chose Lunch and Dinner as your meal plan.\n");

        default:
        	;
    }
    switch(q)
    {

        case 'C': printf("You chose Dinner as your meal plan.\n");

        default:
        	;
    }
    switch(q)
    {
        case 'A':
			;
        case 'B':
			;
        case 'C':
			return 0;
        default: 
			printf("Incorrect input");
            return 1;
    }
}
