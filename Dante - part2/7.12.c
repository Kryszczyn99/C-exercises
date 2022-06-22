#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "zadanko.h"


int main()
{
    char *wsk=(char *)calloc(1000,1);
    if(wsk==NULL) return printf("Failed to allocate memory"),8;
    printf("Podaj tekst: ");
    int i=0;
    int flaga=0;
    while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n' || i==999)
		{
			*(wsk+i)='\0';
			break;
		}
		if(isalpha(znak)) flaga=1;
		*(wsk+i)=znak;
		i++;
	}
	if(flaga==0) printf("Nothing to show");
	else
	{
		char **ptr=split_words(wsk);
		if(ptr==NULL)
		{
			free(wsk);
			return printf("Failed to allocate memory"),8;
		}
		int g=sort_words(ptr);
		if(g==1)
		{
			free(wsk);
			destroy(ptr);
			return printf("Incorrect input\n"),1;	
		} 
		i=0;
		while(*(ptr+i))
		{
			printf("%s\n",*(ptr+i));
			i++;
		}
		destroy(ptr);
	}
	free(wsk);
    return 0;
}
