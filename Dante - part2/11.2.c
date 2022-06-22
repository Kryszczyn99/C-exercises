#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"


int main()
{
	struct stack_t *stos;
	int g=stack_init(&stos);
	if(g==2) return printf("Failed to allocate memory"),8;
	if(g==1) return printf("Incorrect input"),1;
	while(1)
	{
		printf("Podaj op: ");
		int op;
		int y=scanf("%d",&op);
		if(y!=1)
		{
			stack_destroy(&stos);
			return printf("Incorrect input"),1;
		}
		if(op==0) break;
		else if(op==1)
		{
			printf("Podaj value: ");
			int liczba;
			y=scanf("%d",&liczba);
			if(y!=1)
			{
				stack_destroy(&stos);
				return printf("Incorrect input"),1;
			}
			int g=stack_push(stos,liczba);
			if(g==2)
			{
				stack_destroy(&stos);
				return printf("Failed to allocate memory"),8;
			}
		}
		else if(op==2)
		{
			int err_code;
			int value=stack_pop(stos,&err_code);
			if(err_code==1) printf("Stack is empty\n");
			else printf("%d\n",value);
		}
		else if(op==3)
		{
			int val=stack_empty(stos);
			if(val==1) printf("1\n");
			else printf("0\n");
		}
		else if(op==4)
		{
			int val=stack_empty(stos);
			if(val==1) printf("Stack is empty\n");
			else
			{
				stack_display(stos);
				printf("\n");
			}
		}
		else printf("Incorrect input data\n");
	}
	stack_destroy(&stos);
	return 0;
}
