#include <stdio.h>
#include <stdint.h>

int isset_bit(const uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
	int mask = 1 << b;
	int y = *pvalue & mask;
	if(y!=0) return 1;
    return 0;   

}

int toggle_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL || b<0 || b>=32) return -1;
	if (*pvalue&(1 << b)) *pvalue = *pvalue & ~(1 << b);
	else *pvalue = *pvalue | (1 << b);
    return 0;
}

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2)
{
	if(pvalue==NULL || b1<0 || b1>31 || b2<0 || b2>31) return 1;
	int bit1=isset_bit(pvalue,b1);
	int bit2=isset_bit(pvalue,b2);
	if(bit1==bit2) return 0;
	toggle_bit(pvalue,b1);
	toggle_bit(pvalue,b2);
	return 0;
}



int main ()
{
	printf("Podaj liczbe: ");
	unsigned int num;
	int y=scanf("%u",&num);
	if(y!=1) return printf("Incorrect input"),1;
	int a,b;
	printf("Podaj 1 bit: ");
	y=scanf("%d",&a);
	if(y!=1) return printf("Incorrect input"),1;
	printf("Podaj 2 bit: ");
	y=scanf("%d",&b);
	if(y!=1) return printf("Incorrect input"),1;
	y=swap_bits(&num,a,b);
	if(y==1) return printf("Error"),1;
	
	printf("Result: %u",num);
}
