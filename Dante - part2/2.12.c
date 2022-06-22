#include <stdio.h>

int message_compression(char* txt)
{
	if(txt==NULL) return -1;
	int k=0;
	int ilosc=0;
	while(*txt!='\0')
	{
		if((*txt>='a' && *txt<='z') || (*txt>='A' && *txt<='Z'))
		{
			if(*txt>='a' && *txt<='z' && k==0)
			{
				k=1;
				*txt-='a'-'A';
			}
			else if(*txt>='A' && *txt<='Z' && k==1)
			{
				*txt+='a'-'A';
			}
			else if(*txt>='A' && *txt<='Z' && k==0) k=1;
			
			txt++;
		}
		else if(!((*txt>='a' && *txt<='z') || (*txt>='A' && *txt<='Z')))
		{
			k=0;
			ilosc++;
			char *backup=txt;
			for(;*(backup+1)!='\0';backup++)
			{
				*backup=*(backup+1);
			}
			*backup='\0';
		}
	}
	
	return ilosc;
}

int main ()
{
	char tab[1001];
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab);
	char *wsk=tab;
	int liczba=0;
	int zmienna=0;
	for(;*wsk!='\0';wsk++)
	{
		if(!((*wsk>='a' && *wsk<='z') || (*wsk>='A' && *wsk<='Z'))) liczba+=1;
		else zmienna=1;
	}
	int g=message_compression(tab);
	if(zmienna!=1) return printf("NothingToShow\n"),0;
	if(g==-1) return printf("Incorrect input\n"),1;
	wsk=tab;
	for(;*wsk!='\0';wsk++) printf("%c",*wsk);
	
	return 0;
}
