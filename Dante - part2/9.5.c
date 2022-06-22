#include <stdio.h>
#include <stdint.h>

int isset_bit(const uint8_t* pvalue, int b)
{
	int mask = 1 << b;
	int y = *pvalue & mask;
	if(y!=0) return 1;
    return 0;   

}

int count_bits(const void* ptr, size_t offset, size_t count)
{
	if(ptr==NULL) return -1;
	unsigned int i=offset;
	const uint8_t *wsk=ptr;
	int jedynki=0;
	for(;i<count+offset;i++)
	{
		int j=0;
		for(;j<8;j++)
		{
			
			int a=isset_bit((wsk+i),j);
			if(a==1) jedynki+=1;
		}
	}
	return jedynki;
}

int main ()
{
	printf("podaj nazwe pliku: ");
	int i=0;
	char tab[100];
	char *wsk=tab;
	while(1)
	{
		if(i==99)
		{
			*wsk='\0';
			break;
		}
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*wsk='\0';
			break;			
		}
		*wsk=znak;
		wsk++;
	}
	FILE *f;
	f=fopen(tab,"r");
	if(f==NULL) return printf("Unable to open the file"),1;
	uint8_t a[1000];
	uint8_t *ptr=a;
	int ilosc=0;
	while(1)
	{
		int y=fread(ptr,1,1,f);
		if(y!=1)
		{
			*ptr='\0';
			break;
		}
		ptr++;
		ilosc++;
	}
	int g=count_bits(a,0,ilosc);
	if(g==-1);
	else printf("%d",g);
	fclose(f);
	return 0;
}
