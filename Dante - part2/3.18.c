#include <stdio.h>
#include <ctype.h>

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	FILE *plik;
	plik=fopen(tab,"r");
	if(plik==NULL) return printf("COULDN'T OPEN FILE\n"),4;
	int g=getc(plik);
	int p=0;
	while(1)
	{
		if(g==EOF) break;
		char znak=g;
		if(!isalpha(znak)) printf("%c",znak);
		else if(isupper(znak)) printf("%c",znak);
		else
		{
			znak-='a'-'A';
			printf("%c",znak);
		}
		g=getc(plik);
		p+=1;
	}
	if(p==0) printf("NOTHING TO SHOW\n");
	fclose(plik);
	return 0;
}
