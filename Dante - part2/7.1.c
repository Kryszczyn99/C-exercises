#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(int *err_code)
{
    struct student_t *ptr=(struct student_t *)malloc(sizeof(struct student_t));
    if(ptr==NULL)
	{
		if(err_code!=NULL) *err_code=4;
		return NULL;
	} 
	printf("Podaj dane :");
    char *wsk=ptr->name;
    int i,pobrane=0;
    int k=0;
    char znak;
    for(i=0;i<20;i++)
    {
        scanf("%c",&znak);
        if(znak==',')
        {
            scanf("%c",&znak);
            if(znak==' ')
            {
                *(wsk+i)='\0';
                k=1;
                break;
            } 
            else
            {
                if(err_code!=NULL) *err_code=1;
                free(ptr);
                return NULL;    
            }
        }
        if(znak=='\n')
            {
                if(err_code!=NULL) *err_code=1;
                free(ptr);
                return NULL;    
            }
        if(!isalpha(znak))
        {
            if(err_code!=NULL) *err_code=1;
            free(ptr);
            return NULL;            
        }
        pobrane+=1;
        *(wsk+i)=znak;
    }
    if(pobrane==0)
    {
        if(err_code!=NULL) *err_code=1;
        free(ptr);
        return NULL;            
    }
    if(k==0) 
    {
        if(err_code!=NULL) *err_code=1;
        free(ptr);
        return NULL;            
    }
    pobrane=0;
    k=0;
    char *ptr2=ptr->surname;
    for(i=0;i<40;i++)
    {
        scanf("%c",&znak);
        if(znak==',')
        {
            scanf("%c",&znak);
            if(znak==' ')
            {
                *(ptr2+i)='\0';
                k=1;
                break;
            } 
            else
            {
                if(err_code!=NULL) *err_code=2;
                free(ptr);
                return NULL;    
            }   
        }
        if(znak=='\n')
            {
                if(err_code!=NULL) *err_code=2;
                free(ptr);
                return NULL;    
            }
        if(isdigit(znak) || znak=='/')
        {
            if(err_code!=NULL) *err_code=2;
            free(ptr);
            return NULL;            
        }
        pobrane+=1;
        *(ptr2+i)=znak;
    }       
    if(pobrane==0)
    {
        if(err_code!=NULL) *err_code=2;
        free(ptr);
        return NULL;            
    }
    if(k==0) 
    {
        if(err_code!=NULL) *err_code=2;
        free(ptr);
        return NULL;            
    }
    int y=scanf("%d",&(ptr->index));
    if(y!=1)
    {
        if(err_code!=NULL) *err_code=3;
        free(ptr);
        return NULL;            
    }
    if(err_code!=NULL) *err_code=0;
    wsk=ptr->name;
    i=0;
    while(i<20)
    {
        if(*(wsk+i)=='\0') break;
        if(!isalpha(*(wsk+i)) && *(wsk+i)!=' ' && *(wsk+i)!='.')
        {
            *(wsk+i)='\0';
            break;
        }
        i++;
    }
    i=0;
    ptr2=ptr->surname;
    while(i<40)
    {
        if(*(ptr2+i)=='\0') break;
        if(!isalpha(*(ptr2+i)) && *(ptr2+i)!=' ' && *(ptr2+i)!='.')
        {
            *(ptr2+i)='\0';
            break;
        }
        i++;
    }
    if(err_code!=NULL) *err_code=0;
    return ptr;
}
void destroy(struct student_t **s)
{
	if(s==NULL) return;
	free(*s);
}
void show(const struct student_t* p)
{
    if(p==NULL) return;
    printf("%s %s, %d",p->name,p->surname,p->index);
}

int main ()
{
    struct student_t *value;
    int err_code;
    value=read(&err_code);
    if(err_code==4) return printf("Failed to allocate memory"),8;
    else if(err_code!=0) return printf("Incorrect input"),err_code;
	show(value);
    destroy(&value);
    return 0;
}
