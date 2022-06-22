#include <stdio.h>

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	FILE *plik;
	plik=fopen(tab,"r");
	if(plik==NULL) return printf("Couldn't open file\n"),4;
	int g=getc(plik);
	int p=0;
	while(1)
	{
		if(g==EOF) break;
		printf("%c",g);
		g=getc(plik);
		p+=1;
	}
	if(p==0) printf("Nothing to show\n");
	fclose(plik);
	return 0;
}
