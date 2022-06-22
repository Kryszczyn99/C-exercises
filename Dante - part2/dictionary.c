#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"
#define SUCCESS 0
#define INC_INPUT 1
#define MEMORY 2

struct dictionary_t* create_dictionary(int N, int *err_code)
{
	if (N <= 0)
	{
		if (err_code != NULL) *err_code = INC_INPUT;
		return NULL;
	}
	struct dictionary_t* wsk = (struct dictionary_t*)malloc(sizeof(struct dictionary_t));
	if (wsk == NULL)
	{
		if (err_code != NULL) *err_code = MEMORY;
		return NULL;
	}
	struct word_count_t* ptr = (struct word_count_t*)malloc(N * sizeof(struct word_count_t));
	if (ptr == NULL)
	{
		if (err_code != NULL) *err_code = MEMORY;
		free(wsk);
		return NULL;
	}
	wsk->capacity = N;
	wsk->size = 0;
	wsk->wc = ptr;
	if (err_code != NULL) *err_code = SUCCESS;
	return wsk;
}

struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
	if (d == NULL || d->capacity <= 0 || d->size < 0 || d->wc == NULL || word == NULL) return NULL;
	int i = 0,g;
	struct word_count_t *c = d->wc;
	for (i = 0; i < d->size; i++, c++)
	{
		g = strcmp(c->word, word);
		if (g == 0) return c;
	}
	return NULL;
}
void dictionary_display(const struct dictionary_t *d)
{
	if (d == NULL || d->size < 0 || d->capacity <= 0 || d->wc == NULL || d->size>d->capacity) return;
	int i;
	struct word_count_t* c = d->wc;
	for (i = 0; i < d->size; i++)
	{
		printf("%s ", (c+i)->word);
		printf("%d\n", (c+i)->counter);
	}
}

int dictionary_add_word(struct dictionary_t *d, const char *word) {

	if (d == NULL || d->capacity <= 0 || d->size < 0 || d->wc == NULL || word == NULL) return INC_INPUT;
	struct word_count_t* wc = dictionary_find_word(d, word);
	if (wc == NULL)
	{
		int len=strlen(word);
		len+=1;
		int wielkosc=d->size;
		int pojemnosc=d->capacity;
		if (wielkosc == pojemnosc) 
		{
			struct word_count_t *wsk=d->wc;
			int rozmiar=sizeof(struct word_count_t);
			struct word_count_t* ptr = (struct word_count_t*)realloc(wsk, 2*pojemnosc*rozmiar);
			if(ptr==NULL) return MEMORY;
			d->wc = ptr;
			pojemnosc=pojemnosc*2;
			d->capacity = pojemnosc;
		}
		char *pointer=(char*)calloc(1,len);
		if(pointer==NULL) return MEMORY;
		int w1=d->size;
		struct word_count_t* gg=d->wc;
		struct word_count_t* t=gg+w1;
		t->word = pointer;
		int i=0;
		while(1)
		{
			if(*(word+i)=='\0') break;
			*(pointer+i)=*(word+i);
			i++;
		}
		t->counter = 1;
		d->size += 1;
    	
	}
	else wc->counter += 1;
	return SUCCESS;
}

void destroy_dictionary(struct dictionary_t** d)
{
	if (d == NULL || *d == NULL) return;
	int i;
	int size = (*d)->size;
	struct dictionary_t *wsk = *d;
	struct word_count_t *ptr = wsk->wc;
	struct word_count_t *backup = ptr;
	for (i = 0; i < size; i++,ptr++)
	{
		free(ptr->word);
	}
	ptr = backup;
	free(ptr);
	free(wsk);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i=0;
	i = 0;
  	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
    	i++;
    }
	return (s1[i] - s2[i]);
}

int dictionary_sort_alphabetically(struct dictionary_t *d)
{
	if (d == NULL || d->capacity <= 0 || d->size < 0 || d->wc == NULL || d->capacity < d->size) return INC_INPUT;
	int i = 0;
	int wielkosc = d->size;
	for (; i < wielkosc; i++)
	{
		int j = 0;
		for (; j < wielkosc - i - 1; j++)
		{
			char *wsk1=(d->wc+j)->word;
			char *wsk2=(d->wc+j+1)->word;
			int g=my_strcmp(wsk1,wsk2);
			if(g!=0 && !(g<0))
			{
				struct word_count_t temp = *(d->wc+j);
  				*(d->wc+j) = *(d->wc+j+1);
  				*(d->wc+j+1) = temp;
			}
		}
	}
	return SUCCESS;
}

int dictionary_sort_occurence(struct dictionary_t *d)
{
	if (d == NULL || d->capacity <= 0 || d->size < 0 || d->wc == NULL || d->capacity < d->size) return INC_INPUT;
	int i = 0;
	dictionary_sort_alphabetically(d);
	int wielkosc = d->size;
	for (; i < wielkosc; i++)
	{
		int j = 0;
		for (; j < wielkosc - i - 1; j++)
		{
			struct word_count_t t1 = *(d->wc+j);
			struct word_count_t t2 = *(d->wc+j+1);
			int w1=t1.counter;
			int w2=t2.counter;
			if(w1<w2)
			{
				struct word_count_t temp = *(d->wc+j);
  				*(d->wc+j) = *(d->wc+j+1);
  				*(d->wc+j+1) = temp;
			}
		}
	}
	return SUCCESS;
}

int save_dictionary_b(const struct dictionary_t *d, const char *filename)
{
	if(d==NULL || d->capacity<=0 || d->size<0 || d->wc==NULL || d->capacity<d->size || filename==NULL) return INC_INPUT;
	FILE *f;
	f=fopen(filename,"wb");
	if(f==NULL) return 2;
	int wielkosc_pliku=d->size;
	fwrite(&wielkosc_pliku,sizeof(int),1,f);
	int i=0;
	int h=sizeof(int);
	while(1)
	{
		if(i==wielkosc_pliku) break;
		int g=strlen((d->wc+i)->word);
		fwrite(&g,h,1,f);
		fwrite((d->wc+i)->word,1,g,f);
		int w=(d->wc+i)->counter;
		fwrite(&w,h,1,f);
		i++;
	}
	fclose(f);
	return SUCCESS;
}
char *alokacja(struct dictionary_t *slownik,int rozmiar_tablicy,int size)
{
	char *wsk= (char*)malloc(size+1);
	if(wsk==NULL) return NULL;
	(slownik->wc+rozmiar_tablicy)->word=wsk;
	return wsk; 
}
void zamykanie(FILE *f, int *err_code,struct dictionary_t* slownik,int blad)
{
	fclose(f);
	if(err_code!=NULL) *err_code=blad;
	destroy_dictionary(&slownik);
}
void main_zamykanie(FILE *f, struct dictionary_t** slownik, char *wsk)
{
	fclose(f);
	destroy_dictionary(slownik);
	free(wsk);
}
struct dictionary_t* load_dictionary_b(const char *filename, int *err_code)
{
	if(filename==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;	
	}
	FILE *f;
	f=fopen(filename,"rb");
	if(f==NULL)
	{
		if(err_code!=NULL) *err_code=2;
		return NULL;			
	}
	int w;
	int g=fread(&w,sizeof(int),1,f);
	if(g==0)
	{
		fclose(f);
		if(err_code!=NULL) *err_code=3;
		return NULL;					
	}
	if(w<=0)
	{
		fclose(f);
		if(err_code!=NULL) *err_code=3;
		return NULL;			
	}
	int p;
	struct dictionary_t* slownik = create_dictionary(w, &p);
	if(p==2)
	{
		fclose(f);
		if(err_code!=NULL) *err_code = 4;
    	return NULL;
	}
	int i=0;
	int rozmiar_tablicy=slownik->size;
	for(;i<w;i++)
	{
		int size;
		int j=fread(&size,sizeof(int),1,f);
		if(j==0)
		{
			zamykanie(f,err_code,slownik,3);
			return NULL;
		}
		if(size<=0)
		{
			zamykanie(f,err_code,slownik,3);
			return NULL;			
		}
		char * wsk=alokacja(slownik,rozmiar_tablicy,size);
		if(wsk==NULL)
		{
			zamykanie(f,err_code,slownik,4);
			return NULL;
		}
		g=fread((slownik->wc+rozmiar_tablicy)->word,1,size,f);
		if(g==0)
		{
            zamykanie(f,err_code,slownik,3);
			return NULL;
		}
		*((slownik->wc+rozmiar_tablicy)->word+size)='\0';
		/************************************/
		int liczba;
		g=fread(&liczba,sizeof(int),1,f);
		if(g!=1)
		{
			zamykanie(f,err_code,slownik,3);
			return NULL;
		}
		(slownik->wc+rozmiar_tablicy)->counter=liczba;
		rozmiar_tablicy+=1;
		slownik->size=rozmiar_tablicy;
	}
	fclose(f);
	if(err_code!=NULL) *err_code=0;
	return slownik;
}
