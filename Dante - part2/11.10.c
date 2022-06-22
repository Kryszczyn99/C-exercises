#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list1.h"



int main ()
{
	struct doubly_linked_list_t* wsk=dll_create();
	if(wsk==NULL) return printf("Failed to allocate memory"),8;
	
	while(1)
	{
		int op;
		printf("Co chcesz zrobic: ");
		int y=scanf("%d",&op);
		if(y!=1)
		{
			dll_clear(wsk);
			free(wsk);
			return printf("Incorrect input"),1;
		}
		if(op>=15 || op<0) printf("Incorrect input data\n");
		if(op==0) break;
		else if(op==1)
		{
			printf("Podaj liczbe: ");
			int wartosc;
			y=scanf("%d",&wartosc);
			if(y!=1)
			{
				dll_clear(wsk);
				free(wsk);
				return printf("Incorrect input"),1;			
			}	
			int res=dll_push_back(wsk,wartosc);
			if(res==2)
			{
				dll_clear(wsk);
				free(wsk);
				return printf("Failed to allocate memory"),8;
			}			
		}
		else if(op==2)
		{
			int err_code;
			int value=dll_pop_back(wsk,&err_code);
			if(err_code!=0) printf("List is empty\n");
			else printf("%d\n",value);			
		}
		else if(op==3)
		{
			printf("Podaj liczbe: ");
			int wartosc;
			y=scanf("%d",&wartosc);
			if(y!=1)
			{
				dll_clear(wsk);
				free(wsk);
				return printf("Incorrect input"),1;			
			}	
			int res=dll_push_front(wsk,wartosc);
			if(res==2)
			{
				dll_clear(wsk);
				free(wsk);
				return printf("Failed to allocate memory"),8;
			}
		}
		else if(op==4)
		{
			int err_code;
			int value=dll_pop_front(wsk,&err_code);
			if(err_code!=0) printf("List is empty\n");
			else printf("%d\n",value);
		}
		else if(op==5)
		{
				printf("Podaj liczbe: ");
				int liczba;
				y=scanf("%d",&liczba);
				if(y!=1)
				{
					dll_clear(wsk);
					free(wsk);
					return printf("Incorrect input"),1;			
				}
				printf("Podaj element: ");
				unsigned int index;
				y=scanf("%u",&index);
				if(y!=1)
				{
					dll_clear(wsk);
					free(wsk);
					return printf("Incorrect input"),1;			
				}
				int wielkosc=dll_size(wsk);
				unsigned int wielk=(unsigned int) wielkosc;
				if(wielk<index) printf("Index out of range\n");
				else
				{
					int value=dll_insert(wsk,index,liczba);
					if(value==2)
					{
						dll_clear(wsk);
						free(wsk);
						return printf("Failed to allocate memory"),8;
					}
				}
				
		}
		else if(op==6)
		{
			int g=dll_is_empty(wsk);
			if(g==0)
			{
				printf("Podaj indeks: ");
				unsigned int index;
				y=scanf("%u",&index);
				if(y!=1)
				{
					dll_clear(wsk);
					free(wsk);
					return printf("Incorrect input"),1;			
				}
				int err_code;
				int value=dll_remove(wsk,index,&err_code);
				if(err_code!=0) printf("Index out of range\n");
				else printf("%d\n",value);
			}
			else if(g==1) printf("List is empty\n");					
		}
		else if(op==7)
		{
			int err_code=0;
			int p=dll_back(wsk,&err_code);
			if(err_code==0) printf("%d\n",p);
			if(err_code!=0) printf("List is empty\n");			
		}
		else if(op==8)
		{
			int err_code=0;
			int p=dll_front(wsk,&err_code);
			if(err_code==0) printf("%d\n",p);
			if(err_code!=0) printf("List is empty\n");			
		}
		else if(op==9)
		{
			int g=dll_is_empty(wsk);
			if(g==0) printf("0\n");
			else if(g==1) printf("1\n");
		}
		else if(op==10)
		{
			int rozmiar=dll_size(wsk);
			printf("%d\n",rozmiar);
		}
		else if(op==11)
		{
			dll_clear(wsk);
		}
		else if(op==12)
		{
			int g=dll_is_empty(wsk);
			if(g==0)
			{
				printf("Podaj indeks: ");
				unsigned int index;
				y=scanf("%u",&index);
				if(y!=1)
				{
					dll_clear(wsk);
					free(wsk);
					return printf("Incorrect input"),1;			
				}
				int err_code;
				int value=dll_at(wsk,index,&err_code);
				if(err_code!=0) printf("Index out of range\n");
				else printf("%d\n",value);
			}
			else if(g==1) printf("List is empty\n");			
		}
		else if(op==13)
		{
			int g=dll_is_empty(wsk);
			if(g==0) dll_display(wsk);
			if(g==1) printf("List is empty\n");
		}
		else if(op==14)
		{
			int g=dll_is_empty(wsk);
			if(g==0) dll_display_reverse(wsk);
			if(g==1) printf("List is empty\n");
			
		}
	}
	
	dll_clear(wsk);
	free(wsk);
	return 0;	
}
