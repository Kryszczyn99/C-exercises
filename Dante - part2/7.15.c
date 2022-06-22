#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int warunki_load_words(char ***words,const char *filename)
{
    if(words==NULL) return 1;
    if(filename==NULL) return 1;
    return 0;
}
int zamykanie_load_words(char ***words,FILE *f,int pobrane)
{
    int i=0;
    while(1)
    {
        if(pobrane==i) break;
        char *wsk=*(*words+i);
        free(wsk);
        i++;
    }
    free(*words);
    *words=NULL;
    fclose(f);
    return 0;
}
int funkcja_alokujaca_1(int rozmiar_word,char ***words,FILE *f)
{
    char **wsk=(char**)calloc(1,rozmiar_word);
    if(wsk==NULL)
    {
        fclose(f);
        return 1;
    }
    *words=wsk;
    return 0;
}
int funkcja_alokujaca_2(int nowy_rozmiar,char ***words,FILE *f,int pobrane)
{
    char **nowa_alokacja=(char**)realloc(*words,nowy_rozmiar);
    if(nowa_alokacja==NULL)
    {
        zamykanie_load_words(words,f,pobrane);
        return 1;
    }
    *words=nowa_alokacja;
    return 0;   
}
int funkcja_alokujaca_3(int rozmiar_v2,char ***words,FILE *f,int pobrane)
{
    char *ptr=(char*)calloc(1,rozmiar_v2);
    if(ptr==NULL)
    {
        zamykanie_load_words(words,f,pobrane);
        return 1;
    }
    *(*words+pobrane)=ptr;
    return 0;
}
int check(int pobrane,char ***words,FILE *f)
{
    if(pobrane!=0)
    {
        fclose(f);
        *(*words+pobrane)=NULL;
        return 0;
    }
    zamykanie_load_words(words,f,pobrane);
    return 1;
}
int load_words(char ***words,const char *filename)
{
    int y=warunki_load_words(words,filename);
    if(y==1) return 1;
    FILE *f=fopen(filename,"rb");
    if(f==NULL) return *words=NULL,2;
    int rozmiar_word=sizeof(char*);
    y=funkcja_alokujaca_1(rozmiar_word,words,f);
    if(y==1) return 4;
    int pobrane=0;
    int rozmiar_pobrane=0;
    int rozmiar_elementu=sizeof(int);
    int ile_pobrac=1;
    while(1)
    {
        y=fread(&rozmiar_pobrane,rozmiar_elementu,ile_pobrac,f);
        if(y!=1) break;
        if(rozmiar_pobrane<=0)
        {
            zamykanie_load_words(words,f,pobrane);
            return 3;
        }
        /****************/
        int nowy_rozmiar=rozmiar_word;
        int liczba=pobrane+2;
        nowy_rozmiar=nowy_rozmiar*liczba;
        y=funkcja_alokujaca_2(nowy_rozmiar,words,f,pobrane);
        if(y==1) return 4;
        /****************/
        int rozmiar_v2=1+rozmiar_pobrane;
        y=funkcja_alokujaca_3(rozmiar_v2,words,f,pobrane);
        if(y==1) return 4;
        /****************/
        int roz_elementu=sizeof(char);
        
        y=fread(*(*words+pobrane),roz_elementu,rozmiar_pobrane,f);
        *(*(*words+pobrane)+rozmiar_pobrane)='\0';
        pobrane+=1;
        if(rozmiar_pobrane==y) continue;
        zamykanie_load_words(words,f,pobrane);
        return 3;
    }
    y=check(pobrane,words,f);
    if(y==1) return 3;
    return 0;
}
void destroy(char **words)
{
    int i=0;
    if(words==NULL) return;
    while(1)
    {
        char *wsk=*(words+i);
        if(wsk==NULL)
        {
            free(words);
            break;
        }
        free(wsk);
        i++;
    }
    return;
}

int warunki_create_crossword(char ***crossword,char **words,const char *word)
{
    if(crossword==NULL) return 1;
    if(words==NULL)
    {
        *crossword=NULL;
        return 1;
        
    }
    if(word==NULL)
    {
        *crossword=NULL;
        return 1;
    }
    int i=0;
    for(;*(word+i)!='\0';i++);
    int len=i;//dlugosc
    i=0;
    while(1)
    {
        if(i==len) break;
        char znak=*(word+i);
        if(znak>='a' && znak<='z')
        {
            *crossword=NULL;
            return 1;
        }
        if(znak>='A' && znak<='Z')
        {
            i++;
            continue;
        }
        else
        {
            *crossword=NULL;
            return 1;
        }
    }
    return 0;
}
int zwolnienie(char ***crossword)
{
    destroy(*crossword);
    *crossword=NULL;
    return 0;
}
int my_strcmp(char *a,char *b)
{
    int i=0;
    while((*(a+i)!='\0' && *(b+i)!='\0') && *(a+i)==*(b+i)) i++;
    if(*(a+i)==*(b+i)) return 0;
    return 1;
}
char *my_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	while (*(src+i))
	{
		*(dest+i) = *(src+i);
		i++;
	}
	*(dest+i)='\0';
	return dest;
}
int funkcja_1(int i,int j,char ***crossword,char **words)
{
	char **wsk=*crossword;
	int rozmiar;
	int p=0;
	char *ptr=*(words+j);
	for(;*(ptr+p);p++);
	rozmiar=p;
	rozmiar+=1;
    *(wsk+i)=(char*)calloc(1,rozmiar);
    if(*(wsk+i)==NULL) return zwolnienie(crossword),1;
    my_strcpy(*(wsk+i),*(words+j));
    *(*(wsk+i)+rozmiar-1)='\0';
    return 0;
}
int funkcja_2(int i,int g,int spacje,int lenik,char ***crossword)
{
	char **wskaznik=*crossword;
    char *real=(char*)realloc(*(wskaznik+i),lenik);
    if(real==NULL) return zwolnienie(crossword),1;
    *(wskaznik+i)=real;
    g=-1;
    g+=lenik-spacje-1;
    while(1)
    {
        if(g==-1) break;
        *(*(wskaznik+i)+spacje+g)=*(*(wskaznik+i)+g);
        g--;
    }
    g=0;
    char space=' ';
    while(1)
    {
        if(g==spacje) break;
        *(*(wskaznik+i)+g)=space;
        g++;
    }
    *(*(wskaznik+i)+lenik-1)='\0';
    return 0;
}
int funkcja_3(int len,char ***crossword,const char *word,int ile_lewo)
{
    int i=0;
    char **slo=*crossword;
    while(1)
    {
        if(len==i) break;
        int pozycja=-1;
        char *wyraz_1=*(slo+i);
        char znak=*(word+i);
        int g=0;
        for(;*(wyraz_1+g)!='\0';g++);
        int lenik=g;
        g=0;
        while(1)
        {
            if(g==lenik) break;
            char zn_1=*(wyraz_1+g);
            if(znak==zn_1)
            {
                pozycja=g;
                break;
            }
            g++;
        }
        g=0;
        for(;*(wyraz_1+g)!='\0';g++);
        lenik=g;
        int spacje=-pozycja+ile_lewo;
        lenik=lenik+spacje+1;
        if(spacje<=0)
        {
            i++;
            continue;
        }
        int che=funkcja_2(i,g,spacje,lenik,crossword);
        if(che==1) return 4;
        i++;
    }
    return 0;
}
int funkcja_4(int len,char ***crossword,char **words,const char *word)
{
    int i=0;
    int ile_lewo=0;
    while(1)
    {
        if(len==i) break;
        int pozycja_litery=-1;
        int j=0;
        while(1)
        {
            pozycja_litery=-1;
            char izard=*(word+i);
            char *znako=*(words+j);
            if(znako==NULL) return zwolnienie(crossword),-2;
            int w=0;
            for(;*(znako+w)!='\0';w++);
            int len=w;
            w=0;
            while(1)
            {
                if(len==w) break;
                char znaczek=*(znako+w);
                if(izard==znaczek) 
                {
                    pozycja_litery=w;
                    break;
                }
                w++;
            }

            *(*crossword+i)=NULL;
            int value=1;
            znako=*(words+j);
            char **krzyz=*crossword;
            int flaga=0;
            if(krzyz==NULL) flaga=1;
            if(flaga==0)
            {
                w=0;
                while(1)
                {
                    if(*(krzyz+w)==NULL) break;
                    if(my_strcmp(*(krzyz+w),znako)==0)
                    {
                        value=0;
                        break;
                    }
                    w++;
                }
            }
            if(value==1)
            {
                if(pozycja_litery>=0)
                {
                    int val=funkcja_1(i,j,crossword,words);
                    if(val==1) return -1;
                    break;
                }
            }
            j++;
        }
        if(ile_lewo<pozycja_litery) ile_lewo=pozycja_litery;
        i++;
    }
    return ile_lewo;
}
int create_crossword(char ***crossword,char **words,const char *word)
{
    int y=warunki_create_crossword(crossword,words,word);
    if(y==1) return 1;
    int o=0;
    while(1)
    {
        char *slowo=*(words+o);
        if(slowo==NULL) break;
        int i=0;
        for(;*(slowo+i)!='\0';i++);
        int len=i;//dlugosc
        i=0;
        while(1)
        {
            if(i==len) break;
            char znak=*(slowo+i);
            if(znak>='a' && znak<='z')
            {
                *crossword=NULL;
                return 1;
            }
            if(znak>='A' && znak<='Z')
            {
                i++;
                continue;
            }
            else
            {
                *crossword=NULL;
                return 1;
            }
        }
        o++;
    }
    int i=0;
    for(;*(word+i)!='\0';i++);
    int len=i;//dlugosc
    int rozmiar=len+1;
    int wielkosc=sizeof(char*);
    rozmiar=rozmiar*wielkosc;//do alokacji ile
    char **wsk=(char**)calloc(1,rozmiar);
    if(wsk==NULL)
    {
        *crossword=NULL;
        return 4;
    }
    *(wsk+len)=NULL;
    *crossword=wsk;
    y=funkcja_4(len,crossword,words,word);
    if(y==-1) return 4;
    if(y==-2) return 2;
    int ile_lewo=y;
    i=0;
    for(;*(word+i)!='\0';i++);
    len=i;
    int walue=funkcja_3(len,crossword,word,ile_lewo);
    if(walue==4) return 4;
    return 0;
}

int memory_clear(int tryb,char *tab,char **slowa,char **crossword, char *slowo)
{
	if(tryb==0)
	{
		free(tab);
		destroy(slowa);
	}
	if(tryb==1)
	{
		free(tab);
		free(slowo);
		destroy(slowa);
	}
	if(tryb==2)
	{
		free(tab);
		free(slowo);
		destroy(slowa);
		destroy(crossword);		
	}
	return 0;
}
int main()
{
	int size=40*sizeof(char);
	int rozmiar=11*sizeof(char);
	char *tab=(char*)calloc(1,size);
	if(tab==NULL) return printf("Failed to allocate memory"),8;
	printf("Podaj nazwe pliku: ");
	int i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(tab+i)='\0';
			break;
		}
		if(i<39)
		{
			*(tab+i)=znak;
			i++;
		}
	}
	char **slowa;
	int y=load_words(&slowa,tab);
	if(y!=0) free(tab);
	switch(y)
	{
		case 4: return printf("Failed to allocate memory"),8;
		case 3: return printf("File corrupted"),6;
		case 2: return printf("Couldn't open file"),4;
		case 0: break;
	}
	char *wsk=(char*)calloc(1,rozmiar);
	if(wsk==NULL)
	{
		memory_clear(0,tab,slowa,NULL,NULL);
		return printf("Failed to allocate memory"),8;
	}
	printf("Slowo to: ");
	int j=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(wsk+j)='\0';
			break;
		}
		if(j<10)
		{
			*(wsk+j)=znak;
			j++;
		}		
	}
	char **crossword;
	y=create_crossword(&crossword,slowa,wsk);
	switch(y)
	{
		case 4:
			{
				memory_clear(1,tab,slowa,NULL,wsk);
				return printf("Failed to allocate memory"),8;
			}
		case 2:
			{
				memory_clear(2,tab,slowa,crossword,wsk);
				return printf("Couldn't create crossword"),0;
			}
		case 1:
			{
				memory_clear(1,tab,slowa,NULL,wsk);
				return printf("Incorrect input"),1;
			}
		default:
			{
				break;
			}
	}
	i=0;
	for(;*(wsk+i);i++);
	int len=i;
	i=0;
	while(1)
	{
		if(i==len) break;
		int j=0;
		while(1)
		{
			char zn=*(*(crossword+i)+j);
			if(zn=='\0')
			{
				printf("\n");
				break;
			}
			char marko=*(wsk+i);
			char *marker=*(crossword+i);
			int zet=-1;
			int p=0;
			for(;*(marker+p)!='\0';p++);
			int lenik=p;
			p=0;
			while(1)
			{
				if(lenik==p) break;
				char znak=*(marker+p);
				if(znak==marko)
				{
					zet=p;
					break;
				}
				p++;
			}
			if(j!=zet) printf("%c",zn);
			else
			{
				printf("|");
				printf("%c",zn);
				printf("|");
			}
			j++;
		}
		i++;
	}
	memory_clear(2,tab,slowa,crossword,wsk);
	return 0;    
}
