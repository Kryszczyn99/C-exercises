#include <stdio.h>
#include <stdint.h>


int toggle_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
	if (*pvalue&(1 << b)) *pvalue = *pvalue & ~(1 << b);
	else *pvalue = *pvalue | (1 << b);
    return 0;
}
int set_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
    int val=isset_bit(pvalue,b);
    if(val==1) return 0;
	toggle_bit(pvalue,b);
    return 0;
}
int clear_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
	int val=isset_bit(pvalue,b);
    if(val==0) return 0;
    toggle_bit(pvalue,b);
    return 0;
}
int isset_bit(const uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
	int mask = 1 << b;
	int y = *pvalue & mask;
	if(y!=0) return 1;
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
    if(bit<0 || bit>=32) return printf("Invalid bit index\n"),1;
    printf("Wybierz operacje (0-przelacz, 1-ustaw, 2-czysc, 3-wartosc): ");
    int b;
    y=scanf("%d",&b);
    if(y!=1) return printf("Incorrect input\n"),1;
    if(b<0 || b>3) return printf("Invalid operation\n"),1;  
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

