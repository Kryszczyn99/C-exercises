#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
	char tablica[1000];
	printf("Podaj do 50 nawiasow: \n");
	fgets(tablica, 1000,stdin);
	if(strlen(tablica)>51)
	{
		printf("Input is too long\n");
		return 1;
	}
	int i;
	int k=0,max=0;
	for(i=0;i<100;i++)
	{
		if(tablica[i]=='(')
		{
			k+=1;
			if(max<k)
			{
				max=k;
			}
		}else if(tablica[i]==')' && k>0)
		{
			k-=1;
		}
	}
	printf("%d ",max);
	k=0;
	for(i=0;i<50;i++)
	{
		if(tablica[i]=='(')
		{
			k+=1;
			if(k==max)
			{
				printf("%d ",i);
			}
		}else if(tablica[i]==')' && k>0)
		{
			k-=1;
		} 
	}
	
	
	return 0;
}
