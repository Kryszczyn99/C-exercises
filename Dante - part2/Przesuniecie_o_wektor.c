#include <stdio.h>
#include "Przesuniecie_o_wektor.h"

int shift(int *array, int array_size, int positions_to_shift, enum direction dir)
{
	if(array==NULL) return 1;
	if(array_size<=0) return 1;
	if(positions_to_shift<0) return 1;
    if(dir==ROTATE_RIGHT)
    {
    	
	}
    else if(dir==ROTATE_LEFT)
    {
    	
	}

    return 0;
}
