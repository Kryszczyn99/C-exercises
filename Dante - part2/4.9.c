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

void show(const struct complex_t* cp)
{
	if(cp==NULL) return;
	float re=(cp->re);
	float im=(cp->im);
	printf("%f",re);
	if(im<0)
	{
		printf(" - i");
		im*=-1;
		printf("%f\n",im);
	} 
	else 
	{
		printf(" + i");
		printf("%f\n",im);
	}
}

int read(struct complex_t* cp)
{
	if(cp==NULL) return 1;
	printf("Podaj wyrazenie: ");
	float liczba;
	int y=scanf("%f",&liczba);
	if(y!=1) return 2;
	char znak;
	scanf("%c",&znak);
	if(znak!='-' && znak!='+') return 2;
	char i;
	scanf("%c",&i);
	if(i!='i') return 2;
	float liczba1;
	y=scanf("%f",&liczba1);
	if(y!=1) return 2;
	if(liczba1<0 && znak=='-') return 2;
	if(znak=='-') liczba1*=-1;
	(cp->re)=liczba;
	(cp->im)=liczba1;
	return 0;
}

int add(const struct complex_t *first, const struct complex_t *second,
        struct complex_t* result)
        {
        	if(first==NULL || second==NULL || result==NULL) return 1;
        	float re1,re2,im1,im2,wynik_re,wynik_im;
        	re1=(first->re);
        	im1=(first->im);
        	re2=(second->re);
        	im2=(second->im);
        	wynik_re=re1+re2;
        	wynik_im=im1+im2;
        	(result->re)=wynik_re;
        	(result->im)=wynik_im;
        	return 0;
		}

int subtract(const struct complex_t *first, const struct complex_t *second,
             struct complex_t* result)
             {
	         	if(first==NULL || second==NULL || result==NULL) return 1;
	        	float re1,re2,im1,im2,wynik_re,wynik_im;
	        	re1=(first->re);
	        	im1=(first->im);
	        	re2=(second->re);
	        	im2=(second->im);
	        	wynik_re=re1-re2;
	        	wynik_im=im1-im2;
	        	(result->re)=wynik_re;
	        	(result->im)=wynik_im;
	        	return 0;            	
			 }
int multiply(const struct complex_t *first, const struct complex_t *second,
             struct complex_t* result)
             {
     	        if(first==NULL || second==NULL || result==NULL) return 1;
	        	float re1,re2,im1,im2,wynik_re,wynik_im;
	        	re1=(first->re);
	        	im1=(first->im);
	        	re2=(second->re);
	        	im2=(second->im);
	        	wynik_re=(re1*re2)-(im1*im2);
	        	wynik_im=(re1*im2)+(im1*re2);
	        	(result->re)=wynik_re;
	        	(result->im)=wynik_im;
	        	return 0;         	
			 }
int divide(const struct complex_t *first, const struct complex_t *second,
           struct complex_t* result)
           {
           	    if(first==NULL || second==NULL || result==NULL) return 1;
	        	float re1,re2,im1,im2,wynik_re,wynik_im;
	        	re1=(first->re);
	        	im1=(first->im);
	        	re2=(second->re);
	        	im2=(second->im);
	        	if(re2==0 && im2==0) return 2;
	        	wynik_re=(re1*re2+im1*im2)/(re2*re2+im2*im2);
	        	wynik_im=(re2*im1-re1*im2)/(re2*re2+im2*im2);
	        	(result->re)=wynik_re;
	        	(result->im)=wynik_im;
	        	return 0;        	
		   }

int main ()
{
	struct complex_t a;
	struct complex_t b;
	int x=read(&a);
	if(x==1 || x==2)
	{
		printf("Incorrect input\n");
		return 1;
	}
	x=read(&b);
	if(x==1 || x==2)
	{
		printf("Incorrect input\n");
		return 1;
	}
/*****************************************/
	struct complex_t dodawanie;
	x=add(&a,&b,&dodawanie);
	if(x==1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	show(&dodawanie);
/*****************************************/
	struct complex_t odejmowanie;
	x=subtract(&a,&b,&odejmowanie);
	if(x==1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	show(&odejmowanie);
/****************************************/
	struct complex_t mnozenie;
	x=multiply(&a,&b,&mnozenie);
	if(x==1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	show(&mnozenie);
/*****************************************/
	struct complex_t dzielenie;
	x=divide(&a,&b,&dzielenie);
	if(x==1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(x==2) printf("Operation not permitted");
	if(x==0) show(&dzielenie);
/*****************************************/
	return 0;
}
