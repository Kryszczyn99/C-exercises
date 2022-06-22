#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
  
    int* ptr; 
    int i;
    ptr = (int*)malloc(100 * sizeof(int)); 
    if (ptr == NULL) { 
        printf("Failed to allocate memory\n"); 
        return 8;
    } 
 
    for (i = 0; i < 100; ++i) { 
            *(ptr+i) = i; 
    } 

    for (i = 0; i < 100; ++i) { 
           printf("%d ", *(ptr+i)); 
    } 
  	free(ptr);
    return 0; 
} 
