#include <stdio.h>

union double_to_char_t
{
	double d;
	char tab[8];
};

int save_double(const union double_to_char_t *dtc, const char *filename);
int load_double(union double_to_char_t *dtc, const char *filename);

int main()
{
	double input;
	printf("Podaj liczbe: ");
	int y = scanf("%lf", &input);
	if (y != 1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj nazwe pliku: ");
	char tab[40];
	int c = getchar();
	if (c != '\n')
	{
		while (c != '\n')   c = getchar();
	}
	scanf("%39[^\n]s", tab);
	union double_to_char_t unia;
	unia.d = input;
	int g = save_double(&unia, tab);
	if (g == 1) return printf("Incorrect input\n"), 1;
	if (g == 2) return printf("Couldn't create file\n"), 5;
	printf("File saved\n");
	c = getchar();
	if (c != '\n')
	{
		while (c != '\n')   c = getchar();
	}
	char tab2[40];
	printf("Podaj nazwe pliku: ");
	scanf("%39[^\n]s", tab2);
	union double_to_char_t unia2;
	g = load_double(&unia2, tab2);
	if (g == 1) return printf("Incorrect input\n"), 1;
	if (g == 2) return printf("Couldn't open file\n"), 4;
	if (g == 3) return printf("File corrupted\n"), 6;
	printf("%lf", unia2.d);
	return 0;
}

int save_double(const union double_to_char_t *dtc, const char *filename)
{
	if (dtc == NULL || filename == NULL) return 1;
	FILE *plik;
	plik = fopen(filename, "w");
	if (plik == NULL) return 2;
	char *wsk = (char *)dtc;

	int i;
	for (i = 0; i < 8; i++)
	{
		fprintf(plik, "%c", *wsk);
		wsk++;
	}
	fclose(plik);
	return 0;
}

int load_double(union double_to_char_t *dtc, const char *filename)
{
	if (dtc == NULL || filename == NULL) return 1;
	FILE *plik;
	plik = fopen(filename, "r");
	if (plik == NULL) return 2;
	int i;
	char *wsk = (char*)dtc;
	for (i = 0; i < 8; i++)
	{
		char znak;
		int y = fscanf(plik, "%c", &znak);
		if (y != 1)
		{
			fclose(plik);
			return 3;
		}
		*wsk = znak;
		wsk++;
	}
	fclose(plik);
	return 0;
}
