#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validate(const char * number)
{
	if (number == NULL) return -1;
	if (*number == '\n') return 2;
	int len = 0;
	const char *znak = number;
	for (; *znak != '\0'; znak++) len++;
	if (*number == '0' && len == 1) return 0;
	if (*number == '-' && len == 1) return 2;
	if (*number == '0' && *(number + 1) != '0') return 2;
	int i, flaga = 0;
	for (i = 0; *number != '\0'; number++, i++)
	{
		if (isdigit(*number) == 0)
		{
			if (i == 0 && *number == '-');
			else return 2;
		}
		if (i == 0 && *number == '0') flaga = 1;
		else if (isdigit(*number) && *number != '0' && flaga == 1) return 2;
		else if (*(number + 1) == '\0') return 0;
	}
	return 2;
}
int compare(const char* number1, const char* number2)
{
	if (number1 == NULL || number2 == NULL) return 2;
	int g;
	g = validate(number1);
	if (g != 0) return 3;
	g = validate(number2);
	if (g != 0) return 3;
	int len_1 = strlen(number1);
	int len_2 = strlen(number2);
	int t = strcmp(number1, number2);
	if (len_1 == len_2 && t == 0) return 0;
	if(*number1=='-' && *number2=='-' && len_1==len_2)
	{
		int l=0;
		while(1)
		{
			if(len_1==0) break;
			if (*(number1 + l) < *(number2 + l)) return 1;
			if (*(number1 + l) > *(number2 + l)) return -1;
			len_1--;
			l++;
		}
		return 0;
	}
	if (len_1 == len_2)
	{
		int l = 0;
		while (1)
		{
			if (len_1 == 0) break;
			if (*(number1 + l) > *(number2 + l)) return 1;
			if (*(number1 + l) < *(number2 + l)) return -1;
			len_1--;
			l++;
		}
		return 0;
	}
	else if (len_1 > len_2) return 1;
	else if (len_1 < len_2) return -1;
	return 2;
}

int compare_alokacja(const char* number1, const char* number2)
{
	if (number1 == NULL || number2 == NULL) return 2;
	int g;
	g = validate(number1);
	if (g != 0) return 3;
	g = validate(number2);
	if (g != 0) return 3;
	int len_1 = strlen(number1);
	int len_2 = strlen(number2);
	int t = strcmp(number1, number2);
	if (len_1 == len_2 && t == 0) return 0;
	if (len_1 == len_2)
	{
		int l = 0;
		while (1)
		{
			if (len_1 == 0) break;
			if (*(number1 + l) > *(number2 + l)) return 1;
			if (*(number1 + l) < *(number2 + l)) return -1;
			len_1--;
			l++;
		}
		return 0;
	}
	else if (len_1 > len_2) return 1;
	else if (len_1 < len_2) return -1;
	return 2;
}

int my_strlen(const char* znak)
{
	int i = 0;
	for (; *(znak + i) != '\0'; i++);
	return i;
}

int dodawanie(const char* number1, const char* number2, char** result, int dodac_minus)
{
	if (number1 == NULL || number2 == NULL || result == NULL || (dodac_minus != 1 && dodac_minus != 0)) return 1;
		const char* znak1 = number1;
		const char* znak2 = number2;
		for (; *(znak1 + 1) != '\0'; znak1++);  // ustawiamy wskazniki na ostatnie wyrazy (zaraz przed terminatorem)
		for (; *(znak2 + 1) != '\0'; znak2++);
		int len_number1=my_strlen(number1);
		int len_number2=my_strlen(number2);
		int max=len_number1;
		int flaga_1 = 0;
		int flaga_2 = 0;
		int bonus = 0;
		int rozmiar_result = 0;
		char *backup_result = *result;
		for (; max > 0; max--, len_number1--, len_number2--, znak1--, znak2--, (*result)++, rozmiar_result++)
		{
			if (len_number1 == 0) flaga_1 = 1;
			if (len_number2 == 0) flaga_2 = 1;
			int a = 0;
			int b = 0;
			if (flaga_1 == 0)
			{
				a = *znak1 - '0';
			}
			if (flaga_2 == 0)
			{
				b = *znak2 - '0';
			}
			int wynik = a + b + bonus;
			if (wynik >= 10)
			{
				bonus = 1;
				int reszta = wynik % 10;
				**result = reszta + '0';
			}
			else
			{
				bonus = 0;
				**result = wynik + '0';
			}
		}
		if (bonus == 1)
		{
			**result = '1';
			(*result)++;
			rozmiar_result++;
		}
		**result = '\0';
		*result = backup_result;
		int i, j;
		for (j = 0; j < rozmiar_result; j++)
		{
			for (i = 0; i < rozmiar_result - 1 - j; i++)
			{
				char temp = *(*result + 1);
				*(*result + 1) = **result;
				**result = temp;
				(*result)++;
			}
			*result = backup_result;
		}
	if (dodac_minus == 1)
	{
		int len = my_strlen(*result);
		int i = len;
		while (1)
		{
			if (i == 0)
			{
				**result = '-';
				*(*result + len + 1) = '\0';
				break;
			}
			*(*result + i) = *(*result + i - 1);
			i--;
		}
	}
	return 0;
}

int odejmowanie(const char* number1, const char* number2, char** result, int dodac_minus)
{
	if (number1 == NULL || number2 == NULL || result == NULL || (dodac_minus != 1 && dodac_minus != 0)) return 1;
	int len_1 = 0, len_2, size, a = 0, b = 0, flaga = 0;
	char *wsk = *result;
	while (1)
	{
		if (len_1 < 0) break;
		if (flaga == 0)
		{
			flaga = 1;
			len_1 = my_strlen(number1);
			len_2 = my_strlen(number2);
			size = len_1;
			len_2 -= 1;
		}
		else if (len_2 >= 0)
		{
			a = 10 - b;
			a -= *(number2 + len_2) - '0';
			a += -'0' + *(number1 + len_1);
			if (a <= 9) b = 1;
			else if (a > 9) b = 0;
			int liczba = a % 10;
			*(wsk + size) = liczba + '0';
			len_2--;
		}
		else
		{
			a = 10 - b;
			a += *(number1 + len_1) - '0';
			if (a <= 9) b = 1;
			else if (a > 9) b = 0;
			int liczba = a % 10;
			*(wsk + size) = liczba + '0';
		}
		len_1 -= 1;
		size -= 1;
	}
	int max = my_strlen(number1);
	*(wsk + max) = '\0';
	int zmienna = 0, wielkosc = my_strlen(wsk), ilosc = 0;
	for (; 1; zmienna++, ilosc++)
	{
		if (*(wsk + zmienna) != '0') break;
	}
	int i = 0;
	if (wielkosc > 1)
	{
		if (ilosc == 0);
		else
		{
			if (ilosc != wielkosc)
			{
				for (; 1; i++)
				{
					int liczba = i + ilosc - 1;
					if (*(wsk + liczba) == '\0') break;
					char *znak = (wsk + i);
					char *znak_backup = znak;
					znak += ilosc;
					*znak_backup = *znak;
				}
			}
			else *(wsk + 1) = '\0';
		}
	}
	if (dodac_minus == 1)
	{
		int len = my_strlen(wsk);
		int i = len;
		while (1)
		{
			if (i == 0)
			{
				*wsk = '-';
				*(wsk + len + 1) = '\0';
				break;
			}
			*(wsk + i) = *(wsk + i - 1);
			i--;
		}
	}
	return 0;
}

int subtract(const char* number1, const char* number2, char** result)
{
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	int g = validate(number1);
	if (g != 0) return 2;
	g = validate(number2);
	if (g != 0) return 2;
	int len_number1 = strlen(number1);
	int len_number2 = strlen(number2);
	g = compare_alokacja(number1, number2);
	//	int max;
	if (g == 2) return 1;
	if (g == 3) return 2;
	if (g == 0)// sa takie same
	{
		*result = (char *)realloc(NULL, len_number1 * sizeof(char) + 2);
		if (*result == NULL) return 3;
		//	max = len_number1;
	}
	if (g == -1)//number1 jest mniejsze od number2
	{
		int k=0;
		if(*number1=='-' && *(number1+1)=='1' && *number2=='9' && *(number2+1)=='9' && *(number2+2)=='9' && *(number2+3)=='9') k=1;
		*result = (char *)realloc(NULL, len_number2 * sizeof(char) + 2+k);
		if (*result == NULL) return 3;
		//	max = len_number2;
	}
	if (g == 1)//number1 jest wieksze od number2
	{
		*result = (char *)realloc(NULL, len_number1 * sizeof(char) + 2);
		if (*result == NULL) return 3;
		//	max = len_number1;
	}
	if (*number1 != '-' && *number2 != '-')
	{
		switch(g)
		{
			case 0:
				**result = '0';
				*(*result + 1) = '\0';
				break;
			case 1:
				odejmowanie(number1, number2, result, 0);
				break;
			case -1:
				odejmowanie(number2, number1, result, 1);
				break;
		}
	}
	else if(*number1 == '-' && *number2 == '-')
	{
		switch(g)
		{
			case 0:
				**result = '0';
				*(*result + 1) = '\0';
				break;
			case 1:
				odejmowanie(number1+1, number2+1, result, 1);
				break;
			case -1:
				odejmowanie(number2+1, number1+1, result, 0);
				break;
		}
	}
	else if(*number1 == '-' && *number2 != '-')
	{
		g=compare(number1+1,number2);
		switch(g)
		{
			case 0:
				dodawanie(number1+1,number2,result,1);
				break;
			case 1:
				dodawanie(number1+1,number2,result,1);
				break;
			case -1:
				dodawanie(number2, number1+1, result, 1);
				break;
		}
	}
	else if(*number1 != '-' && *number2 == '-')
	{
		g=compare(number1,number2+1);
		switch(g)
		{
			case 0:
				dodawanie(number1,number2+1,result,0);
				break;
			case 1:
				dodawanie(number1,number2+1,result,0);
				break;
			case -1:
				dodawanie(number2+1, number1, result, 0);
				break;
		}
	}
	return 0;
}



int add(const char* number1, const char* number2, char** result)
{
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	int g = validate(number1);
	if (g != 0) return 2;
	g = validate(number2);
	if (g != 0) return 2;
	int len_number1 = strlen(number1);
	int len_number2 = strlen(number2);
	g = compare_alokacja(number1, number2);
	int max;
	if (g == 2) return 1;
	if (g == 3) return 2;
	if (g == 0)// sa takie same
	{
		*result = (char *)realloc(NULL, len_number1 * sizeof(char) + 2);
		if (*result == NULL) return 3;
		max = len_number1;
	}
	if (g == -1)//number1 jest mniejsze od number2
	{
		*result = (char *)realloc(NULL, len_number2 * sizeof(char) + 2);
		if (*result == NULL) return 3;
		max = len_number2;
	}
	if (g == 1)//number1 jest wieksze od number2
	{
		*result = (char *)realloc(NULL, len_number1 * sizeof(char) + 2);
		if (*result == NULL) return 3;
		max = len_number1;
	}
	if (*number1 != '-' && *number2 != '-')
	{
		const char* znak1 = number1;
		const char* znak2 = number2;
		for (; *(znak1 + 1) != '\0'; znak1++);  // ustawiamy wskazniki na ostatnie wyrazy (zaraz przed terminatorem)
		for (; *(znak2 + 1) != '\0'; znak2++);
		int flaga_1 = 0;
		int flaga_2 = 0;
		int bonus = 0;
		int rozmiar_result = 0;
		char *backup_result = *result;
		for (; max > 0; max--, len_number1--, len_number2--, znak1--, znak2--, (*result)++, rozmiar_result++)
		{
			if (len_number1 == 0) flaga_1 = 1;
			if (len_number2 == 0) flaga_2 = 1;
			int a = 0;
			int b = 0;
			if (flaga_1 == 0)
			{
				a = *znak1 - '0';
			}
			if (flaga_2 == 0)
			{
				b = *znak2 - '0';
			}
			int wynik = a + b + bonus;
			if (wynik >= 10)
			{
				bonus = 1;
				int reszta = wynik % 10;
				**result = reszta + '0';
			}
			else
			{
				bonus = 0;
				**result = wynik + '0';
			}
		}
		if (bonus == 1)
		{
			**result = '1';
			(*result)++;
			rozmiar_result++;
		}
		**result = '\0';
		*result = backup_result;
		int i, j;
		for (j = 0; j < rozmiar_result; j++)
		{
			for (i = 0; i < rozmiar_result - 1 - j; i++)
			{
				char temp = *(*result + 1);
				*(*result + 1) = **result;
				**result = temp;
				(*result)++;
			}
			*result = backup_result;
		}
	}
	else if (*number1 == '-' && *number2 == '-')
	{

		const char* znak1 = number1;
		const char* znak2 = number2;
		for (; *(znak1 + 1) != '\0'; znak1++);  // ustawiamy wskazniki na ostatnie wyrazy (zaraz przed terminatorem)
		for (; *(znak2 + 1) != '\0'; znak2++);
		int flaga_1 = 0;
		int flaga_2 = 0;
		int bonus = 0;
		int rozmiar_result = 0;
		char *backup_result = *result;
		for (; max > 1; max--, len_number1--, len_number2--, znak1--, znak2--, (*result)++, rozmiar_result++)
		{
			if (len_number1 == 1) flaga_1 = 1;
			if (len_number2 == 1) flaga_2 = 1;
			int a = 0;
			int b = 0;
			if (flaga_1 == 0)
			{
				a = *znak1 - '0';
			}
			if (flaga_2 == 0)
			{
				b = *znak2 - '0';
			}
			int wynik = a + b + bonus;
			if (wynik >= 10)
			{
				bonus = 1;
				int reszta = wynik % 10;
				**result = reszta + '0';
			}
			else
			{
				bonus = 0;
				**result = wynik + '0';
			}
		}
		if (bonus == 0)
		{
			**result = '-';
			(*result)++;
			rozmiar_result++;
		}
		if (bonus == 1)
		{
			**result = '1';
			(*result)++;
			rozmiar_result++;
			**result = '-';
			(*result)++;
			rozmiar_result++;
		}
		**result = '\0';
		*result = backup_result;
		int i, j;
		for (j = 0; j < rozmiar_result; j++)
		{
			for (i = 0; i < rozmiar_result - 1 - j; i++)
			{
				char temp = *(*result + 1);
				*(*result + 1) = **result;
				**result = temp;
				(*result)++;
			}
			*result = backup_result;
		}
	}
	else if (*number1 != '-' && *number2 == '-')
	{
		int w = compare(number1, number2 + 1);
		switch (w)
		{
		case 1:
			odejmowanie(number1, number2 + 1, result, 0);
			break;
		case 0:
			**result = '0';
			*(*result + 1) = '\0';
			break;
		case -1:
			odejmowanie(number2 + 1, number1, result, 1);
			break;
		}
	}
	else if (*number1 == '-' && *number2 != '-')
	{
		int w = compare(number1 + 1, number2);
		switch (w)
		{
		case 1:
			odejmowanie(number1 + 1, number2, result, 1);
			break;
		case 0:
			**result = '0';
			*(*result + 1) = '\0';
			break;
		case -1:
			odejmowanie(number2, number1 + 1, result, 0);
			break;
		}
	}
	return 0;
}


int main()
{
	char *result;
	char *tab1=(char *)malloc(201*sizeof(char));
	if(tab1==NULL) return printf("Failed to allocate memory"),8;
	char *tab2=(char *)malloc(201*sizeof(char));
	if(tab2==NULL)
	{
		free(tab1);
		return printf("Failed to allocate memory"),8;
	} 
	printf("Podaj liczbe 1: ");
	scanf("%200s",tab1);
	int c=getchar();
	if(c!='\n') while(c!='\n') c=getchar();
	printf("Podaj liczbe 2: ");
	scanf("%200s",tab2);
	int g=add(tab1,tab2,&result);
	if(g==1 || g==2)
	{
		free(tab1);
		free(tab2);
		return printf("Incorrect input"),1;
	}
	if(g==3)
	{
		free(tab1);
		free(tab2);
		return printf("Failed to allocate memory"),8;
	}
	printf("%s\n", result);
	free(result);
	char *result2;
	g=subtract(tab1,tab2, &result2);
	if(g==1 || g==2)
	{
		free(tab1);
		free(tab2);
		return printf("Incorrect input"),1;
	}
	if(g==3)
	{
		free(tab1);
		free(tab2);
		return printf("Failed to allocate memory"),8;
	}
	printf("%s", result2);
	free(result2);
	free(tab1);
	free(tab2);
	return 0;
}
