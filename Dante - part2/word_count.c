#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define integer 4
#include "word_count.h"
int my_strlen(char * tab)
{
	int len=0;
	while(*(tab+len)!='\0') len++;
	return len;
}
int* count_words(const char *filename, int *err_code, int N, ...)
{
	if(!(filename==NULL || N<=0))
	{
		int* pointer = (int*)malloc(N*integer);
		if(pointer==NULL)
		{
			if(err_code!=NULL) *err_code=3;
			return NULL;
		}
		FILE *f = fopen(filename, "r");
		if(f==NULL)
		{
			free(pointer);
			if(err_code!=NULL) *err_code=2;
			return NULL;
		}
		if(err_code!=NULL) *err_code = 0;
		va_list ap;
		va_start(ap,N);
		
		int i=0;
		while(1)
		{
			char litera;
			char *zmienna;
			zmienna=va_arg(ap, char*);
			fseek(f,0,0);
			int ilosc=0,liczba=0;
			if(i==N)
			{
				va_end(ap);
				fclose(f);
				break;
			}
			while(1)
			{
				char znak;
				int y=fscanf(f,"%c",&znak);
				if(y!=1) break;
				int flaga = 0;
				char check=*zmienna;
				int bb=0;
				if((litera>='a' && litera<='z') || (litera>='A' && litera<='Z')) bb=1;
				if(znak==check)
				{
					if(bb==1);
					else
					{
						int i=1;
						int size=my_strlen(zmienna);
						while(1)
						{
							if(i==size) break;
						    fscanf(f,"%c",&znak);
					    	char zobacz=*(zmienna+i);
					    	if(znak==zobacz);
					    	else
							{
					            flaga = 1;
					            break;
					    	}				
							i+=1;
						}
				    	int hh=0;
				    	if(flaga==0)	fscanf(f,"%c",&znak);
				    	if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) hh=1;
				        if(flaga==0 && hh==0)	ilosc++;
					}

				}
				litera=znak;
			}
			liczba+=ilosc;
			*(pointer+i)=liczba;	
			i+=1;	
		}
		return pointer;
	}
	if(err_code!=NULL) *err_code=1;
	return NULL;	
}


