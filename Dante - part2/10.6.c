#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "file_stats.h"

void action(int i,struct file_stats_t *d)
{
    (d+i)->size=0;
    (d+i)->state=NON_EXIST;
}

void zapisz(int i,struct file_stats_t *d,FILE *f)
{
    int size=0;
    char znak;
    while(1)
    {
        int y=fscanf(f,"%c",&znak);
        if(y!=1) break;
        size++;
    }
    fclose(f);
    (d+i)->size=size;
    (d+i)->state=EXIST;
    
}

struct file_stats_t *check_files(int N,...)
{
    va_list start;
    va_start(start,N);
    if(N<=0)
    {
        va_end(start);
        return NULL;
    }
    int size=sizeof(struct file_stats_t);
    int i=0;
    FILE *f;
    char *txt;
    struct file_stats_t *wsk=(struct file_stats_t *)calloc(N,size);
    if(wsk==NULL)
    {
        va_end(start);
        return NULL;
    }
    
    while(1)
    {
        if(i==N)
        {
            va_end(start);
            break;  
        }
        txt = va_arg(start, char*);
        (wsk+i)->filename=txt;
        f=fopen(txt,"rb");
        if(f!=NULL) zapisz(i,wsk,f);
        else action(i,wsk);
        i++;
    }
    
    return wsk;
}

char ** alokowanie(void)
{
    int size=sizeof(char*);
    char **wsk=(char**)calloc(4,size);
    if(wsk==NULL) return NULL;
    int i=3;
    int rozmiar=30;
    for(;i>=0;i--)
    {
        *(wsk+i)=(char *)calloc(rozmiar,1);
        if(*(wsk+i)==NULL)
        {
            
            switch(i)
            {
                case 2:
                    {
                        free(*(wsk+3));
                        break;
                    }
                case 1:
                    {
                        free(*(wsk+3));
                        free(*(wsk+2));
                        break;
                    }
                case 0:
                    {
                        free(*(wsk+3));
                        free(*(wsk+2));
                        free(*(wsk+1));
                        break;
                    }
            }
            free(wsk);
            return NULL;
        }
    }
    return wsk;
}

void destroy(char **tab, int size)
{
    if(tab==NULL || size<=0) return;
    int i=0;
    for(;i<size;i++)
    {
        free(*(tab+i));
    }
    free(tab);
}

int pobieranie(char **tab)
{
    printf("Podaj liczbe: ");
    int liczba,y;
        y=scanf("%d",&liczba);
        if(y!=1)
        {
            destroy(tab,4);
            return -1;
        }
        if(liczba>=5)
        {
            destroy(tab,4);
            return -2;      
        }
        if(liczba<=1)
        {
            destroy(tab,4);
            return -2;      
        }   
    
    return liczba;
}


void drukowanie(int liczba, struct file_stats_t* tab)
{
    if(liczba<0) return;
    if(tab==NULL) return;
    int i=0;
    while(1)
    {
        if(i==liczba) break;
        if(tab->state==EXIST)
        {
            printf("File: ");
            printf("%s",tab->filename);
            printf("; size: %d\n",tab->size);
        }
        else
        {
            printf("File: ");
            printf("%s",tab->filename);
            printf(" not exists\n");
        }
        tab++;
        i++;
    }
}


int main() 
{
    char **tab=alokowanie();
    if(tab==NULL) return printf("Failed to allocate memory"),8;
    int number=pobieranie(tab);
    if(number==-1) return printf("Incorrect input"),1;
    if(number==-2) return printf("Incorrect input data"),2;
    int c=getchar();
    if(c!='\n') while(c!='\n') c=getchar();
    printf("Podaj tekst: ");
    int i=0;
    while(1)
    {
            if(i==29)
            {
                *(*(tab+0)+i)='\0';
                break;
            }
            char znak;
            scanf("%c",&znak);
            if(znak=='\n')
            {
                *(*(tab+0)+i)='\0';
                break;
            }
            *(*(tab+0)+i)=znak;
            i++;
    }

    i=0;
    while(1)
    {
            if(i==29)
            {
                *(*(tab+1)+i)='\0';
                break;
            }
            char znak;
            scanf("%c",&znak);
            if(znak=='\n')
            {
                *(*(tab+1)+i)='\0';
                break;
            }
            *(*(tab+1)+i)=znak;
            i++;
    }   
    if(number>2)
    {
        i=0;
        while(1)
        {
                if(i==29)
                {
                    *(*(tab+2)+i)='\0';
                    break;
                }
                char znak;
                scanf("%c",&znak);
                if(znak=='\n')
                {
                    *(*(tab+2)+i)='\0';
                    break;
                }
                *(*(tab+2)+i)=znak;
                i++;
        }       
    }
    if(number>3)
    {
        i=0;
        while(1)
        {
                if(i==29)
                {
                    *(*(tab+3)+i)='\0';
                    break;
                }
                char znak;
                scanf("%c",&znak);
                if(znak=='\n')
                {
                    *(*(tab+3)+i)='\0';
                    break;
                }
                *(*(tab+3)+i)=znak;
                i++;
        }   
    }
    struct file_stats_t* wsk=NULL;
    switch(number)
    {
        case 4:
            {
                char *plik1=*(tab+0);
                char *plik2=*(tab+1);
                char *plik3=*(tab+2);
                char *plik4=*(tab+3);
                wsk=check_files(number,plik1,plik2,plik3,plik4);
                if(wsk==NULL)
                {
                    destroy(tab,4);
                    return printf("Failed to allocate memory"),8;
                }
                drukowanie(number,wsk);
                break;
            }
        case 3:
            {
                char *plik1=*(tab+0);
                char *plik2=*(tab+1);
                char *plik3=*(tab+2);
                wsk=check_files(number,plik1,plik2,plik3);          
                if(wsk==NULL)
                {
                    destroy(tab,4);
                    return printf("Failed to allocate memory"),8;
                }   
                drukowanie(number,wsk);         
                break;  
            }
        case 2:
            {
                char *plik1=*(tab+0);
                char *plik2=*(tab+1);
                wsk=check_files(number,plik1,plik2);                
                if(wsk==NULL)
                {
                    destroy(tab,4);
                    return printf("Failed to allocate memory"),8;
                }   
                drukowanie(number,wsk);         
                break;
            }
    }
    
    free(wsk);
    destroy(tab,4);
    return 0;
}
