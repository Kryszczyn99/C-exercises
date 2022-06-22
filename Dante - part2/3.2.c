#include <stdio.h>

int file_size_from_path(const char *path)
{
	if(path==NULL) return -2;
	FILE *f;
	f=fopen(path,"r");
	if(f==NULL) return -1;
	int g=getc(f);
	int p=0;
	while(1)
	{
		if(g==EOF)
		{
			break;
		} 
		g=getc(f);
		p+=1;
	}
	fclose(f);
	return p;
}
int file_size_from_file(FILE *f)
{
	if(f==NULL) return -2;
	int backup=ftell(f);
	fseek(f,0,SEEK_END);
	int size=ftell(f);
	fseek(f,backup,SEEK_SET);
	return size;
}

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	FILE *plik;
	plik=fopen(tab,"r");
	if(plik==NULL) return printf("Couldn't open file\n"),4;
	int g=file_size_from_file(plik);
	int p=file_size_from_path(tab);
	if(g!=p) printf("Error\n");
	else
	{
		printf("Rozmiar pliku wynosi %d bajt\n",g);
	}
	
	fclose(plik);
	return 0;
}
