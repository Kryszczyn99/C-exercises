#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#define MEMORY 8
#define INC_INP 1
#define INC_DATA 2
#define FILE_O 4
#define FILE_C 6

int main()
{
	char *wsk = (char *)calloc(40, 1);
	if (wsk == NULL) return printf("Failed to allocate memory"), MEMORY;
	printf("Podaj plik: ");
	int i = 0;
	int operacja;
	while (1)
	{
		char znak;
		scanf("%c", &znak);
		if (znak == '\n' || i == 39)
		{
			*(wsk + i) = '\0';
			printf("Podaj operacje: ");
			int g = scanf("%d", &operacja);
			if (g != 1)
			{
				free(wsk);
				return printf("Incorrect input"), INC_INP;
			}
			break;
		}
		*(wsk + i) = znak;
		i++;
	}
	struct dictionary_t *slownik;
	FILE *f;
	switch (operacja)
	{
	case 1:
	{
		f = fopen(wsk, "r");
		if (f == NULL)
		{
			free(wsk);
			return printf("Couldn't open file"), FILE_O;
		}
		int err_code = 0;
		struct dictionary_t* pointer = create_dictionary(1, &err_code);
		if (err_code == 2)
		{
			free(wsk);
			fclose(f);
			return printf("Failed to allocate memory"), MEMORY;
		}
		slownik = pointer;
		char *tekst = (char *)calloc(50, 1);
		if (tekst == NULL)
		{
			main_zamykanie(f, &slownik, wsk);
			return printf("Failed to allocate memory"), MEMORY;
		}
		int wielkosc = 0;
		while (!feof(f))
		{
			char znak;
			int o = fscanf(f, "%c", &znak);
			if (o == 0) break;
			if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z'))
			{
				*(tekst + wielkosc) = znak;
				wielkosc += 1;
			}
			else if (wielkosc >= 1 && !((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')))
			{
				*(tekst + wielkosc) = '\0';
				int w = dictionary_add_word(slownik, tekst);
				if (w == 2)
				{
					main_zamykanie(f, &slownik, wsk);
					free(tekst);
					return printf("Failed to allocate memory"), MEMORY;
				}
				wielkosc = 0;
			}
		}
		free(tekst);
		fclose(f);
		break;
	}
	case 0:
	{
		int err_code = 0;
		struct dictionary_t *ptr = load_dictionary_b(wsk, &err_code);
		if (err_code != 0)
		{
			free(wsk);
			switch (err_code)
			{
			case 4: return printf("Failed to allocate memory"), MEMORY;
			case 3: return printf("File corrupted"), FILE_C;
			case 2: return printf("Couldn't open file"), FILE_O;
			}
		}
		slownik = ptr;
		break;
	}
	default:
	{
		return printf("Incorrect input data"), INC_DATA;
	}
	}
	char *wsk2 = (char *)malloc(50);
	if (wsk2 == NULL)
	{
		free(wsk);
		destroy_dictionary(&slownik);
		return printf("Failed to allocate memory"), MEMORY;
	}
	char znaczko='.';
	strcpy(wsk2,wsk);
	
	strcat(wsk2,znaczko);
	int y = 0;
	for (; *(wsk2 + y) != '.'; y++);
	char tab[10];
	char *hgj = tab;
	int t = y;
	int wynik = 0;
	for (; *(wsk2 + t) != '\0'; t++,wynik++)
		*(hgj + wynik) = *(wsk2 + t);
	*(hgj + wynik) = *(wsk2 + t);
	*(wsk2 + y) = '_';
	*(wsk2 + y + 1) = 'a';
	*(wsk2 + y + 2) = 'l';
	*(wsk2 + y + 3) = 'p';
	*(wsk2 + y + 4) = 'h';
	*(wsk2 + y + 5) = 'a';
	strcat(wsk2, tab);
	dictionary_sort_alphabetically(slownik);
	wynik = 0;
	switch (operacja)
	{
		case 1:
		{
			f = fopen(wsk2, "w");
			if (f == NULL)
			{
				printf("Couldn't create file\n");
			}
			else
			{
				i = 0;
				int wielkosc = slownik->size;
				for (; i < wielkosc; i++)
				{
					int j = 0;
					for (; *((slownik->wc + i)->word + j) != '\0'; j++)
					{
						fprintf(f, "%c", *((slownik->wc + i)->word + j));
					}
				}
				fclose(f);
				printf("File saved\n");
			}
			break;
		}
		case 0:
		{
			wynik = save_dictionary_b(slownik, wsk2);
			break;
		}
	}
	char *wsk3 = (char *)malloc(50);
	if (wsk3 == NULL)
	{
		free(wsk);
		destroy_dictionary(&slownik);
		return printf("Failed to allocate memory"), MEMORY;
	}
	strcpy(wsk3,wsk);
	strcat(wsk3,znaczko);
	y = 0;
	for (; *(wsk3 + y) != '_'; y++);
	*(wsk3 + y + 1) = 'o';
	*(wsk3 + y + 2) = 'c';
	*(wsk3 + y + 3) = 'c';
	*(wsk3 + y + 4) = '\0';
	strcat(wsk3, tab);
	dictionary_sort_occurence(slownik);
	switch (operacja)
	{
		case 1:
		{
			f = fopen(wsk3, "w");
			if (f == NULL)
			{
				printf("Couldn't create file\n");
			}
			else
			{
				i = 0;
				int wielkosc = slownik->size;
				for (; i < wielkosc; i++)
				{
					int j = 0;
					for (; *((slownik->wc + i)->word + j) != '\0'; j++)
					{
						fprintf(f, "%c", *((slownik->wc + i)->word + j));
					}
				}
				fclose(f);
				printf("File saved\n");
			}
			break;
		}
		case 0:
		{
			wynik = save_dictionary_b(slownik, wsk3);
			break;
		}
	}
	free(wsk);
	destroy_dictionary(&slownik);
	return 0;
}
