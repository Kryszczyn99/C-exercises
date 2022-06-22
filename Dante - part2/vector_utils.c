#include <stdio.h>
#include "vector_utils.h"
#include <stdio.h>


int read_vector(int* tab, int size, int stop_value)
{
    int i=0;
    if(tab==NULL) return -1;
    if(size<1)  return -1;
    int *wsk=tab;
    while(i<size)
    {
        int y=scanf("%d",wsk);
        if(y!=1) return -2;
        if(*wsk==stop_value) break;
        i+=1;
        wsk++;
    }
    if(i==0) return 0;
    return i;
}

/*void display_vector(const int* tab, int size)
{   
    int i=0;
    for(i=0;i<size;i++,tab++)
    {
        printf("%d ",*tab);
    }
} */

/*int read_vector_float(float *vec, int size, float stop_value)
{
    int i=0;
    if(vec==NULL) return -1;
    if(size<1)  return -1;
    float *wsk=vec;
    while(i<size)
    {
        int y=scanf("%f",wsk);
        if(y!=1) return -2;
        if(*wsk==stop_value) break;
        i+=1;
        wsk++;
    }
    
    if(i==0) return 0;
    return i;
}

void display_vector(const int* tab, int size)
{   
    int i=0;
    for(i=0;i<size;i++,tab++)
    {
        printf("%d ",*tab);
    }
}*/
