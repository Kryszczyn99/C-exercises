#include <stdio.h>

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	int d = getchar();
  	if (d != '\n') 
	{
	    while (d != '\n')   d = getchar();
  	}
	FILE *plik1;
	plik1=fopen(tab,"r");
	if(plik1==NULL)
	{
		return printf("Couldn't open file\n"),4;
	} 
	char tab2[31]={0};
	printf("Podaj sciezke do pliku wyjsciowego: ");
	scanf("%30[^\n]s",tab2);
	FILE *plik2;
	plik2=fopen(tab2,"w");
	if(plik2==NULL)
	{
		fclose(plik1);
		return printf("Couldn't create file\n"),5;
	} 
	int g=getc(plik1);
	while(1)
	{
		if(g==EOF) break;
		fprintf(plik2,"%c",g);
		g=getc(plik1);
	}
	printf("File copied\n");
	fclose(plik1);
	fclose(plik2);
	return 0;
}
