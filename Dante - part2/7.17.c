#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroy(char **words)
{
	if(words==NULL) return;
	int i=0;
	while(1)
	{
		char *ptr=*(words+i);
		if(ptr==NULL)
		{
			free(words);
			break;
		}
		free(ptr);
		i++;
	}
	return;
}

int warunki_create(const char *first,const char *second,char ***result)
{
	if(first==NULL) return 1;
	if(second==NULL) return 1;
	if(result==NULL) return 1;
	return 0;
}
int walidacja(const char* tab,char ***result,int number)
{
	int i=0;
	while(1)
	{
		if(i==number) break;
		char znak=*(tab+i);
		if(znak>='A' && znak<='Z');
		else
		{
			*result=NULL;
			return 1;
		}
		i++;
	}
	return 0;
}
int krzyzuj(const char *first,const char *second,char ***result,int *cross_i,int *cross_j,int rzad,int kolumny)
{
	int i=0,j=0;
	int flaga=0;
	while(1)
	{
		if(i==kolumny) break;
		j=0;
		while(1)
		{
			if(j==rzad) break;
			char znak_1=*(first+j);
			char znak_2=*(second+i);
			if(znak_1==znak_2)
			{
				flaga=1;
				*cross_i=i;
				*cross_j=j;
				break;
			}
			j++;
		}
		if(flaga==0)
		{
			i++;
			continue;
		}
		break;
	}
	if(flaga==0)
	{
		*result=NULL;
		return 1;
	}
	return 0;
}

int zwolnij_pamiec(char ***result,int i)
{
	int j=0;
	char **wsk=*result;
	while(1)
	{
		if(i==j) break;
		char *ptr=*(wsk+j);
		free(ptr);
		j++;
	}
	free(*result);
	*result=NULL;
	return 0;
}
int helper_create(int rzad,int kolumna,int *cross_i,int *cross_j,char ***result)
{
	int i=0;
	char **wsk=*result;
	int rozmiar_1=kolumna+1;
	int rozmiar_2=*cross_i+1+1;
	while(1)
	{
		if(i==rzad) break;
		if(*cross_j!=i) *(wsk+i)=(char*)calloc(1,rozmiar_2);
		if(*cross_j==i) *(wsk+i)=(char*)calloc(1,rozmiar_1);
		if(*(wsk+i)==NULL)
		{
			zwolnij_pamiec(result,i);
			return 1;
		}
		i++;
	}
	*(wsk+rzad)=NULL;
	return 0;
}
int helper_create_2(int rzad,int kolumna,int *cross_i,int *cross_j,char ***result,const char* first,const char* second)
{
	int i=0,j=0;
	char t='\0';
	char s=' ';
	char **wsk=*result;
	while(1)
	{
		if(rzad==i) break;
		j=0;
		while(1)
		{
			if(kolumna==j) break;
			char znak_1=*(second+j);
			char znak_2=*(first+i);
			if(*(cross_j)==i) *(*(wsk+i)+j)=znak_1;
			if(*(cross_j)!=i)
			{
				if(j<*(cross_i)) *(*(wsk+i)+j)=s;
				if(*(cross_i)==j) *(*(wsk+i)+j)=znak_2;
			}
			j++;
		}
		if(i!=*(cross_j)) *(*(wsk+i)+*(cross_i)+1)=t;	
		if(*(cross_j)==i) *(*(wsk+i)+kolumna)=t;	
		i++;
	}
	return 0;	
}
int create_leading_word_cross(const char *first,const char *second,char ***result)
{
	if(warunki_create(first,second,result)) return -1;
	int i=0;
	while(1)
	{
		if(*(first+i)=='\0') break;
		i++;
	}
	int rzad=i;
	i=0;
	while(1)
	{
		if(*(second+i)=='\0') break;
		i++;
	}
	int kolumna=i;
	if(walidacja(first,result,rzad)) return -1;
	if(walidacja(second,result,kolumna)) return -1;
	int a,b;
	int *cross_i=&a;
	int *cross_j=&b;
	if(krzyzuj(first,second,result,cross_i,cross_j,rzad,kolumna)) return -2;
	int rozmiar=rzad+1;
	rozmiar*=sizeof(char*);
	*result=(char**)calloc(1,rozmiar);
	if(*result==NULL) return -3;
	if(helper_create(rzad,kolumna,cross_i,cross_j,result)) return -3;
	helper_create_2(rzad,kolumna,cross_i,cross_j,result,first,second);
	return b;
}
int warunki_2(const char *first,const char *second,const char *third,const char *fourth,char ***result,char ***first_cross,char ***second_cross)
{
	if(first==NULL) return 1;
	if(second==NULL) return 1;
	if(third==NULL) return 1;
	if(fourth==NULL) return 1;
	if(result==NULL) return 1;
	if(first_cross==NULL) return 1;
	if(second_cross==NULL) return 1;
	return 0;
}
int funkcja_pomocnicza(const char *first,const char *second,const char *third,const char *fourth,char ***result,char ***first_cross,char ***second_cross,int *a,int *b)
{
	int y;
	y=create_leading_word_cross(second,first,first_cross);
	*a=y;
	if(y<0)
	{
		y=y*(-1);
		return *result=NULL,y;
	}
	y=create_leading_word_cross(fourth,third,second_cross);
	*b=y;
	if(y<0)
	{
		y=y*(-1);
		destroy(*first_cross);
		*first_cross=NULL;
		*result=NULL;
		return y;		
	}
	return 0;
}
int pamiec_zwolnij(int tryb,char*** result,char*** first_cross,char*** second_cross)
{
	if(tryb==0)
	{
		*result=NULL;
		destroy(*first_cross);
		*first_cross=NULL;
		destroy(*second_cross);
		*second_cross=NULL;
	}
	else if(tryb==1)
	{
		destroy(*result);
		*result=NULL;
		destroy(*first_cross);
		*first_cross=NULL;
		destroy(*second_cross);
		*second_cross=NULL;		
	}
	return 0;
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
int alokowanie_result(char ***result,int a,int b,const char* second,const char* fourth,char ***first_cross,char ***second_cross,int *size)
{
	int czar=sizeof(char*);
	int o=0;
	if(a>b) o=a;
	else o=b;
	int wielkosc=o+1;
	int j=0;
	while(1)
	{
		if(*(second+j)=='\0') break;
		j++;
	}
	int len_1=j;
	j=0;
	while(1)
	{
		if(*(fourth+j)=='\0') break;
		j++;
	}
	int len_2=j;
	len_1-=a;
	len_2-=b;
	int len=0;
	if(len_1>len_2) len=len_1;
	else len=len_2;
    wielkosc+=len;
    int ttt=czar*wielkosc;
    char **wsk=(char**)calloc(1,ttt);
    if(wsk==NULL)
    {
        pamiec_zwolnij(0,result,first_cross,second_cross);
        return 3;
    }
    *result=wsk;
    *size=wielkosc;
    return 0;
}
int funkcja_1(char ***result,char ***second_cross,int *Y,int a,char ***first_cross,int i)
{
	int j=0;
	char **pointer=*result;
	char **one=*first_cross;
	char **two=*second_cross;
	char *ptr=*(one+a);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int spacje=j+1+1+1;
	j=0;
	int zmienna=*Y;
	ptr=*(two+zmienna);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t1=j;
	int r=t1+1+spacje;
	char *wsk=(char*)calloc(1,r);
	if(wsk==NULL)
	{
		*(pointer+i)=NULL;
		pamiec_zwolnij(1,result,first_cross,second_cross);
       	return 3;
	}
	*(pointer+i)=wsk;
	char s=' ';
	j=0;
	while(1)
	{
		if(spacje==j)
		{
			j=0;
			while(1)
			{
				if(t1==j)
				{
					int u=t1+spacje;
					*(*(pointer+i)+u)='\0';
					(*Y)+=1;
					break;
				}
				char znak=*(*(two+zmienna)+j);
				int u=j+spacje;
				*(*(*result+i)+u)=znak;
				j++;
			}
			break;
		}
		*(*(pointer+i)+j)=s;
		j++;
	}
	return 0;
}
int funkcja_2(char ***result,char ***first_cross,char ***second_cross,int i,int *X)
{
	int j=0;
	char **one=*first_cross;
	char **pointer=*result;
	int zmienna=*X;
	char *ptr=*(one+zmienna);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t1=j;
	t1+=1;
	char *wsk=(char*)calloc(1,t1);
	if(wsk==NULL)
	{
		*(pointer+i)=NULL;
		pamiec_zwolnij(1,result,first_cross,second_cross);
		return 3;
	}
	*(pointer+i)=wsk;
	(*X)+=1;
	char *potr=*(one+zmienna);
	my_strcpy(*(pointer+i),potr);
	int r=t1-1;
	*(*(pointer+i)+r)='\0';
	return 0;
}
int funkcja_3(char ***result,char ***first_cross,char ***second_cross,int a,int i,int *X,int *Y)
{
	int j=0;
	char **one=*first_cross;
	char **two=*second_cross;
	char **pointer=*result;
	int zmienna_1=*X;
	int zmienna_2=*Y;
	(*X)+=1;
	(*Y)+=1;
	char *ptr=*(one+a);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t1=j;
	int spacje=t1+1+1+1;
	ptr=*(one+zmienna_1);
	j=0;
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t2=j;
	spacje-=t2;
	int r=spacje+t2;
	j=0;
	ptr=*(two+zmienna_2);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t3=j;
	r+=t3;
	r+=1;
	char *wsk=(char*)calloc(1,r);
	if(wsk==NULL)
	{
		*(pointer+i)=NULL;
		pamiec_zwolnij(1,result,first_cross,second_cross);
		return 3;
	}
	*(pointer+i)=wsk;
	ptr=*(one+zmienna_1);
	my_strcpy(*(pointer+i),ptr);
	j=0;
	char s=' ';
	while(1)
	{
		if(spacje==j)
		{
			j=0;
			while(1)
			{
				if(t3==j)
				{
					r-=1;
					*(*(pointer+i)+r)='\0';
					break;
				}
				char znak=*(*(two+zmienna_2)+j);
				int o=j+spacje;
				o+=t2;
				*(*(pointer+i)+o)=znak;
				j++;
			}
			break;
		}
		int k=j+t2;
		*(*(pointer+i)+k)=s;
		j++;
	}
	return 0;
}
int funkcja_4(char ***result,char ***first_cross,char ***second_cross,int i,int *X)
{
	int j=0;
	char **one=*first_cross;
	char **pointer=*result;
	int zmienna_1=*X;
	(*X)+=1;
	char *ptr=*(one+zmienna_1);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int t1=j;
	t1+=1;
	char *wsk=(char*)calloc(1,t1);
	if(wsk==NULL)
	{
		*(pointer+i)=NULL;
		pamiec_zwolnij(1,result,first_cross,second_cross);
		return 3;
	}
	*(pointer+i)=wsk;
	ptr=*(one+zmienna_1);
	my_strcpy(*(pointer+i),ptr);
	*(*(pointer+i)+t1-1)='\0';
	return 0;
}
int funkcja_5(char ***result,char ***first_cross,char ***second_cross,int i,int *Y,int a)
{
	int j=0;
	char **one=*first_cross;
	char **two=*second_cross;
	char **pointer=*result;
	int zmienna_2=*Y;
	(*Y)+=1;
	char *ptr=*(one+a);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int spacje=j;
	spacje+=1;
	spacje+=1;
	spacje+=1;
	int r=spacje+1;
	j=0;
	ptr=*(two+zmienna_2);
	while(1)
	{
		if(*(ptr+j)=='\0') break;
		j++;
	}
	int o=j;
	r+=o;
	char *wsk=(char*)calloc(1,r);
	if(wsk==NULL)
	{
		*(pointer+i)=NULL;
		pamiec_zwolnij(1,result,first_cross,second_cross);
		return 3;
	}
	*(pointer+i)=wsk;
	j=0;
	char s=' ';
	while(1)
	{
		if(spacje==j)
		{
			j=0;
			while(1)
			{
				if(o==j)
				{
					r-=1;
					*(*(pointer+i)+r)='\0';
					break;
				}
				char znak=*(*(two+zmienna_2)+j);
				int h=j+spacje;
				*(*(pointer+i)+h)=znak;
				j++;
			}
			break;
		}
		*(*(pointer+i)+j)=s;
		j++;
	}
	return 0;
}
int tworzenie_krzyza(char ***result,char ***first_cross,char ***second_cross,int size,int a,int b)
{
	int roznica=a-b;
    int bez=roznica;
    if(roznica<0) bez=bez*(-1);
    int i=0;
    while(1)
    {
    	if((*(*first_cross+i))==NULL) break;
    	i++;
	}
	int len_1=i;
	i=0;
	while(1)
	{
		if((*(*second_cross+i))==NULL) break;
		i++;
	}
	int len_2=i;
    i=0;
    int y=0;
    int X=0;
    int Y=0;
    while(1)
    {
        if(size==i)
        {
            size-=1;
            *(*result+size)=NULL;
            break;
        }
        int f1=0;
        int f2=0;
        if(X<len_1) f1=1;
        if(Y<len_2) f2=1;
        int minus=0;
        if(roznica<0) minus=1;
        if(minus && i<bez)
        {
            y=funkcja_1(result,second_cross,&Y,a,first_cross,i);
            if(y!=0) return 3;
        }
        else if(!minus && i<roznica)
        {
            y=funkcja_2(result,first_cross,second_cross,i,&X);
            if(y!=0) return 3;
        }
        else if(i>=bez && f1 && f2)
        {
            y=funkcja_3(result,first_cross,second_cross,a,i,&X,&Y);
            if(y!=0) return 3;
        }
        else if(f1)
        {
            y=funkcja_4(result,first_cross,second_cross,i,&X);
            if(y!=0) return 3;
        }
        else if(f2)
        {
            y=funkcja_5(result,first_cross,second_cross,i,&Y,a);
            if(y!=0) return 3;
        }
        i++;
    }
    return 0;
}
int create_double_leading_word_cross(const char *first,const char *second,const char *third,const char *fourth,char ***result,char ***first_cross,char ***second_cross)
{
    int y=warunki_2(first,second,third,fourth,result,first_cross,second_cross);
    if(y!=0) return y;
    int a,b;
    y=funkcja_pomocnicza(first,second,third,fourth,result,first_cross,second_cross,&a,&b);
    if(y!=0) return y;
	int size;
	y=alokowanie_result(result,a,b,second,fourth,first_cross,second_cross,&size);
	if(y!=0) return y;
	y=tworzenie_krzyza(result,first_cross,second_cross,size,a,b);
	if(y!=0) return y;
	return 0;
}

char* al(int r)
{
	char *wsk=(char*)calloc(1,r);
	if(wsk==NULL) return NULL;
	return wsk;
}
void delete_words(char *w1,char *w2,char *w3,char *w4)
{
	if(w1==NULL) return;
	free(w1);
	if(w2==NULL) return;
	free(w2);
	if(w3==NULL) return;
	free(w3);
	if(w4==NULL) return;
	free(w4);
}
void rozwal(char **result,char **jeden,char **dwa,char *w1,char *w2,char *w3,char *w4)
{
	destroy(jeden);
	destroy(dwa);
	destroy(result);
	delete_words(w1,w2,w3,w4);
}
void druk(char **p,int t)
{
	if(p==NULL) return;
	int i=0;
	while(1)
	{
		char *w=*(p+i);
		if(w==NULL)
		{
			if(t!=0) printf("\n");
			break;
		}
		int j=0;
		while(1)
		{
			char znak=*(w+j);
			if(znak=='\0') break;
			printf("%c",znak);
			j++;
		}
		printf("\n");
		i++;
	}
	return;
}
void skan(char *w)
{
	scanf("%10s",w);
}
int main ()
{
	int r=11*sizeof(char);
	char *ptr;
	ptr=al(r);
	if(ptr==NULL) return printf("Failed to allocate memory"),8;
	char *w1=ptr;
	ptr=al(r);
	if(ptr==NULL)
	{
		delete_words(w1,NULL,NULL,NULL);
		return printf("Failed to allocate memory"),8;
	}
	char *w2=ptr;
	ptr=al(r);
	if(ptr==NULL)
	{
		delete_words(w1,w2,NULL,NULL);
		return printf("Failed to allocate memory"),8;
	}
	char *w3=ptr;
	ptr=al(r);
	if(ptr==NULL)
	{
		delete_words(w1,w2,w3,NULL);
		return printf("Failed to allocate memory"),8;
	}
	char *w4=ptr;
	printf("Podaj literki: ");
	skan(w1);
	skan(w2);
	skan(w3);
	skan(w4);
	char **result;
	char **jeden;
	char **dwa;
	int y=create_double_leading_word_cross(w1,w2,w3,w4,&result,&jeden,&dwa);
	switch(y)
	{
		case 3:
			{
				delete_words(w1,w2,w3,w4);
				return printf("Failed to allocate memory"),8;
			}
		case 2:
			{
				delete_words(w1,w2,w3,w4);
				return printf("Unable to make two crosses"),0;
			}
		case 1:
			{
				delete_words(w1,w2,w3,w4);
				return printf("Incorrect input"),1;
			}
	}
	druk(jeden,1);
	druk(dwa,1);
	druk(result,0);
	rozwal(result,jeden,dwa,w1,w2,w3,w4);
  	return 0;	
}
