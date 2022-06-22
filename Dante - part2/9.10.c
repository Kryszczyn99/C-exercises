#include <stdint.h>
#include <stdio.h>

int isset_bit(uint32_t* pvalue, int b)
{
	int mask = 1 << b;
	int y = *pvalue & mask;
	if(y!=0) return 1;
    return 0;   

}

int longest_series(unsigned int x)
{
	int max=0;
	int i=0;
	int zliczanie=0;
	for(i=0;i<32;i++)
	{
		int b=isset_bit(&x,i);
		if(b==0)
		{
			if(zliczanie>max) max=zliczanie;
			zliczanie=0;
		} 
		else if(b==1)
		{
			zliczanie+=1;
		}
	}
	if(zliczanie>max) max=zliczanie;
	return max;
}

int main ()
{
	printf("Podaj liczbe: ");
	unsigned int x;
	int y=scanf("%u",&x);
	if(y!=1) return printf("Incorrect input"),1;
	int g=longest_series(x);
	printf("%d\n",g);
	return 0;
}
