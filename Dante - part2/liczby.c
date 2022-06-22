#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "liczby.h"
int my_strlen(char *wsk)
{
	if (wsk == NULL) return 0;
	int len = 0;
	while (1)
	{
		if (*(wsk + len) == '\0') break;
		len++;
	}
	return len;
}

char *my_strcat(char **dest, const char * src) 
{
	if (dest == NULL) return NULL;
	if (src == NULL) return NULL;
	int w1=0;
	int calosc = 0;
	int w2 = 0;
	if (*dest == NULL)
	{
		w2 = 0;
		w1 = my_strlen((char *)src);
		calosc = w1 + 1;
		*dest = (char*)malloc(calosc*sizeof(char));
		if (*dest == NULL) return NULL;
	}
	else
	{
		w1 = my_strlen((char *)src);
		w2 = my_strlen(*dest);
		calosc = w1 + 1 + w2;
		char *wsk = NULL;
		wsk = (char*)realloc(*dest, calosc*sizeof(char));
		if (wsk == NULL) return NULL;
		else *dest = wsk;
	}
	int j = 0;
	int i = w2;
	calosc = w1 + w2;
	while(i < calosc)
	{
		*(*dest + i) = *(src + j);
		i += 1;
		j += 1;
	}
	*(*dest + i) = '\0';
	return *dest;
}

int number_len(unsigned long long number)
{
	int len = 0;
	for (; number > 0; len++) number /= 10;
	return len;
}

char *ltoa(unsigned long long number)
{
	int a = number_len(number);
	if (number > 0)
	{
		int zmienna = a + 1;
		char *wsk=NULL;
		wsk = (char*)malloc(zmienna*sizeof(char));
		if (wsk == NULL)	return NULL;
		int i=0;
		for (; i < a; i++, number /= 10)
		{
			char znak = number % 10;
			znak = znak + '0';
			int ilosc = a - i - 1;
			*(wsk + ilosc) = znak;
		}
		*(wsk + a) = '\0';
		return wsk;
	}
	char *wsk = NULL;
	wsk = (char*)malloc(2);
	if (wsk == NULL) return NULL;
	int i;
	for (i = 0; i < 2; i++)
	{
		if(i==0) *(wsk + i) = '0';
		if(i==1) *(wsk + i) = '\0';
	}
	return wsk;
}

int funkcja_1(unsigned long long number)
{
	int len = 0;
	for (; number > 999; number /= 1000, len++);
	return len;
}
int funkcja_2(unsigned long long number)
{
	for (; number > 999; number /= 1000);
	return number;
}


int number_2_words(char **text, unsigned long long number)
{
	if (text == NULL) return 1;
	char *txt = ltoa(number);
	if (txt == NULL)
	{
		*text = NULL;
		return 2;
	}
	if (number == 0)
	{
		*text = (char*)calloc(1,sizeof(char));
		if (*text == NULL)
		{
			free(txt);
			return 2;
		}
		char *wsk;
		char tab[] = "Zero";
		wsk = my_strcat(text, tab);
		if (wsk == NULL)
		{
			free(*text);
			*text = NULL;
			free(txt);
			return 2;
		}
		*text = wsk;
		free(txt);
		return 0;
	}
	for(int i=0;number > 0;i++)
	{
		unsigned long long zmienna = funkcja_2(number);
		int dlugosc = funkcja_1(number);
		if (i == 0)
		{
			*text = (char*)calloc(1, sizeof(char));
			if (*text == NULL)
			{
				free(txt);
				return 2;
			}
		}
			int p = i;
			char spacja[] = " ";
			char tab10[] = "One";
			char tab11[] = "Two";
			char tab12[] = "Three";
			char tab13[] = "Four";
			char tab14[] = "Five";
			char tab15[] = "Six";
			char tab16[] = "Seven";
			char tab17[] = "Eight";
			char tab18[] = "Nine";
			char tab100[] = "Hundred";
			char tab20[] = "Twenty";
			char tab30[] = "Thirty";
			char tab40[] = "Forty";
			char tab50[] = "Fifty";
			char tab60[] = "Sixty";
			char tab70[] = "Seventy";
			char tab80[] = "Eighty";
			char tab90[] = "Ninety";
			char tab21[] = "Ten";
			char tab22[] = "Eleven";
			char tab23[] = "Twelve";
			char tab24[] = "Thirteen";
			char tab25[] = "Fourteen";
			char tab26[] = "Fifteen";
			char tab27[] = "Sixteen";
			char tab28[] = "Seventeen";
			char tab29[] = "Eighteen";
			char tab31[] = "Nineteen";
			char *wskaznik = NULL;
			int l1 = zmienna / 100;
			l1 = l1 % 10;
			if (l1 != 0)
			{
				if (p != 0)
				{
					wskaznik = my_strcat(text, spacja);
					if (wskaznik == NULL)
					{
						free(*text);
						*text = NULL;
						free(txt);
						return 2;
					}
					*text = wskaznik;
				}
				if (l1 == 1) wskaznik = my_strcat(text, tab10);
				else if (l1 == 2) wskaznik = my_strcat(text, tab11);
				else if (l1 == 3) wskaznik = my_strcat(text, tab12);
				else if (l1 == 4) wskaznik = my_strcat(text, tab13);
				else if (l1 == 5) wskaznik = my_strcat(text, tab14);
				else if (l1 == 6) wskaznik = my_strcat(text, tab15);
				else if (l1 == 7) wskaznik = my_strcat(text, tab16);
				else if (l1 == 8) wskaznik = my_strcat(text, tab17);
				else if (l1 == 9) wskaznik = my_strcat(text, tab18);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
				wskaznik = my_strcat(text, spacja);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
				wskaznik = my_strcat(text, tab100);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
				p++;
			}
			int l2 = zmienna / 10;
			l2 = l2 % 10;
			int l3 = zmienna % 10;
			if (l2 == 1)
			{
				if (p != 0) {
					wskaznik = my_strcat(text, spacja);
					if (wskaznik == NULL)
					{
						free(*text);
						*text = NULL;
						free(txt);
						return 2;
					}
					*text = wskaznik;
				}
				if (l3 == 0) wskaznik = my_strcat(text, tab21);
				else if (l3 == 1) wskaznik = my_strcat(text, tab22);
				else if (l3 == 2) wskaznik = my_strcat(text, tab23);
				else if (l3 == 3) wskaznik = my_strcat(text, tab24);
				else if (l3 == 4) wskaznik = my_strcat(text, tab25);
				else if (l3 == 5) wskaznik = my_strcat(text, tab26);
				else if (l3 == 6) wskaznik = my_strcat(text, tab27);
				else if (l3 == 7) wskaznik = my_strcat(text, tab28);
				else if (l3 == 8) wskaznik = my_strcat(text, tab29);
				else if (l3 == 9) wskaznik = my_strcat(text, tab31);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
				p++;

			}
			else if (l2 > 1)
			{
				if (p != 0)
				{
					wskaznik = my_strcat(text, spacja);
					if (wskaznik == NULL)
					{
						free(*text);
						*text = NULL;
						free(txt);
						return 2;
					}
					*text = wskaznik;
				}
				if (l2 == 2) wskaznik = my_strcat(text, tab20);
				else if (l2 == 3) wskaznik = my_strcat(text, tab30);
				else if (l2 == 4) wskaznik = my_strcat(text, tab40);
				else if (l2 == 5) wskaznik = my_strcat(text, tab50);
				else if (l2 == 6) wskaznik = my_strcat(text, tab60);
				else if (l2 == 7) wskaznik = my_strcat(text, tab70);
				else if (l2 == 8) wskaznik = my_strcat(text, tab80);
				else if (l2 == 9) wskaznik = my_strcat(text, tab90);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
				p++;

			}
			if (l3 != 0 && l2 != 1)
			{
				if (p != 0)
				{
					wskaznik = my_strcat(text, spacja);
					if (wskaznik == NULL)
					{
						free(*text);
						*text = NULL;
						free(txt);
						return 2;
					}
					*text = wskaznik;
				}
				if (l3 == 1) wskaznik = my_strcat(text, tab10);
				else if (l3 == 2) wskaznik = my_strcat(text, tab11);
				else if (l3 == 3) wskaznik = my_strcat(text, tab12);
				else if (l3 == 4) wskaznik = my_strcat(text, tab13);
				else if (l3 == 5) wskaznik = my_strcat(text, tab14);
				else if (l3 == 6) wskaznik = my_strcat(text, tab15);
				else if (l3 == 7) wskaznik = my_strcat(text, tab16);
				else if (l3 == 8) wskaznik = my_strcat(text, tab17);
				else if (l3 == 9) wskaznik = my_strcat(text, tab18);
				if (wskaznik == NULL)
				{
					free(*text);
					*text = NULL;
					free(txt);
					return 2;
				}
				*text = wskaznik;
			}
		char tab1[] = " Thousand";
		char tab2[] = " Million";
		char tab3[] = " Billion";
		char tab4[] = " Trillion";
		char tab5[] = " Quadrillion";
		char tab6[] = " Quintillion";
		if (dlugosc == 0);
		else if (dlugosc == 1) wskaznik = my_strcat(text, tab1);
		else if (dlugosc == 2) wskaznik = my_strcat(text, tab2);
		else if (dlugosc == 3) wskaznik = my_strcat(text, tab3);
		else if (dlugosc == 4) wskaznik = my_strcat(text, tab4);
		else if (dlugosc == 5) wskaznik = my_strcat(text, tab5);
		else if (dlugosc == 6) wskaznik = my_strcat(text, tab6);
		if (wskaznik == NULL)
		{
			free(*text);
			free(txt);
			*text = NULL;
			return 2;
		}
		*text = wskaznik;
		long long a = pow(1000, dlugosc);
		number = number % a;
	}
	free(txt);
	return  0;
}
