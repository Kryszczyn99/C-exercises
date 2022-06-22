#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "format_type.h"

struct statistic_t
{
	int min;
	int max;
	float avg;
	float standard_deviation;
	int range;
};

int load(const char *filename, int ***ptr, enum save_format_t format)
{
	if (filename == NULL || ptr == NULL) return 1;
	if (format == fmt_text)//tekstowy
	{
		FILE *f;
		f = fopen(filename, "r");
		if (f == NULL) return 2;//nie otworzono
		int pobrane = 0, liczba, ilosc_jedynek = 0;
		while (1) //sprawdzamy dane i ile wierszy bedzie trzeba zaalokowac
		{
			int y = fscanf(f, "%d", &liczba);
			if (y != 1) break;
			if (liczba == -1) ilosc_jedynek += 1;
			pobrane += 1;
		}
		if (pobrane == 0)
		{
			fclose(f);
		 	return 3;//pusty plik/corrupted
		}
		fseek(f, 0, SEEK_SET); //wracamy na poczatek pliku
		while(1)
		{
			char znak;
			int y = fscanf(f, "%c", &znak);
			if(y!=1) break;
			if(isalpha(znak))
			{
				fclose(f);
				return 3;
			}
		}
		fseek(f, 0, SEEK_SET); //wracamy na poczatek pliku
		*ptr = (int **)calloc(ilosc_jedynek+1, sizeof(int *));
		if (*ptr == NULL)
		{
			fclose(f);
		 	return 4;//brak pamieci
		}
		int i;
		for (i = 0; i < ilosc_jedynek; i++)
		{
			int ile_w_wierszu = 0;
			while (1)
			{
				int liczba2;
				fscanf(f, "%d", &liczba2);
				ile_w_wierszu += 1;
				if (liczba2 == -1) break;
			}
			*(*ptr + i) = (int *)calloc(ile_w_wierszu, sizeof(int));
			if (*(*ptr + i) == NULL)
			{
				i -= 1; //by wrocic na poprzedni wskaznik bo ten bylby null
				while (i >= 0)
				{
					free(*(*ptr + i));
					i--;
				}
				free(*ptr);
				fclose(f);
				return 4;//brak pamieci
			}
		}
		fseek(f, 0, SEEK_SET); //wracamy na poczatek pliku
		int j = 0;
		for (i = 0; i < ilosc_jedynek; i++) //tutaj odbywa sie przepisywanie na wskaznik
		{
			while (1)
			{
				int liczba2;
				fscanf(f, "%d", &liczba2);
				*(*(*(ptr)+i) + j) = liczba2;
				if (liczba2 == -1) break;
				j++;
			}
			j = 0;
		}
		*(*(ptr)+ilosc_jedynek) = NULL;
		fclose(f);
		return 0;
	}
	else if (format == fmt_binary)//binarny
	{
		FILE *f;
		f = fopen(filename, "rb");
		if (f == NULL) return 2;
		int pobrane = 0, liczba, ilosc_jedynek = 0;
		while (1) //sprawdzamy dane i ile wierszy bedzie trzeba zaalokowac
		{
			int y = fread(&liczba, sizeof(int), 1, f);
			if (y != 1) break;
			if (liczba == -1) ilosc_jedynek += 1;
			pobrane += 1;
		}
		if (pobrane == 0)
		{
			fclose(f);
		 	return 3;//nic w pliku nie ma/corrupted
		}
		fseek(f, 0, SEEK_SET); //wracamy na poczatek pliku
		*ptr = (int **)calloc(ilosc_jedynek+1, sizeof(int *));
		if (*ptr == NULL)
		{
			fclose(f);
		 	return 4;//brak pamieci
		}
		int i;
		for (i = 0; i < ilosc_jedynek; i++)
		{
			int ile_w_wierszu = 0;
			while (1)
			{
				int liczba2;
				fread(&liczba2, sizeof(int), 1, f);
				ile_w_wierszu += 1;
				if (liczba2 == -1) break;
			}
			*(*ptr + i) = (int *)calloc(ile_w_wierszu, sizeof(int));
			if (*(*ptr + i) == NULL)
			{
				i -= 1; //by wrocic na poprzedni wskaznik bo ten bylby null
				while (i >= 0)
				{
					free(*(*ptr + i));
					i--;
				}
				free(*ptr);
				fclose(f);
				return 4;//brak pamieci
			}
		}
		fseek(f, 0, SEEK_SET); //wracamy na poczatek pliku
		int j = 0;
		for (i = 0; i < ilosc_jedynek; i++) //tutaj odbywa sie przepisywanie na wskaznik
		{
			while (1)
			{
				int liczba2;
				fread(&liczba2, sizeof(int), 1, f);
				*(*(*(ptr)+i) + j) = liczba2;
				if (liczba2 == -1) break;
				j++;
			}
			j = 0;
		}
		*(*(ptr)+ilosc_jedynek) = NULL;
		fclose(f);
		return 0;
	}
	return 1;
}
int statistics_row(int **ptr, struct statistic_t **stats)
{
	if (ptr == NULL || stats == NULL) return -1;
	int ile_wierszy = 0, i = 0;
	while (1)
	{
		if (*(ptr + i) == NULL) break;
		i++;
		ile_wierszy += 1;
	}
	*stats = (struct statistic_t *)malloc(ile_wierszy * sizeof(struct statistic_t)); //<--Here
	if (*stats == NULL) return -2;
	int g = 0, p = 0;
	while (1)
	{
		if (*(ptr + p) == NULL) break;
		int pusty_rzad = 0;
		int min = **(ptr + p);
		int max = **(ptr + p);
		int range = 0;
		float odchylenie = 0;
		float avg = 0;
		while (1)
		{
			if (*(*(ptr + p) + g) == -1) break;
			pusty_rzad += 1;
			g++;
		}
		if (pusty_rzad == 0)
		{
			(*stats + p)->avg = -1;
			(*stats + p)->standard_deviation = -1;
			(*stats + p)->min = -1;
			(*stats + p)->max = -1;
			(*stats + p)->range = -1;
		}
		else
		{
			g = 0;
			while (1)
			{
				if (*(*(ptr + p) + g) == -1) break;
				if (min > *(*(ptr + p) + g)) min = *(*(ptr + p) + g);
				if (max < *(*(ptr + p) + g)) max = *(*(ptr + p) + g);
				avg += *(*(ptr + p) + g);
				g++;
			}
			g = 0;
			avg /= pusty_rzad;
			range = max - min;
			while (1)
			{
				if (*(*(ptr + p) + g) == -1) break;
				odchylenie += (*(*(ptr + p) + g) - avg)*(*(*(ptr + p) + g) - avg);
				g++;
			}
			odchylenie /= pusty_rzad;
			odchylenie = sqrt(odchylenie);
			(*stats + p)->avg = avg;
			(*stats + p)->standard_deviation = odchylenie;
			(*stats + p)->max = max;
			(*stats + p)->min = min;
			(*stats + p)->range = range;
		}
		g = 0;
		p++;
	}
	return p;
}
void destroy(int ***ptr)
{
	if (ptr == NULL) return;
	int p = 0;
	while (1)
	{
		if (*(*(ptr)+p) == NULL)
		{
			free(*(*(ptr)+p));
			break;
		} 
		free(*(*(ptr)+p));
		p++;
	}
	free(*ptr);
	*ptr = NULL;
}

void display(int **ptr)
{
	if (ptr == NULL) return;
	int g = 0, p = 0;
	while (1)
	{
		if (*(ptr + p) == NULL) break;
		while (1)
		{
			if (*(*(ptr + p) + g) == -1) break;
			printf("%d ", *(*(ptr + p) + g));
			g++;
		}
		g = 0;
		printf("\n");
		p++;
	}
}

int main()
{
	char *wsk_tab = (char *)malloc(40 * sizeof(char));
	if (wsk_tab == NULL) return printf("Failed to allocate memory\n"), 8;
	printf("Podaj nazwe pliku: ");
	int i = 0;
	while (1)
	{
		if (i >= 39) break;
		char znak;
		scanf("%c", &znak);
		if (znak == '\n') break;
		*(wsk_tab + i) = znak;
		i++;
	}
	*(wsk_tab + i) = '\0';
	int len_tab = strlen(wsk_tab);
	if (*(wsk_tab + len_tab - 1) == 'n' &&
		*(wsk_tab + len_tab - 2) == 'i' &&
		*(wsk_tab + len_tab - 3) == 'b' &&
		*(wsk_tab + len_tab - 4) == '.')
	{
		//printf("Binarny\n");
		int **wsk_bin;
		int g = load(wsk_tab, &wsk_bin, fmt_binary);
		if (g != 0) free(wsk_tab);
		if (g == 4) return printf("Failed to allocate memory\n"), 8;
		if (g == 3) return printf("File corrupted\n"), 6;
		if (g == 1 || g == 2) return printf("Couldn't open file\n"), 4;
		struct statistic_t *wskaznik;
		g = statistics_row(wsk_bin, &wskaznik);
		if (g == -1 || g == -2)
		{
			free(wsk_tab);
			destroy(&wsk_bin);
			return printf("Failed to allocate memory\n"), 8;
		}
		for(i=0;i<g;i++)
		{
			printf("%d %d %d %f %f\n",(wskaznik+i)->min,(wskaznik+i)->max,(wskaznik+i)->range,(wskaznik+i)->avg,(wskaznik+i)->standard_deviation);
		}
		free(wsk_tab);
		free(wskaznik);
		destroy(&wsk_bin);
	}
	else if (*(wsk_tab + len_tab - 1) == 't' &&
		*(wsk_tab + len_tab - 2) == 'x' &&
		*(wsk_tab + len_tab - 3) == 't' &&
		*(wsk_tab + len_tab - 4) == '.')
	{
		//printf("Tekstowy\n");
		int **wsk_txt;
		int g = load(wsk_tab, &wsk_txt, fmt_text);
		if (g != 0) free(wsk_tab);
		if (g == 4) return printf("Failed to allocate memory\n"), 8;
		if (g == 3) return printf("File corrupted\n"), 6;
		if (g == 1 || g == 2) return printf("Couldn't open file\n"), 4;
		struct statistic_t *wskaznik;
		g = statistics_row(wsk_txt, &wskaznik);
		if (g == -1 || g == -2)
		{
			free(wsk_tab);
			destroy(&wsk_txt);
			return printf("Failed to allocate memory\n"), 8;
		}
		for(i=0;i<g;i++)
		{
			printf("%d %d %d %f %f\n",(wskaznik+i)->min,(wskaznik+i)->max,(wskaznik+i)->range,(wskaznik+i)->avg,(wskaznik+i)->standard_deviation);
		}
		free(wsk_tab);
		free(wskaznik);
		destroy(&wsk_txt);
	}
	else
	{
		free(wsk_tab);
		return printf("Unsupported file format\n"), 7;
	}
	
	return 0;
}
