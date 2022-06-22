#include <stdio.h>

union bit_set{
	unsigned int liczba;
	unsigned short int tab1[2];
	unsigned char tab2[4];
	struct bite{
		unsigned char a1:1;
		unsigned char a2:1;
		unsigned char a3:1;
		unsigned char a4:1;
		unsigned char a5:1;
		unsigned char a6:1;
		unsigned char a7:1;
		unsigned char a8:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
		unsigned char b8:1;
		unsigned char c1:1;
		unsigned char c2:1;
		unsigned char c3:1;
		unsigned char c4:1;
		unsigned char c5:1;
		unsigned char c6:1;
		unsigned char c7:1;
		unsigned char c8:1;
		unsigned char d1:1;
		unsigned char d2:1;
		unsigned char d3:1;
		unsigned char d4:1;
		unsigned char d5:1;
		unsigned char d6:1;
		unsigned char d7:1;
		unsigned char d8:1;
	}bity;
};

int main ()
{
	printf("Podaj liczbe: ");
	union bit_set unia;
	int y=scanf("%u",&(unia.liczba));
	if(y!=1) return printf("Incorrect input\n"),1;
	printf("%u\n",unia.liczba);
	printf("%d %d\n",*unia.tab1,*(unia.tab1+1));
	printf("%d %d %d %d\n",*unia.tab2,*(unia.tab2+1),*(unia.tab2+2),*(unia.tab2+3));
	printf("%u%u%u%u%u%u%u%u ",unia.bity.a8,unia.bity.a7,unia.bity.a6,unia.bity.a5,unia.bity.a4,unia.bity.a3,unia.bity.a2,unia.bity.a1);
	printf("%u%u%u%u%u%u%u%u ",unia.bity.b8,unia.bity.b7,unia.bity.b6,unia.bity.b5,unia.bity.b4,unia.bity.b3,unia.bity.b2,unia.bity.b1);
	printf("%u%u%u%u%u%u%u%u ",unia.bity.c8,unia.bity.c7,unia.bity.c6,unia.bity.c5,unia.bity.c4,unia.bity.c3,unia.bity.c2,unia.bity.c1);
	printf("%u%u%u%u%u%u%u%u",unia.bity.d8,unia.bity.d7,unia.bity.d6,unia.bity.d5,unia.bity.d4,unia.bity.d3,unia.bity.d2,unia.bity.d1);
	return 0;
}
