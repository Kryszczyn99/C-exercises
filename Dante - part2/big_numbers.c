#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "big_numbers.h"

int create(struct big_numbers_t *bn, int capacity)
{
	if(bn==NULL || capacity<=0) return 1;
	int g=sizeof(char*);
	bn->big_number=(char **)calloc(capacity,g);
	if(bn->big_number==NULL) return 2;
	bn->size=0;
	bn->capacity=capacity;
	return 0;
}
int create_big_numbers(struct big_numbers_t **bn, int capacity)
{
	if(bn==NULL || capacity<=0) return 1;
	int g=sizeof(struct big_numbers_t);
	*bn=(struct big_numbers_t *)calloc(1,g);
	if(*bn==NULL) return 2;
	int y=create(*bn,capacity);
	switch(y)
	{
		case 2:
			{
				free(*bn);
				*bn=NULL;
				return 2;
			}
		case 1:
			{
				free(*bn);
				*bn=NULL;
				return 1;
			}
		case 0:
			{
				return 0;
			}
	}
	return 0;
}

void destroy(struct big_numbers_t *bn)
{
	if(bn==NULL || bn->big_number==NULL || bn->size<0 || bn->capacity<=0) return;
	int i=0;
	int rozmiar=bn->size;
	while(1)
	{
		if(i==rozmiar)
		{
			char **wsk=bn->big_number;
			free(wsk);
			break;
		}
		char *ptr=*(bn->big_number+i);
		free(ptr);
		i++;
	}
	return;
}
void destroy_big_numbers(struct big_numbers_t **bn)
{
	if(bn==NULL || (*bn)->big_number==NULL || (*bn)->size<0 || (*bn)->capacity<=0) return;
	int s=(*bn)->size;
	int c=(*bn)->capacity;
	if(s>c) return;
	destroy(*bn);
	free(*bn);
	*bn=NULL;
	return;
}


int add_big_number(struct big_numbers_t *bn, const char *big_number)
{
	if(bn==NULL) return 1;
	int s=bn->size;
	int c=bn->capacity;
	if(bn->big_number==NULL || c<=0 || s<0 || big_number==NULL) return 1;
	if(s>c) return 1;
	if(s==c) return 3;
	int check=0;
	int number=0;
	int just=0;
	if(*big_number=='-') check++;
	while(1)
	{
		char znak=*(big_number+check);
		if(znak=='\0')
		{
			if(number==0) return 1;
			break;
		}
		else if(isdigit(znak)==0) return 1;
		
		if(just==0)
		{
			if(znak=='0')
			{
				char znak2=*(big_number+check+1);
				if(znak2=='\0') break;
				return 1;
			}
			just=1;
		}
		number=1;
		check++;
	}
	int len=0;
	while(*(big_number+len)!='\0') len++;
	len+=1;
	char *wsk=(char*)malloc(len);
	if(wsk==NULL) return 2;
	int i=0;
	while(1)
	{
		if(*(big_number+i)=='\0')
		{
			*(wsk+i)='\0';
			bn->size+=1;
			break;
		}
		*(wsk+i)=*(big_number+i);
		i++;
	}
	*(bn->big_number+bn->size-1)=wsk;
	return 0;
}
void display(const struct big_numbers_t *bn)
{
	if(bn==NULL) return;
	int s=bn->size;
	int c=bn->capacity;
	if(bn->big_number==NULL || c<=0 || s<0) return;
	if(s>c) return;
	int i=0;
	while(1)
	{
		if(i==s) break;
		char *wsk=*(bn->big_number+i);
		printf("%s\n",wsk);
		i++;
	}
	return;
}
