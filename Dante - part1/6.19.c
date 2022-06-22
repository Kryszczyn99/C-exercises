#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define XX 1001
#define G 0

int main (void)
{
	char tablica[XX];
	printf("Podaj tekst: \n");
	fgets(tablica, XX,stdin);
	int len=strlen(tablica);
	int YY,k=G,q=G,p=G;
	for(YY=G;YY<len-1;YY=YY+1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='A' || tablica[YY]=='a')
		{
			k+=1;
			p=k;
		}
		else continue;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	k=G;
	q=G;
	for(YY=G;YY<len-1;YY=YY+1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='E' || tablica[YY]=='e')
		{
			k+=1;
			p=k;
		}
		else continue;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	k=G;
	q=G;
	YY=G;
	while(YY<len-1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='I' || tablica[YY]=='i')
		{
			k+=1;
			p=k;
		}
		else continue;
		
		YY=YY+1;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	k=G;
	q=G;
	for(YY=G;YY<len-1;YY=YY+1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='O' || tablica[YY]=='o')
		{
			k+=1;
			p=k;
		}
		else continue;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	k=G;
	q=G;
	for(YY=G;YY<len-1;YY=YY+1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='U' || tablica[YY]=='u')
		{
			k+=1;
			p=k;
		}
		else continue;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	k=G;
	q=G;
	for(YY=G;YY<len-1;YY=YY+1)
	{	
		if(tablica[YY]=='\n' || tablica[YY]=='\t' || tablica[YY]==' ')
		{
			if(p>G)
			{
				q+=1;
				p=G;
			}
		}
		else if(tablica[YY]=='Y' || tablica[YY]=='y')
		{
			k+=1;
			p=k;
		}
		else continue;
	}
	if(k>G && q>G)printf("%d-%d\n",k,q);
	
	return G;
}
