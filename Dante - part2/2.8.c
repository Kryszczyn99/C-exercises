#include <stdio.h>

//Jesli bedzie zle to znaczy, ze
//Nie rozumiem do konca Pana uwagi, jesli jest to mozliwe prosze to bardziej opisac
//lub przykladowe wejscie oraz wyjscie podac bym mogl zrozumiec

char* trim(char* text);

char* change_letter_size(char* dest, const char* src)
{
    if(dest==NULL || src==NULL) return NULL;
  	char *znak2;
  	znak2=dest;
    for(;*src!='\0';src++)
  	{
	    if(*src>='a' && *src<='z')
	    {
	        char znak;
	                znak=*src;
	                znak-='a'-'A';
	                *dest=znak;
	                dest++;
	    }
	    else if(*src>='A' && *src<='Z')
	    {
	        char znak;
	                znak=*src;
	                znak+='a'-'A';
	                *dest=znak;
	                dest++;
	    }
	    else
	    {
	        *dest=*src;
	        dest++;
	    }
 	 }
 	*dest='\0';
    return znak2;
}

int main ()
{
    char tab[1001];
    char tab1[1001];
    printf("Podaj tekst: ");
    scanf("%1000[^\n]s",tab);
    char *pointer;
    pointer=change_letter_size(tab1,tab);
    if(pointer==NULL) return printf("Incorrect input\n"),1;
    trim(tab1);
    for(;*pointer!='\0';pointer++) printf("%c",*pointer);
    return 0;
}


char* trim(char* text)
{
    if(text==NULL) return NULL;
    char *znak=text;
    while(*znak==' ' || *znak=='\t' || *znak=='\n')
    {
        text=znak;
        for(;*(text+1)!='\0';text++) *text=*(text+1);
        *text='\0';
    }
    text=znak;
    for(;*text!='\0';text++)
    {
        if(*text==' ' || *text=='\t' || *text=='\n')
        {
            char *backup=text;
            int p=0;
            for(;*backup!='\0';backup++)
            {
                if(*backup!=' ' || *backup!='\n' || *backup!='\t')
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
