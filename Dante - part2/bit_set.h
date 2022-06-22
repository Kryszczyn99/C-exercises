#ifndef bit_sett
#define bit_sett
#include <stdio.h>
union bit_set{
	struct bite{
		unsigned char a:1;
		unsigned char b:1;
		unsigned char c:1;
		unsigned char d:1;
		unsigned char e:1;
		unsigned char f:1;
		unsigned char g:1;
		unsigned char h:1;
	}bity;
	unsigned char znak;
};
#endif // word
