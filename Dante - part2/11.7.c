#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	struct linked_list_t* p=ll_create();
	if(p==NULL) return printf("Failed to allocate memory"),8;
	while(1)
	{
		printf("Co chcesz zrobic: ");
		int op;
		int y=scanf("%d",&op);
		if(y!=1)
		{
			ll_clear(p);
			free(p);
			return printf("Incorrect input"),1;
		}
		if(op==0)//zakonczenie programu
		{
			break;
		}
		else if(op==1)//dodanie elementu na koniec listy
		{
			int liczba;
			printf("Podaj liczbe: ");
			y=scanf("%d",&liczba);
			if(y!=1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			int g=ll_push_back(p,liczba);
			if(g==1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else if(g==2)
			{
				ll_clear(p);
				free(p);
				return printf("Failed to allocate memory"),8;					
			}
		}
		else if(op==2)//usuniecie ostatniego elementu z listy
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				int err_code=0;
				int wynik=ll_pop_back(p,&err_code);
				if(err_code==1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;					
				}
				printf("%d\n",wynik);
			}
		}
		else if(op==3)//dodanie elementu na poczatek listy
		{
			int liczba;
			printf("Podaj liczbe: ");
			y=scanf("%d",&liczba);
			if(y!=1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			int g=ll_push_front(p,liczba);
			if(g==1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else if(g==2)
			{
				ll_clear(p);
				free(p);
				return printf("Failed to allocate memory"),8;					
			}
		}
		else if(op==4)//usuniecie pierwszego elementu
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				int err_code=0;
				int wynik=ll_pop_front(p,&err_code);
				if(err_code==1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;					
				}
				printf("%d\n",wynik);
			}
		}
		else if(op==5)
		{
			printf("Podaj liczbe: ");
			int liczba;
			int y=scanf("%d",&liczba);
			if(y!=1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;					
			}
			printf("Podaj indeks: ");
			unsigned int index;
			y=scanf("%u",&index);
			if(y!=1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			int code=ll_insert(p,index,liczba);
			if(code==1) printf("Index out of range\n");
			else if(code==2)
			{
				ll_clear(p);
				free(p);
				return printf("Failed to allocate memory"),8;					
			}
			
		}
		else if(op==6)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				printf("Podaj indeks: ");
				unsigned int index;
				y=scanf("%u",&index);
				if(y!=1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;				
				}
				int err_code=0;
				int code=ll_remove(p,index,&err_code);
				if(err_code==1) printf("Index out of range\n");
				else
				{
					printf("%d\n",code);
				}
			}
		}
		else if(op==7)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				int err_code;
				int gh=ll_back(p,&err_code);
				if(err_code==1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;		
				}
				printf("%d\n",gh);
			}
		}
		else if(op==8)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				int err_code;
				int gh=ll_front(p,&err_code);
				if(err_code==1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;		
				}
				printf("%d\n",gh);
			}
		}
		else if(op==9)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("1\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}		
			else printf("0\n");
		}
		else if(op==10)
		{
			int size=ll_size(p);
			if(size==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else printf("%d\n",size);
		}
		else if(op==11)
		{
			ll_clear(p);
		}
		else if(op==12)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				unsigned int index;
				printf("Podaj indeks: ");
				int y=scanf("%u",&index);
				if(y!=1)
				{
					ll_clear(p);
					free(p);
					return printf("Incorrect input"),1;					
				}
				int err_code=0;
				int liczba=ll_at(p,index,&err_code);
				if(err_code==1)
				{
					printf("Index out of range\n");
				}
				else
				{
					printf("%d\n",liczba);
				}
			}
		}
		else if(op==13)
		{
			int w=ll_is_empty(p);
			if(w==1) printf("List is empty\n");
			else if(w==-1)
			{
				ll_clear(p);
				free(p);
				return printf("Incorrect input"),1;				
			}
			else
			{
				ll_display(p);
			}
		}
		else printf("Incorrect input data\n");
	}
	ll_clear(p);
	free(p);
	return 0;
}
