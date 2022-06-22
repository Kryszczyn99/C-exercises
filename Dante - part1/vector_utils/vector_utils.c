#include <stdio.h>
#include "vector_utils.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int read_vector(int vec[], int size, int stop_value)
{
    int i=0;
    if(size<1)  return -1;
    while(i<size)
    {
        int y=scanf("%d",&vec[i]);
        if(y!=1) return -2;
        if(vec[i]==stop_value) break;
        i+=1;
    }
    if(i==0) return -1;
    int zmienna;
    if ((vec[i] != stop_value || size==i) && vec[i-1]!=stop_value)
    {
        scanf("%d",&zmienna);
        while(zmienna!=stop_value)  scanf("%d", &zmienna);
    } 
    return i;
}

void display_vector(const int vec[], int size)
{   
    int i=0;
    for(i=0;i<size;i++)
    {
        printf("%d ",vec[i]);
    }
}
