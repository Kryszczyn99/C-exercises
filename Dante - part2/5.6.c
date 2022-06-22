#include <stdio.h>
//#include "bit_set.h"

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

int main ()
{
 	printf("Podaj wartosci: ");
 	union bit_set tab[40];
 	union bit_set *wsk=tab;
 	int i=0;
 	while(1)
 	{
 		if(i==40) break;
 		unsigned int z;
 		int y=scanf("%x",&z);
 		if(y!=1) return printf("Incorrect input\n"),1;
 		(wsk+i)->znak=(unsigned char)z;
 		i++;
	}
	int c=getchar();
	if(c!='\n')
	{
		while(c!='\n') c=getchar();
	}
	printf("Podaj nazwe pliku: ");
	char taba[50];
	char *ptr=taba;
	i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(ptr+i)='\0';
			break;
		}
		*(ptr+i)=znak;
		i++;
	}
	for(i=0;i<40;i++)
	{
		if((wsk+i)->bity.h==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.g==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.f==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.e==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.d==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.c==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.b==1) printf("#");
		else printf(" ");
		if((wsk+i)->bity.a==1) printf("#");
		else printf(" ");
		if((i+1)%5==0) printf("\n");
	}
	FILE *f;
	f=fopen(taba,"w");
	if(f==NULL) return printf("Couldn't create file"),5;
	for(i=0;i<40;i++)
	{
		if((wsk+i)->bity.h==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.g==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.f==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.e==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.d==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.c==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.b==1) fprintf(f,"#");
		else fprintf(f," ");
		if((wsk+i)->bity.a==1) fprintf(f,"#");
		else fprintf(f," ");
		if((i+1)%5==0) fprintf(f,"\n");
	}
	fclose(f);
	printf("File saved");
	return 0;
}
