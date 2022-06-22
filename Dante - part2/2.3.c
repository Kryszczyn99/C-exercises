#include <stdio.h>
#include <string.h>
#include <ctype.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace)
{
    if(text==NULL || uppercase==NULL || lowercase==NULL || whitespace==NULL) return 1;
    int i;
    *uppercase=0;
    *lowercase=0;
    *whitespace=0;
    for(i=0;*text!='\0';i++,text++)
    {
        if(isupper(*text)!=0) *uppercase+=1;
        else if(islower(*text)!=0) *lowercase+=1;
        else if(*text=='\n' || *text=='\t' || *text==' ') *whitespace+=1;
    }
    return 0;
}

int main ()
{
    char tab[1000];
    printf("Podaj tekst: ");
    scanf("%1000[^\n]s",tab);
    int duze=0,male=0,spacje=0;
    int *uppercase,*lowercase,*whitespace;
    uppercase=&duze;
    lowercase=&male;
    whitespace=&spacje;
    int p=marks_counter(tab,uppercase,lowercase,whitespace);
    if(p==1) return printf("Incorrect input\n"),1;
    printf("%d\n%d\n%d\n",duze,male,spacje);
    return 0;
}

