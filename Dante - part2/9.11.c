#include <stdio.h>
#include <stdint.h>


int toggle_bit(uint64_t* pvalue, int b)
{
	if (*pvalue&(1 << b)) *pvalue = *pvalue & ~(1 << b);
	else *pvalue = *pvalue | (1 << b);
    return 0;
}

int isset_bit(const uint64_t* pvalue, int b)
{
	int mask = 1 << b;
	int y = *pvalue & mask;
	if(y!=0) return 1;
    return 0;   
}

int set_bit(uint64_t* pvalue, int b)
{
    int val=isset_bit(pvalue,b);
    if(val==1) return 0;
	toggle_bit(pvalue,b);
    return 0;
}
int clear_bit(uint64_t* pvalue, int b)
{
	int val=isset_bit(pvalue,b);
    if(val==0) return 0;
    toggle_bit(pvalue,b);
    return 0;
}

unsigned long long add(unsigned long long a, unsigned long long b)
{
	uint64_t number=a;
	int i=0;
	int bonus=0;
	for(;i<64;i++)
	{
		int bit1=isset_bit(&a,i);
		int bit2=isset_bit(&b,i);
		if(bit1==0 && bit2==0)
		{
			clear_bit(&number,i);
			bonus=0;
		}
		else if(bit1==1 && bit2==1)
		{
			clear_bit(&number,i);
			bonus=1;
		}
		else
		{
			if(bonus==1)
			{
				clear_bit(&number,i);
				bonus=1;	
			}
			else if(bonus==0)
			{
				set_bit(&number,i);
				bonus=0;
			}
		}
	}
	return number;
}

int main ()
{
	uint64_t a;
	uint64_t b;
	printf("Podaj liczby: ");
	int y=scanf("%llu %llu",&a,&b);
	if(y!=2) return printf("Incorrect input"),1;
	uint64_t result=add(a,b);
	printf("%llu",result);
}
