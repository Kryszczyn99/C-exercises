#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "circular_buffer.h"

int main ()
{
	printf("Podaj rozmiar bufora: ");
	int buffer_size;
	int y=scanf("%d",&buffer_size);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(buffer_size<=0) return printf("Incorrect input data\n"),2;
	struct circular_buffer_t *bufor;
	int u=circular_buffer_create_struct(&bufor, buffer_size);
	if(u==1) return printf("Incorrect input\n"),1;
	if(u==2) return printf("Failed to allocate memory\n"),8;
	
	while(1)
	{
		printf("Podaj operacje: ");
		int op;
		int z=scanf("%d",&op);
		if(z!=1)
		{
			circular_buffer_destroy_struct(&bufor);
			return printf("Incorrect input\n"),1;
		} 
		if(op>6 || op<0) printf("Incorrect input data\n");
		else if(op==0) break;
		else if(op==1)
		{
			printf("Podaj wartosc do dodania: ");
			int value;
			int x=scanf("%d",&value);
			if(x!=1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			int g=circular_buffer_push_back(bufor,value);
			if(g==1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
		}
		else if(op==2)
		{
			int g=circular_buffer_empty(bufor);
			if(g==-1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			if(g==0)
			{
				int err_code=0;
				int g=circular_buffer_pop_back(bufor,&err_code);
				if(err_code==0) printf("%d\n",g);
				else
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			}
			if(g==1) printf("Buffer is empty\n");				
		}
		else if(op==3)
		{
			int g=circular_buffer_empty(bufor);
			if(g==-1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			if(g==0)
			{
				int err_code=0;
				int g=circular_buffer_pop_front(bufor,&err_code);
				if(err_code==0) printf("%d\n",g);
				else
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			}
			if(g==1) printf("Buffer is empty\n");	
		}
		else if(op==4)
		{
			int g=circular_buffer_empty(bufor);
			if(g==-1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			if(g==0)
			{
				circular_buffer_display(bufor);
				printf("\n");
			}
			if(g==1) printf("Buffer is empty\n");				
		}
		else if(op==5)
		{
			int g=circular_buffer_empty(bufor);
			if(g==-1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			if(g==0) printf("0\n");
			if(g==1)
			{
				printf("1\n");	
				bufor->begin=0;
				bufor->end=0;
			} 		
		}
		else if(op==6)
		{
			int g=circular_buffer_full(bufor);
			if(g==-1)
			{
				circular_buffer_destroy_struct(&bufor);
				return printf("Incorrect input\n"),1;
			} 
			if(g==0) printf("0\n");
			if(g==1) printf("1\n");
		}
	}
	circular_buffer_destroy_struct(&bufor);
	return 0;
}
