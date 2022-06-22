#include <stdio.h>

char* reverse(char* text)
{
  if(text==NULL) return NULL;
  int i,j;
  char *znak=text;
  char temp;
  int wielkosc=0;
  char *size=text;
  for(;*size!='\0';size++) wielkosc+=1;
  char *backup;
  backup=text;
  for(j=0;j<wielkosc;j++)
  {
    for(i=0;i<wielkosc-1-j;i++)
    {
      temp=*(text+1);
      *(text+1)=*text;
      *text=temp;
      text++;
    }
    text=backup;
  }
  return znak;
}
char* remove_non_letters(char* text)
{
    if(text==NULL) return NULL;
    char *znak=text;
    for(;*text!='\0';text++)
    {
        if((*text>='A' && *text<='Z' )|| (*text>='a' && *text<='z'));
        else    *text=' ';
    }
    return znak;
}

char* trim(char* text)
{
  	if(text==NULL) return NULL;
  	char *znak=text;
	while(*znak==' ')
  	{
	  	text=znak;
	  	for(;*(text+1)!='\0';text++) *text=*(text+1);
	  	*text='\0';
  	}
	char *po_tablicy=znak;
	for(;*(po_tablicy+1)!='\0';po_tablicy++)
	{
		char *backup=po_tablicy;
		while(*backup==' ' && *(backup+1)==' ')
		{
			text=backup;
			for(;*(text+1)!='\0';text++) *text=*(text+1);
	  		*text='\0';
		}
	}
	text=znak;
	for(;*text!='\0';text++)
	{
		if(*text==' ')
		{
			char *backup=text;
			int p=0;
			for(;*backup!='\0';backup++)
			{
				if(*backup!=' ')
				{
					p=1;
					break;
				}
			}
			if(p==0)
			{
				*text='\0';
				break;
			}
		}
	}
  	return znak;
}
int main ()
{
    char tab[1001];
    char *wsk;
    wsk=tab;
    printf("Podaj tekst: ");
    scanf("%1000[^\n]s",tab);
    int litery=0;
    for(;*wsk!='\0';wsk++)
    {
    	if((*wsk>='a' && *wsk<='z') || (*wsk>='A' && *wsk<='Z'))
    	{
    		litery=1;
    		break;
		}
	}
	if(litery==0)
	{
		char tab4[]="Nothing to show";
		reverse(tab4);
		remove_non_letters(tab4);
		char *wskaznik;
		wskaznik=trim(tab4);
		for(;*wskaznik!='\0';wskaznik++) printf("%c",*wskaznik);
	}
	
    char *pointer;
    pointer=reverse(tab);
    if(pointer==NULL) return printf("Incorrect input\n"),1;
    
    
    pointer=remove_non_letters(tab);
    if(pointer==NULL) return printf("Incorrect input\n"),1;
    
    
    pointer=trim(tab);
    wsk=tab;
    if(pointer==NULL) return printf("Incorrect input\n"),1;
    for(;*wsk!='\0';wsk++) printf("%c",*wsk);
    return 0;
}
