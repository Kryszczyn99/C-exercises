#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*

Przygotuj funkcje do kodowania i odkodowywania wiadomosci w obrazach.
	Obraz bedzie zapisany w postaci tekstowej, kazdy wiersz w pliku to jeden wiersz obrazu.
	Obrazy beda w odcieniach szarosci, wartosci pikseli beda w zakresie 0-255.

	Wiadomosc ma byc zakodowana na ostatnim bicie kazdego piksela.
	Oznacza to, ze aby odczytac jeden znak wiadomosci konieczne bedzie przeanalizowanie 8 kolejnych pikseli (tutaj bajtow) obrazu wejsciowego.

	Funkcje powinny miec nastepujace prototypy:

	int encode(const char *input, char *txt, const char *output)

	Funkcja ma za zadanie zakodowac wiadomosc przekazana w parametrze txt w obrazie,
	ktorego nazwa zostanie przekazana w parametrze input.
	Obraz z ukryta wiadomoscia ma zostac zapisany do pliku o nazwie przekazanej parametrem output.

	Jezeli tresc wiadomosci bedzie krotsza niz maksymalna dopuszczalna dla danego obrazy to najmlodsze bity w pozostalych pikselach powinna zostac wyzerowane.

	Funkcja encode powinna zwrocic wartosc:
	 3 - jezeli niemozliwe bedzie zakodowania calej wiadomosci w pliku,
	 4 - jezeli nie uda sie utworzyc pliku wyjsciowego,
	 2 - jezeli plik wejsciowy nie bedzie istanial,
	 1 - w przypadku blednych danych przekazanych podczas wywolywania funkcji encode,
	 0 - w przypadku sukcesu.


	int decode(const char * filename, char *txt, int size)

	Funkcja ma odczytac wiadomosc ukryta w pliku o nazwie przekazanej w parametrze filename i zapisac ja do zmiennej txt.
	Parametr size oznacza pojemnosc tablicy txt w bajtach.

	Funkcja ma zwrocic:
	 3 - jezeli dane w pliku wejsciowym beda uszkodzone,
	 1 - w przypadku blednych danych wejsciowych,
	 2 - kiedy nie uda sie otworzyc pliku wejsciowego,
	 0 - w przypadku sukcesu.

	Napisz program, ktory pozwoli uzytkownikowi ukrywac wiadomosc w obrazie i odczytywac wiadomosc z obrazu.

	Wpisanie litery e/E bedzie oznaczalo, ze uzytkownik chce ukryc tekst w obrazie, wtedy program ma pobrac tekst
	do ukrycia (nie wiecej niz 1000 znakow) oraz nazwe pliku z obrazem i nazwe pliku wyjsciowego (nie przekrocza 29 znakow).

	Program powinien wyswietlic komunikat:
	- File saved w przypadku powodzenia (kod bledu 0),
	- Couldn't open file - jezeli plik wejsciowy nie zostanie odnaleziony (kod bledu 4).
	- Couldn't create file - jezeli nie mozliwe bedzie utworzenie pliku wyjsciowego (kod bledu 5),
	- File corrupted - jezeli nie uda sie zapisac wiadomosci w pliku (kod bledu 6).

	Wpisanie przez uzytkownika litery d/D bedzie oznaczalo, ze chce on odczytac wiadomosc ukryta w pliku.
	Program powinien zapytac sie uzytkownika o nazwe pliku a nastepnie wyswietlic odczytana wiadomosc i zakonczyc sie z
	kodem bledu 0.

	Program powinien wyswietlic komunikat:
	- Couldn't open file - jezeli nie uda sie otworzyc pliku zrodlowego (kod bledu 4)
	- File corrupted - jezeli nie uda sie odczytac wiadomosci z pliku (kod bledu 6).

	W przypadku podania przez uzytkownika blednego znaku program powinien wyswietlic komunikat Incorrect input data i zakocznyc dzialanie z kodem bledu 1.
	*/
union zapis {
	unsigned char znak;
	struct zapisywanie {
		unsigned char a1 : 1;
		unsigned char a2 : 1;
		unsigned char a3 : 1;
		unsigned char a4 : 1;
		unsigned char a5 : 1;
		unsigned char a6 : 1;
		unsigned char a7 : 1;
		unsigned char a8 : 1;
	}bity;
};

union odczyt {
	unsigned char znak;
	struct odczytywanie {
		unsigned char a1 : 1;
		unsigned char a2 : 1;
		unsigned char a3 : 1;
		unsigned char a4 : 1;
		unsigned char a5 : 1;
		unsigned char a6 : 1;
		unsigned char a7 : 1;
		unsigned char a8 : 1;
	}bity;
};

int decode(const char * filename, char *txt, int size)
{
	if (filename == NULL || txt == NULL || size <= 0) return 1;
	FILE *f;
	f = fopen(filename, "r");
	if (f == NULL) return 2;
	union odczyt odczyt;
	union zapis zapis;
	unsigned char zmienna;
	int y, i = 0;
	while (1)
	{
		if (i + 1 == size) break;
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			break;
		}
		odczyt.znak = zmienna;
		zapis.bity.a8 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a7 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a6 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a5 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a4 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a3 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a2 = odczyt.bity.a1;

		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			fclose(f);
			return 3;
		}
		odczyt.znak = zmienna;
		zapis.bity.a1 = odczyt.bity.a1;
		*(txt + i) = zapis.znak;
		i++;
	}
	*(txt + i) = '\0';
	fclose(f);
	return 0;
}

/*
	int encode(const char *input, char *txt, const char *output)

	Funkcja ma za zadanie zakodowac wiadomosc przekazana w parametrze txt w obrazie,
	ktorego nazwa zostanie przekazana w parametrze input.
	Obraz z ukryta wiadomoscia ma zostac zapisany do pliku o nazwie przekazanej parametrem output.

	Jezeli tresc wiadomosci bedzie krotsza niz maksymalna dopuszczalna dla danego obrazy to najmlodsze bity w pozostalych pikselach powinna zostac wyzerowane.

	Funkcja encode powinna zwrocic wartosc:
	 3 - jezeli niemozliwe bedzie zakodowania calej wiadomosci w pliku,
	 4 - jezeli nie uda sie utworzyc pliku wyjsciowego,
	 2 - jezeli plik wejsciowy nie bedzie istanial,
	 1 - w przypadku blednych danych przekazanych podczas wywolywania funkcji encode,
	 0 - w przypadku sukcesu.
*/
int encode(const char *input, char *txt, const char *output)
{
	if (input == NULL || txt == NULL || output == NULL) return 1;
	FILE *f;
	f = fopen(input, "r");
	if (f == NULL) return 2;
	FILE *F;
	F = fopen(output, "w");
	if (F == NULL)
	{
		fclose(f);
		return 4;
	}
	union zapis z;
	union odczyt o;
	int i = 0, flaga = 0;
	unsigned char zmienna;
	while (1)
	{
		int y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			break;
		}
		int j = 0;
		for (j = 0; j < 7; j++)
		{
			y = fscanf(f, "%hhu", &zmienna);
			if (y != 1)
			{
				fclose(f);
				fclose(F);
				return 3;
			}
		}
	}
	i = 0, flaga = 0;
	fseek(f, 0, SEEK_SET);
	while (1)
	{
		if (*(txt + i) == '\0') //zerowac bedziemy kazdy bit
		{
			flaga = 1;
		}
		z.znak = *(txt + i);
		/****************************************/
		int len = 0;
		char znak;
		int size;
		if (i == 0)
		{
			while (1)
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
					break;
				}
				if (!(isdigit(znak)))
				{
					break;
				}
				len++;
			}
			fseek(f, 0, SEEK_SET);
		}
		else {
			while (1)
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
					break;
				}
				if (!(isdigit(znak)))
				{
					fscanf(f, "%c", &znak);
					if (znak == '\n')
					{
						fprintf(F, "\n");
					}
					break;
				}
				len++;
			}
			size = ftell(f);
			fseek(f, size-len-1, SEEK_SET);
		}
		
		int y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			break;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a8 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a8 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/***********************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a7 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a7 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/********************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);

			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a6 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a6 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/*************************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a5 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a5 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/*************************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a4 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a4 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/******************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a3 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a3 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/***********************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fscanf(f, "%c", &znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a2 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a2 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);
		/******************************/
		len = 0;
		while (1)
		{
			fscanf(f, "%c", &znak);
			if (znak == '\n')
			{
				fprintf(F, "\n");
				break;
			}
			if (!(isdigit(znak)))
			{
				fprintf(F, "%c", znak);
				if (znak == '\n')
				{
					fprintf(F, "\n");
				}
				break;
			}
			len++;
		}
		size = ftell(f);
		fseek(f, size - len - 1, SEEK_SET);
		y = fscanf(f, "%hhu", &zmienna);
		if (y != 1)
		{
			return 3;
		}
		o.znak = zmienna;
		if (flaga == 1)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a1 == 0)
		{
			o.bity.a1 = 0;
		}
		else if (z.bity.a1 == 1)
		{
			o.bity.a1 = 1;
		}
		fprintf(F, "%hhu ", o.znak);

		if (flaga == 0)    i++;
	}
	fclose(f);
	fclose(F);
	if (flaga == 0) return 3;
	return 0;
}

int main()
{
	printf("D/d or E/e: ");
	char op;
	scanf("%c", &op);
	if (op == 'E' || op == 'e')
	{
		int c = getchar();
		if (c != '\n')
		{
			while (c != '\n') c = getchar();
		}
		printf("Podaj tresc do zakodowania: ");
		char tab[1000];
		char *wsk = tab;
		int i = 0;
		while (1)
		{
			char znak;
			scanf("%c", &znak);
			if (znak == '\n' || i == 1000)
			{
				*(wsk + i) = '\0';
				break;
			}
			*(wsk + i) = znak;
			i++;
		}

		printf("Podaj input file: ");
		char input[30];
		wsk = input;
		i = 0;
		while (1)
		{
			char znak;
			scanf("%c", &znak);
			if (znak == '\n' || i == 30)
			{
				*(wsk + i) = '\0';
				break;
			}
			*(wsk + i) = znak;
			i++;
		}

		printf("Podaj input file: ");
		char output[30];
		wsk = output;
		i = 0;
		while (1)
		{
			char znak;
			scanf("%c", &znak);
			if (znak == '\n')
			{
				*(wsk + i) = '\0';
				break;
			}
			*(wsk + i) = znak;
			i++;
		}
		int g = encode(input, tab, output);
		if (g == 0) printf("File saved");
		if (g == 1) return printf("Incorrect input"), 1;
		if (g == 2) return printf("Couldn't open file"), 4;
		if (g == 3) return printf("File corrupted"), 6;
		if (g == 4) return printf("Couldn't create file"), 5;
	}
	else if (op == 'D' || op == 'd')
	{
		int c = getchar();
		if (c != '\n')
		{
			while (c != '\n') c = getchar();
		}
		printf("Podaj output file: ");
		char tab[30];
		char *wsk = tab;
		int i = 0;
		while (1)
		{
			char znak;
			scanf("%c", &znak);
			if (znak == '\n' || i == 30)
			{
				*(wsk + i) = '\0';
				break;
			}
			*(wsk + i) = znak;
			i++;
		}
		char text[1000];
		int g = decode(wsk, text, 1000);
		if (g == 1) return printf("Incorrect input"), 1;
		if (g == 2) return printf("Couldn't open file"), 4;
		if (g == 3) return printf("File corrupted"), 6;
		printf("%s", text);
	}
	else return printf("Incorrect input data"), 1;
	return 0;
}
