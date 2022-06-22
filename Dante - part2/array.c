#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_create(struct array_t *a, int N)
{
	if(a==NULL || N<=0) return 1; //blad danych wejsciowych
	a->ptr=(int *)malloc((N)*sizeof(int));
	if(a->ptr==NULL) return 2; //blad z zaalokowaniem
	a->capacity=N;
	a->size=0;
	return 0;
}
int array_push_back(struct array_t *a, int value)
{
	if(a==NULL || a->ptr==NULL || a->size<0 || a->capacity<=0 || a->size>a->capacity) return 1;// blad danych wejsciowych
	if(a->size==a->capacity) return 2; //blad z dodaniem do tablicy
	*((a->ptr)+a->size)=value;
	a->size+=1;
	return 0;
}
void array_display(const struct array_t *a)
{
	if(a==NULL || a->ptr==NULL || a->size<=0 || a->capacity<=0 || a->size>a->capacity) return;
	int i;
	for(i=0;i<a->size;i++) printf("%d ",*((a->ptr)+i));
}
void array_destroy(struct array_t *a)
{
	if(a==NULL || a->ptr==NULL) return;
	free(a->ptr);
}
