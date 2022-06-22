#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"

int main ()
{
	struct stack_t *wsk;
	//char *ptr=(char *)malloc(1);
	int g=stack_init(&wsk, 10);
	if(g==1)
	{
	//	free(ptr);
		return printf("Incorrect input"),1;
	} 
	if(g==2)
	{
	//	free(ptr);
		return printf("Failed to allocate memory"),8;
	} 
//	free(ptr);
	
	while(1)
	{
		int op;
		printf("Podaj operator: ");
		int y=scanf("%d",&op);
		if(y!=1)
		{
			stack_free(wsk);
			return printf("Incorrect input"),1;
		}
		if(op==0)
		{
			break;
		}
		else if(op==1)
		{
			printf("Podaj liczbe: ");
			int liczba;
			y=scanf("%d",&liczba);
			if(y!=1)
			{
				stack_free(wsk);
				return printf("Incorrect input"),1;			
			}
			g=stack_push(wsk,liczba);
			if(g==1)
			{
				stack_free(wsk);
				return printf("Incorrect input"),1;		
			}
			else if(g==2)
			{
				stack_free(wsk);
				return printf("Failed to allocate memory"),8;					
			}
		}
		else if(op==2)
		{
			if(wsk->head==0) printf("Stack is empty\n");
			else
			{
				int err_code;
				g=stack_pop(wsk,&err_code);
				if(err_code==1)
				{
					stack_free(wsk);
					return printf("Incorrect input"),1;
				}
				else printf("%d\n",g);
			}			
		}
		else if(op==3)
		{
			if(wsk->head==0) printf("Stack is empty\n");
			else
			{
				stack_display(wsk);
			}
		}
		else printf("Incorrect input data\n");
	}
	stack_free(wsk);
	return 0;
}
