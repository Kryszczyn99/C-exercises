//odczytana wiadomosc jest z visual studio w dev C++ nie dziala
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
#include <stdio.h>

union bit_set {
	unsigned char liczba;
	struct bite {
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

union bitek {
	unsigned char liczba;
	struct bites {
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


int main()
{
	printf("Podaj nazwe pliku: ");
	char tab[30] = { 0 };
	char *wsk = tab;
	int i = 0;
	while (1)
	{
		char znak;
		scanf("%c", &znak);
		if (znak == '\n') break;
		*(wsk + i) = znak;
		i++;
	}
	FILE *f;
	f = fopen(tab, "r");
	if (f == NULL)
	{
		printf("Blad otwarcia pliku\n");
		return 1;
	}
	union bitek unia;
	union bit_set u;
	while (1)
	{
		unsigned char liczba;
		int y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a8 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a7 = u.bity.a1;
		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a6 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a5 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a4 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a3 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a2 = u.bity.a1;

		y = fscanf(f, "%u", &liczba);
		if (y != 1)
		{
			printf("\nPrzerwanie petli\n");
			break;
		}
		u.liczba = liczba;
		unia.bity.a1 = u.bity.a1;
		printf("%c", unia.liczba);
	}
	fclose(f);
	return 0;
}
