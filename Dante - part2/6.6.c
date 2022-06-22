#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "array.h"



int main ()
{
	printf("Podaj rozmiar: ");
	int size;
	int y=scanf("%d",&size);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(size<=0) return printf("Incorrect input data\n"),2;
	struct array_t struktura;
	int g=array_create(&struktura,size);
	if(g==1) return printf("Incorrect input\n"),1;
	if(g==2) return printf("Failed to allocate memory"),8;
	int k=0;
	int p=0;
	printf("Podaje dane do tablicy: \n");
	while(1)
	{
		int liczba;
		int z=scanf("%d",&liczba);
		if(z!=1)
		{
			array_destroy(&struktura);
			return printf("Incorrect input\n"),1;
		} 
		if(liczba==0) break;
		int h=array_push_back(&struktura,liczba);
		if(h==1)
		{
			array_destroy(&struktura);
			return printf("Incorrect input\n"),1;
		}
		if(h==2) p=1;
		k+=1;
	}
	if(p==1) printf("Buffer is full\n");
	if(k!=0) array_display(&struktura);
	else if(p!=1 && k==0) printf("Buffer is empty\n");
	array_destroy(&struktura);
	return 0;
}
