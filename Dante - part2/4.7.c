#include <stdio.h>
#include <math.h>

struct complex_t
{
    float re;
    float im;
};

struct complex_t* set(struct complex_t* cp, float re, float im, int *err_code)
{
	if(cp==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;		
	}
	(cp->re)=re;
	(cp->im)=im;
	if(err_code!=NULL) *err_code=0;
	return cp;
}
void show(const struct complex_t* cp)
{
	if(cp==NULL) return;
	float re=(cp->re);
	float im=(cp->im);
	printf("%.2f",re);
	if(im<0)
	{
		printf(" - i");
		im*=-1;
		printf("%.2f\n",im);
	} 
	else 
	{
		printf(" + i");
		printf("%.2f\n",im);
	}
}
float complex_abs(struct complex_t* cp, int * err_code)
{
	if(cp==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return -1;		
	}
	float im,re;
	re=(cp->re);
	im=(cp->im);
	float wynik;
	wynik=sqrt((re*re)+(im*im));
	if(err_code!=NULL) *err_code=0;
	return wynik;	
}
struct complex_t* read(struct complex_t* p, int *err_code)
{
	if(p==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;
	}
	printf("Podaj wyrazenie: ");
	float liczba;
	int y=scanf("%f",&liczba);
	if(y!=1)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;		
	}
	char znak;
	scanf("%c",&znak);
	if(znak!='-' && znak!='+')
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;		
	}
	char i;
	scanf("%c",&i);
	if(i!='i')
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;		
	}
	float liczba1;
	y=scanf("%f",&liczba1);
	if(y!=1)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;		
	}
	if(liczba1<0 && znak=='-')
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;			
	}
	if(znak=='-') liczba1*=-1;
	set(p,liczba,liczba1,err_code);
	return p;
}

int main ()
{
	struct complex_t a;
	struct complex_t b;
	int err_code;
	int *err_code1=&err_code;
	if(read(&a,err_code1)==NULL)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(read(&b,err_code1)==NULL)
	{
		printf("Incorrect input\n");
		return 1;
	}
	show(&a);
	show(&b);
	float wynik1,wynik2;
	wynik1=complex_abs(&a,err_code1);
	if(wynik1==-1)
	{
		printf("Incorrect input\n");
		return 1;		
	}
	wynik2=complex_abs(&b,err_code1);
	if(wynik2==-1)
	{
		printf("Incorrect input\n");
		return 1;		
	}
	if(wynik1==wynik2) printf("EQUAL");
	else if(wynik1>wynik2) printf("FIRST");
	else if(wynik1<wynik2) printf("SECOND");
	return 0;
}
