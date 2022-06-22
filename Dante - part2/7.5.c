#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "big_numbers.h"


int main()
{
	struct big_numbers_t* tab;
	char *wsk;
	int y=create_big_numbers(&tab,10);
	if(y==1) return printf("Failed to allocate memory"),8;
	if(y==2) return printf("Failed to allocate memory"),8;
	int p=sizeof(char);
	wsk=(char*)calloc(201,p);
	if(wsk==NULL)
	{
		destroy_big_numbers(&tab);
		return printf("Failed to allocate memory"),8;
	}
	printf("Podaj wartosci: ");
	int full=0;
	int alokacja=0;
	char znak;
	while(1)
	{
		int s=tab->size;
		int c=tab->capacity;
		if(s==c)
		{
			full=1;
			break;
		}
		znak=getchar();
		char znak_copy=znak;
		ungetc(znak,stdin);
		if(znak_copy=='\n') break;
		scanf("%200s",wsk);
		char znaczek=getchar();
		if(znaczek!='\n') while(znaczek!='\n') znaczek=getchar();
		int i=0;
		if(*(wsk+i)=='-') i++;
		int flaga=0;
		while(1)
		{
			char znaczek=*(wsk+i);
			if(znaczek=='\0') break;
			if(isdigit(znaczek)==0)
			{
				printf("Incorrect input\n");
				flaga=1;
				break;
			}
			i++;
		}
		if(flaga==1) continue;
		y=add_big_number(tab,wsk);
		if(y==1 || y==2)
		{
			alokacja=1;
			break;
		}
		
	}
	if(full==1) printf("Buffer is full\n");
	else if(alokacja==1) printf("Failed to allocate memory\n");
	int s=tab->size;
	if(s!=0) display(tab);
	else printf("Buffer is empty\n");
	destroy_big_numbers(&tab);
	free(wsk);
	return 0;
}

