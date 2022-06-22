#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "file_stats.h"

void action(int i,struct file_stats_t *d)
{
	(d+i)->size=0;
	(d+i)->state=NON_EXIST;
}

void zapisz(int i,struct file_stats_t *d,FILE *f)
{
	fseek(f,0,SEEK_END);
	int size=ftell(f);
	fclose(f);
	(d+i)->size=size;
	(d+i)->state=EXIST;
	
}

struct file_stats_t *check_files(int N, ...)
{
	if(N<=0) return NULL;
	int size=sizeof(struct file_stats_t);
	va_list start;
	struct file_stats_t *wsk=(struct file_stats_t *)calloc(N,size);
	if(wsk==NULL) return NULL;
	int i=0;
	va_start(start,N);
	while(1)
	{
		if(i==N) break;
		char* txt = va_arg(start, char*);
		(wsk+i)->filename=txt;
		FILE *f=fopen(txt,"rb");
		if(f==NULL) action(i,wsk);
		else zapisz(i,wsk,f);
		
	}
	va_end(start);
	return wsk;
}

int main() 
{

	return 0;
}
