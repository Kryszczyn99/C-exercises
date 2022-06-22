#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stack.h"


int main ()
{
	struct stack_t *stos;
	int g=stack_init(&stos);
	if(g==1) return printf("Incorrect input"),1;
	if(g==2) return printf("Failed to allocate memory"),8;
	uint64_t liczba;
	printf("Podaj tekst: ");
	int y=scanf("%lu",&liczba);
	if(y!=1)
	{
		stack_destroy(&stos);
		return printf("Incorrect input"),1;
	}
	if(liczba==0)
	{
		int g=stack_push(stos,0);
		if(g==2)
		{
			stack_destroy(&stos);
			return printf("Failed to allocate memory"),8;
		}
		stack_display(stos);
		stack_destroy(&stos);
		return 0;
	}
	uint64_t backup=liczba;
	int len=0;
	while(backup)
	{
		backup/=2;
		len++;
	}
	int i=0;
	for(;i<len;i++)
	{
		int value=liczba%2;
		liczba/=2;
		int g=stack_push(stos,value);
		if(g==2)
		{
			stack_destroy(&stos);
			return printf("Failed to allocate memory"),8;
		}
	}
	stack_display(stos);
	stack_destroy(&stos);
	return 0;
}
