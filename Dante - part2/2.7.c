#include <stdio.h>

char* reverse(char* text);
char* trim(char* text);
char* remove_non_letters(char* text);

char* swap_order_words(char* txt)
{
    if(txt==NULL) return NULL;
    char *znak=txt;
    reverse(txt);
    remove_non_letters(txt);
    trim(txt);
    
    int k=0;
    char *poczatek=txt;
    char *backup_poczatek;
    char *backup_koniec;
    
    for(;*txt!='\0';txt++)
    {
        
        if(*txt==' ' && k==0);
        else if(*txt!=' ')
        {
            if(k==0)
            {
                poczatek=txt;
            }  
            k=1;
        }
        else
        {
            k=0;
            char *koniec=txt;
            int len=0;
            backup_poczatek=poczatek;
            backup_koniec=koniec;
            for(; backup_poczatek < backup_koniec ; backup_poczatek++ , len++);      
            char temp;
            int i,j;
            char *backup;
            backup=poczatek;
            for(j=0;j<len;j++)
            {
                for(i=0;i<len-1-j;i++)
                {
                  temp=*(backup+1);
                  *(backup+1)=*backup;
                  *backup=temp;
                  backup++;
                }
            backup=poczatek;
            }
        }
    }
    int len=0;
	int o=0;
    txt=znak;
	for(;*txt!='\0';txt++)
	{
		if(o==0)
		{
			char *backup3=txt;
			for(;*backup3!='\0';backup3++)
			{
				if(*backup3==' ') break;
			}
			if(*backup3=='\0') o=1;
		}
		if(o==1)
		{
			len++;
		}
	}
    int i,j;
    char temp;
    char *backup=poczatek;
    for(j=0;j<len;j++)
    {
        for(i=0;i<len-1-j;i++)
        {
            temp=*(backup+1);
            *(backup+1)=*backup;
            *backup=temp;
            backup++;
        }
    backup=poczatek;
    }  


    
    return znak;
}

int main ()
{
    char tab[1001];
    printf("Podaj tekst: ");
    scanf("%1000[^\n]s",tab);
    char *wsk=tab;
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
        char *wskaznik;
        wskaznik=swap_order_words(tab4);
        for(;*wskaznik!='\0';wskaznik++) printf("%c",*wskaznik);
    }
    char *pointer=swap_order_words(tab);
    for(;*pointer!='\0';pointer++) printf("%c",*pointer);
    
    return 0;
}


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

