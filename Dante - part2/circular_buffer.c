#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "circular_buffer.h"

int circular_buffer_create(struct circular_buffer_t *a, int N)
{
	if(a==NULL || N<=0) return 1;
	int *wsk=(int *)malloc(N*sizeof(int));
	if(wsk==NULL) return 2;
	a->ptr=wsk;
	a->full=0;
	a->capacity=N;
	a->end=0;
	a->begin=0;
	return 0;
}
int circular_buffer_create_struct(struct circular_buffer_t **cb, int N)
{
	if(cb==NULL || N<=0) return 1;
	*cb=(struct circular_buffer_t *)malloc(sizeof(struct circular_buffer_t));
	if(*cb==NULL) return 2;
	int g=circular_buffer_create(*cb,N);
	if(g==2 || g==1)
	{
		free(*cb);
		return 2;
	}
	return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *a)
{
	if(a==NULL || a->ptr==NULL) return;
	free(a->ptr);
}
void circular_buffer_destroy_struct(struct circular_buffer_t **a)
{
	if(a==NULL) return;
	circular_buffer_destroy(*a);
	if(*a==NULL) return;
	free(*a);
}

int circular_buffer_push_back(struct circular_buffer_t *cb, int value)
{
	if(cb==NULL) return 1;
	if(cb->ptr==NULL || cb->begin>cb->capacity || cb->end>cb->capacity) return 1;
	if(cb->capacity<=0 ||cb->begin<0 ||cb->end<0) return 1;
	if(cb->full!=0 && cb->full!=1) return 1;
	
	if(cb->full==1) 
	{
		*(cb->ptr+cb->begin)=value;	
		if(cb->begin+1>=cb->capacity)cb->begin=0;
		else cb->begin+=1;
	}
	else if(cb->full==0) *(cb->ptr+cb->end)=value;
	
	if(cb->end+1==cb->capacity) cb->end=0;
	else cb->end+=1;
	
	if(cb->end==cb->begin) cb->full=1;
	return 0;
}
int circular_buffer_pop_front(struct circular_buffer_t *a, int *err_code)
{
	if(a==NULL||a->begin>a->capacity||a->end>a->capacity||a->ptr==NULL||a->begin<0||a->end<0||a->capacity<=0)
	{
		if(err_code!=NULL) *err_code=1;
		return 20;
	}
	int g=circular_buffer_empty(a);
	if(g==-1)
	{
		if(err_code!=NULL) *err_code=1;
		return 20;
	}
	if(g==1)
	{
		if(err_code!=NULL) *err_code=2;
		return 20;
	} 
	int wielkosc=*(a->ptr+a->begin);
	if(a->begin+1==a->capacity) a->begin=0;
	else a->begin+=1;
	a->full=0;
	if(err_code!=NULL) *err_code=0;	
	return wielkosc;
}
int circular_buffer_pop_back(struct circular_buffer_t *a, int *err_code)
{
	if(a==NULL||a->begin>a->capacity||a->end>a->capacity||a->ptr==NULL||a->begin<0||a->end<0||a->capacity<=0)
	{
		if(err_code!=NULL) *err_code=1;
		return 20;
	}
	int g=circular_buffer_empty(a);
	if(g==-1)
	{
		if(err_code!=NULL) *err_code=1;
		return 20;
	}
	if(g==1)
	{
		if(err_code!=NULL) *err_code=2;
		return 20;
	} 
	int wielkosc;
	if(a->end==0)  wielkosc=*(a->ptr+a->capacity-1);
	else wielkosc=*(a->ptr+a->end-1);
	
	if(a->end==0) a->end=a->capacity-1;
	else a->end-=1;
	
	a->full=0;
	if(err_code!=NULL) *err_code=0;
	return wielkosc;	
}

int circular_buffer_empty(const struct circular_buffer_t *a)
{
	if(a==NULL||a->begin>a->capacity||a->end>a->capacity||a->ptr==NULL||a->begin<0||a->end<0||a->capacity<=0) return -1;
	if((a->begin==a->end) && a->full==0) return 1;
	return 0;
}
int circular_buffer_full(const struct circular_buffer_t *a)
{
	if(a==NULL||a->begin>a->capacity||a->end>a->capacity||a->ptr==NULL||a->begin<0||a->end<0||a->capacity<=0) return -1;
	if((a->begin==a->end) && a->full==1) return 1;
	return 0;
}

void circular_buffer_display(const struct circular_buffer_t *a)
{
	if(a==NULL||a->begin>a->capacity||a->end>a->capacity||a->ptr==NULL||a->begin<0||a->end<0||a->capacity<=0) return;
	int i;
	if((a->begin==a->end) && a->full==1)
	{
		for(i=a->begin;i<a->capacity;i++)
		{
			printf("%d ",*(a->ptr+i));
		}
		for(i=0;i<a->end;i++)
		{
			printf("%d ",*(a->ptr+i));
		}
	}
	else if(a->begin>a->end)
	{
		for(i=a->begin;i<a->capacity;i++) printf("%d ",*(a->ptr+i));
		for(i=0;i<a->end;i++) printf("%d ",*(a->ptr+i));
	}
	else for(i=a->begin;i<a->end;i++)
	{
		printf("%d ",*(a->ptr+i));
	}
}
