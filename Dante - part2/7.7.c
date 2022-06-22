#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int warunek_1(const char *expr)//pierwszy znak nie jest liczba ani minusem
{
	int flaga=0;
	if(*expr>='0' && *expr<='9') flaga=1;
	int minus=0;
	if(*expr=='-') minus=1;
	if(flaga==0 && minus==0) return 1;
	return 0;
}
int warunek_2(const char *expr)//pierwszy znak to minus przy dlugosci wiekszej od 1 ale drugi znak to nie liczba
{
	int i=0;
	while(1)
	{
		if(*(expr+i)=='\0') break;
		i++;
	}
	if(1<i)
	{
		int minus=0;
		if(*expr=='-') minus=1;
		if(minus==1);
		else
		{
			int flaga=0;
			if(*expr>='0' && *expr<='9') flaga=1;
			if(flaga==0) return 1;		
		}
	}
	return 0;
}
int warunek_3(const char *expr)
{
	int i=0;
	while(1)
	{
		if(*(expr+i)=='\0') break;
		i++;
	}
	int len=i;
	i=0;
	while(1)
	{
		if(len==i) break;
		int flaga=0;
		if(*(expr+i)=='*' || *(expr+i)=='+' || *(expr+i)=='-') flaga=1;
		switch(flaga)
		{
			case 1:
				{
					char znak=*(expr+i+1);
					int liczba=0;
					if(znak>='0' && znak<='9') liczba=1;
					int minus=0;
					if(znak=='-') minus=1;
					if(liczba==0 && minus==0) return 1;
					break;
				}
			case 0:
				{
					char znak=*(expr+i);
					int liczba=0;
					if(znak>='0' && znak<='9') liczba=1;
					if(liczba==0) return 1;
					break;
				}
		}
		i++;
	}
	return 0;
}
int validate_expression(const char *expr)
{
	if(expr==NULL) return 2;
	if(warunek_1(expr)) return 1;
	if(warunek_2(expr)) return 1;
	if(warunek_3(expr)) return 1;
	return 0;
}


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
int warunki_multiply(const char* number1,const char* number2,char** result)
{
	if(number1==NULL) return 1;
	if(number2==NULL) return 1;
	if(result==NULL) return 1;
	int y=validate(number1);
	if(y!=0) return 2;
	y=validate(number2);
	if(y!=0) return 2;
	return 0;	
}
int jedno_zero(const char* number1,const char* number2,char** result)
{
	char z='0';
	int flaga=0;
	if(*number1==z) flaga=1;
	if(*number2==z) flaga=1;
	if(flaga==1)
	{
		**result=z;
		*(*result+1)='\0';
		return 1;
	}
	return 0;
}
int mn_help(char *num_2,char **result,int X,int Y,int *n,int j,int n1)
{
	int n2=0;
	char zn=*(num_2+j);
	if(zn=='\0');
	else n2=zn-'0';
	int zmienna=X+Y; 
	zn=*(*result+zmienna);
	int pop=0;
	if(zn=='\0');
	else pop=zn-'0';
	int suma=n1*n2+pop+*n; 
   	*n=suma/10;
   	int pod=suma%10;
   	char znak=pod+'0';
   	zmienna=X+Y;
	*(*result+zmienna)=znak; 
	return 0;
}
int multiply(const char* number1,const char* number2,char** result)
{
	int y=warunki_multiply(number1,number2,result);
	if(y!=0) return y;
	int flaga_minus=0;
	int m1=0;
	int m2=0;
	if(*number1=='-') m1=1;
	if(*number2=='-') m2=1;
	if(m1==1 && m2==0) flaga_minus=1;
	else if(m1==0 && m2==1) flaga_minus=1;
	int i=0;
	while(1)
	{
		if(*(number1+i)=='\0') break;
		i++;
	}
	int len_1=i;
	i=0;
	while(1)
	{
		if(*(number2+i)=='\0') break;
		i++;
	}
	int len_2=i;
	i=0;
	int rozmiar=len_1+len_2;
	rozmiar+=1;//terminator dla number1
	rozmiar+=1;//terminator dla number2
	*result=(char*)calloc(1,rozmiar);
	if(*result==NULL) return 3;
	y=jedno_zero(number1,number2,result);
	if(y!=0) return 0;
	if(m1==1) len_1-=1;
	if(m2==1) len_2-=1;
	char *num_1=(char*)number1;
	char *num_2=(char*)number2;
	if(m1==1) num_1+=1;
	if(m2==1) num_2+=1;
	int X=0,Y=0;
	i=-1;
	i+=len_1;
	**result='0';
	i=-1;
	i+=len_1;
	int j=0;
	while(1)
	{
		if(i==-1) break;
		j=-1;
		j+=len_2;
		int n=0;
		char zn=*(num_1+i);
		int n1=0;
		if(zn=='\0');
		else n1=zn-'0'; 
		Y=0;  
		while(1)
		{
			if(j==-1) break;
			mn_help(num_2,result,X,Y,&n,j,n1);
			Y++; 
			j--;
		}
		if(n<=0)
		{
			X+=1;
			i-=1;
		}
		else
		{
			char znak=n+'0';
			int zmienna=X+Y;
			*(*result+zmienna)=znak;			
			X+=1;
			i-=1;
		}
	}
	i=0;
	char *wsk=*result;
	while(1)
	{
		if(*(wsk+i)=='\0') break;
		i++;
	}
	int lenik=i;
	char mn='-';
	switch(flaga_minus)
	{
		case 1:
			{
				*(*result+lenik)=mn;
				lenik+=1;
				*(*result+lenik)='\0';
				break;
			}
		case 0:
			{
				*(*result+lenik)='\0';
				break;
			}
	}
	char *ptr=*result;
	i=0;
	while(1)
	{
		if(*(ptr+i)=='\0') break;
		i++;
	}
	lenik=i;
	i=0;
	while(1)
	{
		if(i==lenik) break;
		j=0;
		while(1)
		{
			if(j==lenik-i-1) break;
			char znak_1=*(ptr+j);
			char znak_2=*(ptr+j+1);
			*(ptr+j)=znak_2;
			*(ptr+j+1)=znak_1;
			j++;
		}
		i++;
	}
	return 0;
}
int warunki_calculate(const char* expr,char** result)
{
	if(expr==NULL) return 1;
	if(result==NULL) return 1;
	if(validate_expression(expr)) return 2;
	return 0;
}
char * my_strpbrk ( const char * tab1, const char * tab2)
{
    for(;*tab1;tab1++)
    {
        const char *wsk1,*wsk2;
        wsk1=tab1;
        for(wsk2=tab2; *wsk2; wsk2++)
        {
            if (*wsk1!=*wsk2) continue;
            return  (char*) wsk1;
        }        
    }
    return NULL;
}
char *my_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while (*(src+i))
    {
        *(dest+i) = *(src+i);
        i++;
    }
    *(dest+i)='\0';
    return dest;
}
int funkcja_1(const char* expr, char **result)
{
    int j=0;
    while(1)
    {
    	if(*(expr+j)=='\0') break;
    	j++;
	}
    my_strcpy((char*)*result,(char*)expr);
    *(*result+j) = '\0';   
	return 0;	
}
int funkcja_2(const char* expr,char **result,char *znaczek,char *znak,int *prev)
{
	int dlugosc=znak-expr;
	dlugosc+=1;
    char* l=(char*)calloc(1,dlugosc);
    strncpy(l,expr,dlugosc-1);
    *(l+dlugosc-1)='\0';
    my_strcpy((char*)*result,l);
    free(l); 
    *(*result+dlugosc-1)='\0';
    (*prev)=dlugosc;
    *znaczek=*znak;
    return 0;
}
int pm(char **result, char* nowy)
{
	free(*result);
    *result = nowy;
    return 0;
}
int calculate(const char* expr, char **result)
{
	char z1='-';
	char z2='+';
	char z3='*';
    int prev=0;
    char znaczek;
    const char* tab="-*+";
    int y=warunki_calculate(expr,result);
    if(y!=0) return y;
    int i=0;
    while(1)
    {
        if(*(expr+i)=='\0') break;
        i++;
    }
    int len_expr=i;
    len_expr+=1;//terminator
    *result=(char*)calloc(1,len_expr);
    if(*result==NULL) return 3;
    char* znak=my_strpbrk(expr+1,tab);
    if(znak==NULL) funkcja_1(expr,result);
    if(znak!=NULL) funkcja_2(expr,result,&znaczek,znak,&prev);
    char m='-';
    while(znak)
    {
        char z=*(znak+1);
        if(z==m) znak=strpbrk(znak+2,tab);
        if(z!=m) znak=strpbrk(znak+1,tab);
        char* l;
        if(znak==NULL)
        {
        	int backup=prev;
        	const char* temp=expr+backup;
        	i=0;
        	while(1)
        	{
        		if(*(temp+i)=='\0') break;
        		i++;
			}
            int dlugosc=i;
            dlugosc+=1;
            prev+=dlugosc;
            l=(char*)calloc(1,dlugosc);
            strncpy(l,expr+backup,dlugosc-1);
            *(l+dlugosc-1)='\0';
        }
        if(znak!=NULL)
        {
        	int backup=prev;
            int dlugosc=znak-expr;
            dlugosc-=backup;
            dlugosc+=1;
            prev+=dlugosc;
            l=(char*)calloc(1,dlugosc);
            strncpy(l,expr+backup,dlugosc-1);
            *(l+dlugosc-1)='\0';
             
        }
        char* nowy;
        if(znaczek==z2) add(*result,l,&nowy);
        if(znaczek==z1) subtract(*result,l,&nowy);
        if(znaczek==z3) multiply(*result,l,&nowy);
        free(l);
        if(*nowy=='\0');
        else pm(result,nowy);
        if(znak==NULL) continue;
        else
        {
            char g=*znak;
            znaczek=g;
        }
    }
    return 0;
}

int main()
{
	int size=501;
	char *wsk=(char*)calloc(1,size);
	if(wsk==NULL) return printf("Failed to allocate memory"),8;
	printf("Podaj rownanie: ");
	int i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(wsk+i)='\0';
			break;
		}
		if(i<=500)
		{
			*(wsk+i)=znak;
			i++;
		}
	}
	int y=validate_expression(wsk);
	if(y!=0)
	{
		free(wsk);
		return printf("Incorrect input"),1;
	}
	char *result;
	y=calculate(wsk,&result);
	switch(y)
	{
		case 3:
			{
				free(wsk);
				return printf("Failed to allocate memory"),8;
			}
		default:
			{
				i=0;
				while(1)
				{
					char zn=*(result+i);
					if(zn=='\0') break;
					printf("%c",zn);
					i++;
				}
				free(wsk);
				free(result);
				return 0;
			}
	}
	return 0;
}
