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
	fseek(plik1,0,2);
	int dlugosc=ftell(plik1);
	int i;
	for(i=1;i<=dlugosc;i++)
	{
		fseek(plik1,dlugosc-i,0);
		int g=fgetc(plik1);
		fprintf(plik2,"%c",g);
		
	}
	fclose(plik1);
	fclose(plik2);
	printf("File copied\n");
	return 0;
}
