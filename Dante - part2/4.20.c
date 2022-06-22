#include <stdio.h>


struct message_t
{
	char a;
	double b;
	int c;
};

int load_data(struct message_t *cp, int size, const char *filename);
int decode_message(const struct message_t *cp, int size, char *msg, int text_size);

int main()
{
	char tab[30];
	printf("Podaj plik: ");
	char *wsk = tab;
	for (int i = 0; i < 30; i++)
	{
		if (i == 30)
		{
			*wsk = '\0';
			break;
		}
		char znak;
		scanf("%c", &znak);
		if (znak == '\n')
		{
			*wsk = '\0';
			break;
		}
		*wsk = znak;
		wsk++;
	}
	struct message_t calosc[100]; //2400 bajtów // 1100 bajtów to wiadomosc ukryta
	int g = load_data(calosc, 100, tab);
	if (g == -1 || g == -3) return printf("File corrupted"), 6;
	if (g == -2) return printf("Couldn't open file"), 4;
	char wiadomosc[1101] = { 0 };
	int p = decode_message(calosc, g, wiadomosc, 1101);
	if (p == 1) return printf("File corrupted"), 6;
	printf("%s", wiadomosc);
	return 0;
}


int load_data(struct message_t *cp, int size, const char *filename)
{
	if (cp == NULL || size <= 0 || filename == NULL) return -1;
	FILE *f;
	f = fopen(filename, "rb");
	if (f == NULL) return -2;
	int wielkosc[1];
	int p=fread(wielkosc, sizeof(int), 1, f);
	if(p==0)
	{
		fclose(f);
		return -3;
	}
	if (*wielkosc > 2400) *wielkosc = 2400;
	if(*wielkosc<=0)
	{
		fclose(f);
		return -3;
	} 
	if(*(wielkosc)%24!=0)
	{
		fclose(f);
		return -3;
	} 
	int rozmiar = *wielkosc / 24;
	fread(cp, 24, rozmiar, f);
	fclose(f);
	return rozmiar;
}

int decode_message(const struct message_t *cp, int size, char *msg, int text_size)
{
	if (cp == NULL || size <= 0 || msg == NULL || text_size <= 0) return 1;
	if(text_size==1)
	{
		*msg='\0';
		return 0;
	}
	int flaga=0;
	int pobrane=0;
	int i = 0;
	while (i < size)
	{
		char *ptr = (char *)cp;
		ptr += 1; // usuwa znak char
		if(flaga==0)
		{
			for (int j = 0; j < 7; j++, ptr++, msg++)
			{
				*msg = *ptr;
				pobrane+=1;
				if(pobrane==text_size)
				{
					flaga=1;
					break;
				}
			} 
		}
		
		ptr += 12; // przesuwa o double i int
		if(flaga==0)
		{
			for (int j = 0; j < 4; j++, ptr++, msg++)
			{
				*msg=*ptr;
				pobrane+=1;
				if(pobrane==text_size)
				{
					flaga=1;
					break;
				}
			}
		}
		if(flaga==1) break;
		i++;
		cp++;
	}
	*msg = '\0';
	return 0;
}


