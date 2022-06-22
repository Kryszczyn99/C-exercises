#include <stdio.h>
#include <string.h>
#include <ctype.h>

int distance(const char tab[])
{
	
}

int main ()
{
	char tab1[1000];
	printf("Podaj tekst: ");
	int i,j;
	for(i=0;i<10;i++)
	{
		scanf("%1000[^\n]",&tab1);
        while(getchar()!='\n');	
        int len = strlen(tab1);
		for(j=0;j<len;j++)
		{
			if(isdigit(tab1[j]))
			{
				printf("Incorrect input data\n");
				return 2;	
			}
			if(tab1[j]>='a' && tab1[j]<='z')			
			{
				printf("Incorrect input data\n");
				return 2;	
			}
		}
		fflush(stdin);
	}
	
	return 0;
}
