#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "liczby.h"

int main()
{
	int y;
	char *text;
	unsigned long long liczba;
	printf("Podaj wartosc: ");
	y = scanf("%llu", &liczba);
	if (y == 0) return printf("Incorrect input"), 1;
	y = number_2_words(&text, liczba);
	if (y == 2) return printf("Failed to allocate memory"), 8;
	int i = 0;
	while (1)
	{
		if (*(text + i) == '\0') break;
		printf("%c", *(text+i));
		i++;
	}
	free(text);
	return 0;
}



