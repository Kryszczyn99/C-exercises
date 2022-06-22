#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 1000
#define K 50
#define G 0

int main (void)
{
	char tablica[N];
	printf("Podaj do 50 nawiasow: \n");
	fgets(tablica, N,stdin);
	if(strlen(tablica)>K+1)
	{
		printf("Input is too long\n");
		return 1;
	}
	int i=G;
	int k=G;
	while(i<K)
	{
		if(k<G)
		{
			printf("Niepoprawny\n");
			return G;
		}
		if(tablica[i]=='(')
		{
			k=k+1;
		}else if(tablica[i]==')')
		{
			k=k-1;
		}
		i=i+1;
	}
	if(k!=G)
	{
		printf("Niepoprawny\n");
		return G;
	}
	printf("Poprawny\n");
	
	
	return G;
}
