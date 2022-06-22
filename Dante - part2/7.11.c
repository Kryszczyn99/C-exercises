#include <stdio.h>
#include <stdlib.h>
#define NO_MEMORY 8

int main() 
{
	int i = 0;
	char *wsk=NULL;
	while(1)
	{
		
		if(i==0)
		{
			wsk = (char*)realloc(NULL,1);
			if(wsk==NULL) return printf("Failed to allocate memory"),NO_MEMORY;
			printf("Podaj tekst: ");
		}
		char *ptr=NULL;
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(wsk+i) = '\0';
			break;
		}
		ptr = realloc(wsk,i+2);
		if(ptr==NULL)
		{
			*(wsk+i) = '\0';
			break;
		}
		else
		{
			wsk=ptr;
		}
		*(wsk+i) = znak;
		i++;
	}
  	printf("%s", wsk);
	free(wsk);
	return 0;
}
