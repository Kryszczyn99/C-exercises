#include <stdio.h>
#include <string.h>

int read_file(const char *filename)
{
	if (filename == NULL) return -1;
	FILE *plik;
	plik = fopen(filename, "r");
	if (plik == NULL) return 0;
	fseek(plik, 0, SEEK_END);
	int dlugosc = ftell(plik);
	fseek(plik, 0, SEEK_SET);
	int p = 0;
	int ilosc_otwartych=1;
	while (1)
	{
		char tab1[31] = { 0 };
		fgets(tab1, 31, plik);
		int len = strlen(tab1);
		p += len;
		printf("%s",tab1);
		char *wsk = tab1;
		for (; *(wsk + 1) != '\0'; wsk++);
		if(*wsk=='\n') *wsk = '\0';
		FILE *f;
		f = fopen(tab1, "r");
		fseek(plik, p, SEEK_SET);
		if (f != NULL)
		{
			int value=read_file(tab1);
			fclose(f);
			ilosc_otwartych+=value;
		}
		
			
		if (p >= dlugosc - 1)
		{
			fclose(plik);
			return ilosc_otwartych;
		}

	}
	return 0;
}

int main()
{
	char tab[31] = { 0 };
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s", tab);
	FILE *plik;
	plik = fopen(tab, "r");
	if (plik == NULL) return printf("Couldn't open file\n"), 4;
	int o=read_file(tab);
	printf("%d",o);
	fclose(plik);
	return 0;
}
