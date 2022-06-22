#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary1.h"
#define NO_MEMORY 8
#define CANNOT_OPEN_FILE 4
#define INCORRECT_INPUT 1

int main()
{
	char *wsk=(char *)calloc(1,50);
	if(wsk==NULL) return printf("Failed to allocate memory"),NO_MEMORY;
	int i=0;
	printf("Podaj tekst:  ");
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n' || i==50) break;
		*(wsk+i)=znak;
		i++;
	}
	FILE *f;
	f=fopen(wsk,"r");
	if(f==NULL)
	{
		free(wsk);
		return printf("Couldn't open file"),CANNOT_OPEN_FILE;
	} 
	int err_code;
	struct dictionary_t *slownik=create_dictionary(10,&err_code);
	if(err_code==1)
	{
		fclose(f);
		free(wsk);
		return printf("Incorrect input"),INCORRECT_INPUT;
	} 
	if(err_code==2)
	{
		fclose(f);
		free(wsk);
		return printf("Failed to allocate memory"),NO_MEMORY;
	}
	
	int flaga=0;
	int dzwignia=0;
	while(1)
	{
		int i=0;
		*wsk='\0';
		int p=0;
		while(1)
		{
			char znak;
			int y=fscanf(f,"%c",&znak);
			if(y!=1)
			{
				flaga=1;
				*(wsk+i)='\0';
				break;
			}
			if(!isalpha(znak))
			{
				*(wsk+i)='\0';
				break;
			}
			p=1;
			dzwignia=1;
			*(wsk+i)=znak;
			i++;
		}
		if(p==0);
		else
		{
			int g=dictionary_add_word(slownik,wsk);
			if(g==2)
			{
				fclose(f);
				destroy_dictionary(&slownik);
				free(wsk);
				return printf("Failed to allocate memory"),NO_MEMORY;
			} 
		}
		if(flaga==1) break;
	}
	if(dzwignia==0) printf("Nothing to show");
	dictionary_display(slownik);
	destroy_dictionary(&slownik);
	free(wsk);
	fclose(f);
	return 0;
}
