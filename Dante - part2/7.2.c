#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct student_t
{
    char *imie;
    char *nazwisko;
    int index;
};

struct student_t* read(int *err_code)
{
    char *wsk = (char *)calloc(100,sizeof(char));
    if (wsk == NULL)
    {
        if (err_code != NULL) *err_code = 4;
        return NULL;
    }
    struct student_t *ptr = (struct student_t *)malloc(sizeof(struct student_t));
    if (ptr == NULL)
    {
        if (err_code != NULL) *err_code = 4;
        free(wsk);
        return NULL;
    }
    int i=0;
    int przecinki=0;
    printf("Podaje dane: ");
    for(i=0;i<100;i++)
    {

        char znak;
        scanf("%c",&znak);
        if(znak=='\n' || isdigit(znak))
        {
            free(wsk);
            free(ptr);
            if(przecinki==0)
            {
                if (err_code != NULL) *err_code = 1;
                return NULL;
            }
            if (err_code != NULL) *err_code = 2;
            return NULL;
        }
        if(znak==',')
        {
            przecinki+=1;
            if(przecinki==2)
            {
                break;
            }
        }
        *(wsk+i)=znak;
    }
    *(wsk+i)='\0';
    int liczba;
    int y=scanf("%d",&liczba);
    if(y!=1)
    {
        if (err_code != NULL) *err_code = 3;
        free(wsk);
        free(ptr);
        return NULL;        
    }
    int pobrane1=0;
    int flaga=0;
    for(i=0;i<100;i++)
    {
        if(isalpha(*(wsk+i)))
        {
            flaga=1;
            pobrane1+=1;
        }
        else if(flaga==1 && !isalpha(*(wsk+i)))
        {
            pobrane1+=1;
            break;       
        } 
    }
    if(flaga==0 || pobrane1==0)
    {
        if (err_code != NULL) *err_code = 1;
        free(wsk);
        free(ptr);
        return NULL;        
    }
    int pobrane2=0;
    flaga=0;
    for(;*(wsk+i)!=',';i++);
    for(;i<100;i++)
    {
        if(isalpha(*(wsk+i)))
        {
            flaga=1;
            pobrane2+=1;
        }
        else if(flaga==1 && !isalpha(*(wsk+i)))
        {
            int backup=i;
            int flag=0;
            for(;i<100;i++)
            {
                if(*(wsk+i)=='\0')
                {
                    flag=1;
                    break;
                }
                if(isalpha(*(wsk+i))) break;
            }
            if(flag==1)
            {
                pobrane2+=1;
                break;  
            }
            pobrane2+=1;
            i=backup;
        }       
    }
    if(flaga==0 || pobrane1==0)
    {
        if (err_code != NULL) *err_code = 1;
        free(wsk);
        free(ptr);
        return NULL;        
    }
    char *tekst1=(char *)calloc(pobrane1,sizeof(char));
    if (tekst1 == NULL)
    {
        if (err_code != NULL) *err_code = 4;
        free(wsk);
        free(ptr);
        return NULL;
    }   
    char *tekst2=(char *)calloc(pobrane2,sizeof(char));
    if (tekst2 == NULL)
    {
        if (err_code != NULL) *err_code = 4;
        free(wsk);
        free(tekst1);
        free(ptr);
        return NULL;
    }
    flaga=0;
    int p=0;
    for(i=0;i<100;i++)
    {
        if(isalpha(*(wsk+i)))
        {
            flaga=1;
            *(tekst1+p)=*(wsk+i);
            p+=1;
        }
        else if(flaga==1 && !isalpha(*(wsk+i)))
        {
            break;       
        }       
    }
    *(tekst1+p)='\0';
    flaga=0;
    p=0;
    for(;*(wsk+i)!=',';i++);
    for(;i<100;i++)
    {
        if(isalpha(*(wsk+i)))
        {
            flaga=1;
            *(tekst2+p)=*(wsk+i);
            p+=1;
        }
        else if(flaga==1 && !isalpha(*(wsk+i)))
        {
            int backup=i;
            int flag=0;
            for(;i<100;i++)
            {
                if(*(wsk+i)=='\0') flag=1;
                if(isalpha(*(wsk+i))) break;
            }
            if(flag==1)
            {
                break;  
            }
            i=backup;
            *(tekst2+p)=*(wsk+i);
            p+=1;
        }       
    }
    *(tekst2+p)='\0';
    ptr->imie=tekst1;
    ptr->nazwisko=tekst2;
    ptr->index=liczba;
    free(wsk);
    if (err_code != NULL) *err_code = 0;
    return ptr;
}

void destroy(struct student_t **s)
{
    if(s==NULL) return;
    free((*s)->imie);
    free((*s)->nazwisko);
    free(*s);
}
void show(const struct student_t* p)
{
    if(p==NULL) return;
    printf("%s %s, %d",p->imie,p->nazwisko,p->index);
}

int main()
{
    struct student_t *value;
    int err_code;
    value = read(&err_code);
    if (err_code == 4) return printf("Failed to allocate memory"), 8;
    else if (err_code != 0) return printf("Incorrect input"), err_code;
    show(value);
    destroy(&value);
    return 0;
}
