#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int stack_push(struct stack_t **stack, char *value)
{
    struct stack_t* wsk;
    if(stack==NULL || value==NULL) return 1;
    int rozmiar=sizeof(struct stack_t);
    wsk=(struct stack_t*)calloc(1,rozmiar);
    if(wsk==NULL) return 2;
    int is_null=0;
    if(*stack==NULL) is_null=1;
    if(is_null==0)
    {
        wsk->prev=*stack;
        wsk->sentence=value;
        *stack=wsk;
    } 
    else
    {
        wsk->sentence=value;
        *stack=wsk;
    }
    return 0;
}

char *stack_pop(struct stack_t **stack, int *err_code)
{
    if(stack==NULL)
    {
        if(err_code!=NULL) *err_code=1;
        return NULL;
    }
    struct stack_t* ptr=*stack;
    if(ptr==NULL)
    {
        if(err_code!=NULL) *err_code=1;
        return NULL;
    }
    if(err_code!=NULL) *err_code=0;
    
    char *wynik;
    char *tekst=ptr->sentence;
    wynik=tekst;
    
    struct stack_t *poprzednik=ptr->prev;
    *stack=poprzednik;
    
    free(ptr);
    
    return wynik;
}

void stack_destroy(struct stack_t **stack)
{
    if(stack==NULL) return;
    if(*stack==NULL) return;
    struct stack_t *poprzednik;
    struct stack_t *wsk;
    wsk=*stack;
    while(1)
    {
        if(wsk==NULL)
        {
            *stack=NULL;
            return; 
        } 
        free(wsk->sentence);
        poprzednik=wsk->prev;
        free(wsk);
        wsk=poprzednik;
    }
}

int stack_load(struct stack_t **stack, const char *filename)
{
    if(filename==NULL) return 1;
    FILE *f;
    f=fopen(filename,"r");
    if(stack==NULL)
    {
        if(f!=NULL) fclose(f);
        return 1;
    } 
    if(*stack!=NULL)
    {
        if(f!=NULL) fclose(f);
        return 1;
    }
    if(f==NULL) return 2;
    int flaga=0;
    int flaga_alokowanie=0;
    int rozmiar=0;
    char *slowo;
    while(1)
    {
        if(flaga==0)
        {
            slowo=(char *)calloc(1,1);
            if(slowo==NULL)
            {
                fclose(f);
                return 3;
            }
            flaga=1;
        }
        rozmiar+=1;
        int z_terminatorem=1+rozmiar;
        char *bufor=realloc(slowo,z_terminatorem);
        if(bufor==NULL)
        {
            free(slowo);
            stack_destroy(stack);
            fclose(f);
            return 3;
        }
        else
        {
            char znak;
            int y=fscanf(f,"%c",&znak);
            slowo=bufor;
            if(y!=1)
            {
                int wielkosc=-1+rozmiar;
                *(slowo+wielkosc)='\0';
                free(slowo);
                break;
            }
            if(znak!='.')
            {
                int wielkosc=-1+rozmiar;
                *(slowo+wielkosc)=znak;
            }
            else
            {
                int wielkosc=rozmiar-1;
                rozmiar=0;
                *(slowo+wielkosc+1)='\0';
                *(slowo+wielkosc)='.';
                int p=stack_push(stack,slowo);
                if(p==0) flaga_alokowanie=1;
                else
                {
                    free(slowo);
                    stack_destroy(stack);
                    fclose(f);
                    return 3;
                }
            }
            if(flaga_alokowanie==1)
            {
                flaga_alokowanie=0;
                slowo=(char *)malloc(1);
            }
        }

    }
    
    fclose(f);
    return 0;
}


int stack_save(const struct stack_t *stack, const char *filename)
{
    if(filename==NULL) return 1;
    if(stack==NULL) return 1;
    FILE *f;
    f=fopen(filename,"w");
    if(f==NULL) return 2;
    const struct stack_t *wsk=stack;
    while(1)
    {
    	if(wsk==NULL)
    	{
    		fclose(f);
    		break;
    		
		}
		char *ptr=wsk->sentence;
		int i=0;
		while(1)
		{
			if(*(ptr+i)=='\0') break;
			fprintf(f,"%c",*(ptr+i));
			i+=1;
		}
		wsk=wsk->prev;
	}
    return 0;
}

