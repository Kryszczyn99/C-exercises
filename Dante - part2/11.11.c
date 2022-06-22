#include <stdio.h>
#include "doubly_linked_list.h"
#include <stdlib.h>


int main ()
{
	struct doubly_linked_list_t* tab1=dll_create();
	if(tab1==NULL) return printf("Failed to allocate memory"),8;
	struct doubly_linked_list_t* tab2=dll_create();
	if(tab2==NULL)
	{
		free(tab1);
		return printf("Failed to allocate memory"),8;	
	}
	printf("Podaj pierwszy ciag: ");
	int flaga_1=1;
	while(1)
	{
		int liczba;
		int y=scanf("%d",&liczba);
		if(y!=1)
		{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Incorrect input"),1;
		}
		if(liczba==-1) break;
		int g=dll_push_back(tab1,liczba);
		if(g==2)
		{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Failed to allocate memory"),8;		
		}
		flaga_1=0;
	}
	printf("Podaj pierwszy ciag: ");
	int flaga_2=1;
	while(1)
	{
		int liczba;
		int y=scanf("%d",&liczba);
		if(y!=1)
		{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Incorrect input"),1;
		}
		if(liczba==-1) break;
		int g=dll_push_back(tab2,liczba);
		if(g==2)
		{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Failed to allocate memory"),8;		
		}
		flaga_1=0;
	}
	if(flaga_1==1 && flaga_2==1)
	{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Not enough data available"),3;
	}
	printf("Wybierz op: ");
	int op;
	int y=scanf("%d",&op);
	if(y!=1)
	{
		dll_clear(tab1);
		dll_clear(tab2);
		free(tab1);
		free(tab2);
		return printf("Incorrect input"),1;		
	}
	if(op<0 || op>2)
	{
			dll_clear(tab1);
			dll_clear(tab2);
			free(tab1);
			free(tab2);
			return printf("Incorrect input data"),2;			
	}
	if(op==0) dll_concat_zip(tab1,tab2);
	else if(op==1) dll_concat_begin(tab1,tab2);
	else if(op==2) dll_concat_end(tab1,tab2);

		dll_display(tab1);
		dll_display_reverse(tab1);
		dll_clear(tab1);
		free(tab1);
		free(tab2);
	return 0;
}
