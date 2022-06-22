#include <stdio.h>
#include <stdint.h>

union bit_set{
    unsigned int liczba;
    struct bite{
        unsigned char a:1;
        unsigned char b:1;
        unsigned char c:1;
        unsigned char d:1;
        unsigned char e:1;
        unsigned char f:1;
        unsigned char g:1;
        unsigned char h:1;
    }bity[4];
};


int toggle_bit(uint32_t* pvalue, int b)
{
	if(pvalue==NULL || b<0 || b>=32) return -1;
	int w;
	w=b/8;
	int i=b%8;
	union bit_set unia;
	unia.liczba=*pvalue;
	struct bite *wsk=unia.bity;
	if(i==0 && ((*(wsk+w)).a)==0) set_bit(pvalue,b);
	else if(i==0 && ((*(wsk+w)).a)==1) clear_bit(pvalue,b);
	else if(i==1 && ((*(wsk+w)).b)==0) set_bit(pvalue,b);
	else if(i==1 && ((*(wsk+w)).b)==1) clear_bit(pvalue,b);
	else if(i==2 && ((*(wsk+w)).c)==0) set_bit(pvalue,b);
	else if(i==2 && ((*(wsk+w)).c)==1) clear_bit(pvalue,b);
	else if(i==3 && ((*(wsk+w)).d)==0) set_bit(pvalue,b);
	else if(i==3 && ((*(wsk+w)).d)==1) clear_bit(pvalue,b);
	else if(i==4 && ((*(wsk+w)).e)==0) set_bit(pvalue,b);
	else if(i==4 && ((*(wsk+w)).e)==1) clear_bit(pvalue,b);
	else if(i==5 && ((*(wsk+w)).f)==0) set_bit(pvalue,b);
	else if(i==5 && ((*(wsk+w)).f)==1) clear_bit(pvalue,b);
	else if(i==6 && ((*(wsk+w)).g)==0) set_bit(pvalue,b);
	else if(i==6 && ((*(wsk+w)).g)==1) clear_bit(pvalue,b);
	else if(i==7 && ((*(wsk+w)).h)==0) set_bit(pvalue,b);
	else if(i==7 && ((*(wsk+w)).h)==1) clear_bit(pvalue,b);
	return 0;
}
int set_bit(uint32_t* pvalue, int b)
{
	if(pvalue==NULL || b<0 || b>=32) return -1;
	int w;
	w=b/8;
	int i=b%8;
	union bit_set unia;
	unia.liczba=*pvalue;
	struct bite *wsk=unia.bity;
	if(i==0 && ((*(wsk+w)).a)==0) ((*(wsk+w)).a)=1;
	if(i==1 && ((*(wsk+w)).b)==0) ((*(wsk+w)).b)=1;
	if(i==2 && ((*(wsk+w)).c)==0) ((*(wsk+w)).c)=1;
	if(i==3 && ((*(wsk+w)).d)==0) ((*(wsk+w)).d)=1;
	if(i==4 && ((*(wsk+w)).e)==0) ((*(wsk+w)).e)=1;
	if(i==5 && ((*(wsk+w)).f)==0) ((*(wsk+w)).f)=1;
	if(i==6 && ((*(wsk+w)).g)==0) ((*(wsk+w)).g)=1;
	if(i==7 && ((*(wsk+w)).h)==0) ((*(wsk+w)).h)=1;
	*pvalue=unia.liczba;
	return 0;
}
int clear_bit(uint32_t* pvalue, int b)
{
	if(pvalue==NULL || b<0 || b>=32) return -1;
	int w;
	w=b/8;
	int i=b%8;
	union bit_set unia;
	unia.liczba=*pvalue;
	struct bite *wsk=unia.bity;
	if(i==0 && ((*(wsk+w)).a)==1) ((*(wsk+w)).a)=0;
	if(i==1 && ((*(wsk+w)).b)==1) ((*(wsk+w)).b)=0;
	if(i==2 && ((*(wsk+w)).c)==1) ((*(wsk+w)).c)=0;
	if(i==3 && ((*(wsk+w)).d)==1) ((*(wsk+w)).d)=0;
	if(i==4 && ((*(wsk+w)).e)==1) ((*(wsk+w)).e)=0;
	if(i==5 && ((*(wsk+w)).f)==1) ((*(wsk+w)).f)=0;
	if(i==6 && ((*(wsk+w)).g)==1) ((*(wsk+w)).g)=0;
	if(i==7 && ((*(wsk+w)).h)==1) ((*(wsk+w)).h)=0;
	*pvalue=unia.liczba;
	return 0;
}
int isset_bit(const uint32_t* pvalue, int b)
{
	if(pvalue==NULL || b<0 || b>=32) return -1;
	int w;
	w=b/8;
	int i=b%8;
	union bit_set unia;
	unia.liczba=*pvalue;
	struct bite *wsk=unia.bity;
	if(i==0) return ((*(wsk+w)).a);
	if(i==1) return ((*(wsk+w)).b);
	if(i==2) return ((*(wsk+w)).c);
	if(i==3) return ((*(wsk+w)).d);
	if(i==4) return ((*(wsk+w)).e);
	if(i==5) return ((*(wsk+w)).f);
	if(i==6) return ((*(wsk+w)).g);
	if(i==7) return ((*(wsk+w)).h);
	return 0;	
}

int main ()
{
	unsigned int liczba;
	printf("Podaj wartosc: ");
	int y=scanf("%u",&liczba);
	if(y!=1) return printf("Incorrect input\n"),1;
	printf("Podaj bit do operacji: ");
	int bit;
	y=scanf("%d",&bit);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(bit<0 || bit>=32) return printf("Invalid bit index\n"),2;
	printf("Wybierz operacje (0-przelacz, 1-ustaw, 2-czysc, 3-wartosc): ");
	int b;
	y=scanf("%d",&b);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(b<0 || b>3) return printf("Invalid operation\n"),2;	
	if(b==0)
	{
		int g=toggle_bit(&liczba,bit);
		if(g==0)
		{
			printf("%x",liczba);
		}
	}
	else if(b==1)
	{
		int g=set_bit(&liczba,bit);
		if(g==0)
		{
			printf("%x",liczba);
		}
	}
	else if(b==2)
	{
		int g=clear_bit(&liczba,bit);
		if(g==0)
		{
			printf("%x",liczba);
		}
	}
	else if(b==3)
	{
		int g=isset_bit(&liczba,bit);
		if(g!=-1)
		{
			printf("%d\n",g);
		}
	}
	return 0;
}
