#include <stdlib.h>
#include <stdio.h>

#define DISPLAY_BITS(value)\
{\
	int p=8*sizeof(value);\
	p-=1;\
	int g=0;\
	for(;g<=p;g++)\
	{\
		int val=0!=(value&(2ll/2<<(p-g)));\
		printf("%d",val);\
	}\
	printf("\n");\
}


#define COUNT_BITS(value, pointer_to_bits_set_counter, pointer_to_bits_cleared_counter) \
{ \
	(*pointer_to_bits_set_counter)=0;\
	(*pointer_to_bits_cleared_counter)=0;\
	int i=sizeof(value)*8-1;\
	int g=0;\
	for(;g<=i;g++) \
	{ \
		int y = 0!=(value &  (2ll/2 << (i-g))); \
		if (y != 0) (*pointer_to_bits_set_counter)+=1; \
		else (*pointer_to_bits_cleared_counter)+=1; \
	} \
}
#define REVERSE_BITS(pointer_to_variable)\
{ \
	unsigned int i=0;\
	unsigned int value=8;\
	value*=sizeof(*pointer_to_variable);\
	value/=2;\
	int g=sizeof(*pointer_to_variable);\
	g*=8;\
	g-=1;\
	for(;   i < value;   i+=1,g-=1)\
	{\
		int bit1=1;\
		bit1 = 0!=(*pointer_to_variable & (2ll/2<<i));\
		int bit2=1;\
		bit2 = 0!=(*pointer_to_variable & (2ll/2<<g));\
		if(bit1==bit2);\
		else\
		{\
			if(!bit2)  *pointer_to_variable = ~(2ll/2<<i) & *pointer_to_variable;\
			else    *pointer_to_variable = 2ll/2<<i | *pointer_to_variable;\
			if(!bit1)  *pointer_to_variable = ~(2ll/2<<g) & *pointer_to_variable;\
			else    *pointer_to_variable = 2ll/2<<g | *pointer_to_variable;\
		}\
	}\
}



int main ()
{

	printf("Podaj typ: ");
	int type;
	int y=scanf("%d",&type);
	if(y!=1) return printf("Incorrect input"),1;
	int jedynki=0,zera=0;
	if(type==0)
	{
		unsigned int num;
		printf("Podaj liczbe: ");
		y=scanf("%u",&num);
		if(y!=1) return printf("Incorrect input"),1;
		COUNT_BITS(num,&jedynki,&zera);
		printf("%d\n",jedynki);
		printf("%d\n",zera);
		DISPLAY_BITS(num);
		REVERSE_BITS(&num);
		printf("\n");
		DISPLAY_BITS(num);
	}
	else if(type==1)
	{
		unsigned short int num;
		printf("Podaj liczbe: ");
		y=scanf("%hu",&num);
		if(y!=1) return printf("Incorrect input"),1;
		COUNT_BITS(num,&jedynki,&zera);
		printf("%d\n",jedynki);
		printf("%d\n",zera);
		DISPLAY_BITS(num);
		REVERSE_BITS(&num);
		printf("\n");
		DISPLAY_BITS(num);
	}
	else if(type==2)
	{
		unsigned long long num;
		printf("Podaj liczbe: ");
		y=scanf("%llu",&num);
		if(y!=1) return printf("Incorrect input"),1;
		COUNT_BITS(num,&jedynki,&zera);
		printf("%d\n",jedynki);
		printf("%d\n",zera);
		DISPLAY_BITS(num);
		REVERSE_BITS(&num);
		printf("\n");
		DISPLAY_BITS(num);
	}
	else return printf("Incorrect input data"),2;

	return 0;
}
