#include <stdio.h>
#include <ctype.h>

char* get_word(char* str)
{
    if(str==NULL) return NULL;
    char *p=str;
    int k=0,ctrl=1;
    while(*str)
        {
        if(isalpha(*str) && ctrl==1) k=1;
        else if(!isalpha(*str) && ctrl==1) 
		{
			ctrl=0;
			for(;!isalpha(*str);str++) *str=' ';
			*(str-1)='\n';
		}
		else if(isalpha(*str) && ctrl==0) ctrl=1;
        str++;
    }
    return NULL;
}

int main()
{
    char tekst[1001];
    char *str=tekst;
    printf("Podaj tekst: ");
    scanf("%1000[^\n]s",tekst);
    printf("%s",get_word(str));
    //if(get_word(str)==NULL) printf("Nothing\nto\nshow");
    return 0;
}

