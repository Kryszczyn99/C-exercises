#include <stdio.h>

char* space_changer(char* text)
{
	if(text==NULL) return NULL;
  	int i;
	for(i=0;*(text+i)!='\0';i++)
	{
		if(*(text+i)==' ')	*(text+i)='_';
	}
	return text;
}

int main ()
{
	char tab[1001];
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab);
	space_changer(tab);
	char *wsk=tab;
	for(;*wsk!='\0';wsk++)
	{
		printf("%c",*wsk);
	}
	return 0;
}
