#include <stdio.h>

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	FILE *plik1;
	plik1=fopen(tab,"w");
	if(plik1==NULL)
	{
		return printf("Couldn't create file\n"),5;
	} 
	int i;
	for(i=0;i<=100;i++)
	{
		fprintf(plik1,"%d\n",i);	
	}	
	fclose(plik1);
	printf("File saved\n");
	return 0;
}
