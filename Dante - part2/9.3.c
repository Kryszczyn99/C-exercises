#include <stdio.h>
#include <stdint.h>

void show(const void* ptr, size_t count)
{
	if(ptr==NULL || count<=0) return;
	unsigned int i=0;
	char *wsk=(char *) ptr;
	for(;i<count;i++,wsk++)
	{
		if(*wsk=='\0') printf("00 ");
		else 
		{
			if((uint8_t)*wsk>=0 && (uint8_t)*wsk<=15) printf("0");
			printf("%x ",(uint8_t)*wsk);
		}
	} 
}
void inverse_bits(void* ptr, size_t offset, size_t count)
{
	if(ptr==NULL || (int)offset<0 || count<=0) return;
	unsigned int i=offset;
	char *wsk=(char *) ptr;
	for(;i<count;i++,wsk++)
	{
		if(*wsk=='\0') printf("ff ");
		else
		{
			if((uint8_t)*wsk>=0 && (uint8_t)*wsk<=15) printf("0");
			printf("%x ",(uint8_t)~(*(wsk)));	
		} 
	}
}

int main ()
{
	printf("Podaj tekst: ");
	char tab[101];
	int i;
	int size=0;
	for(i=0;i<100;i++,size++)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			tab[i]='\0';
			size+=1;
			break;
		}
		tab[i]=znak;
	}
	char *wsk=tab;
	show(wsk,size);
	printf("\n");
	wsk=tab;
	inverse_bits(wsk,0,size);
	return 0;
}
