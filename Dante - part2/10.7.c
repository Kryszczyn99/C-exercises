#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
struct point_t
{
	int x;
	int y;
};

int my_printf(char* text, ...)
{
	if (text == NULL) return 0;
	va_list ap;
	va_start(ap, text);
	int i = 0;
	int ilosc = 0;
	int flaga = 0;
	while (1)
	{
		if (*(text + i) == '\0')
		{
			va_end(ap);
			break;
		}
		if (*(text + i) != '%') flaga = 1;
		else
		{
			char znak = *(text + i + 1);
			if (znak == 'p')
			{
				struct point_t wsk = va_arg(ap, struct point_t);
				ilosc += 1;
				putchar('(');
				int liczba = wsk.x;
				int l_op;
				if (liczba < 0) l_op = -1;
				else if (liczba == 0) l_op = 0;
				else l_op = 1;
				switch (l_op)
				{
				case 1:
				{
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}
				case 0:
				{
					ilosc += 1;
					putchar('0');
					break;
				}
				case -1:
				{
					putchar('-');
					ilosc += 1;
					liczba = liczba * (-1);
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}

				}
				//koniec drukowania x
				ilosc += 1;
				putchar(' ');
				liczba = wsk.y;
				if (liczba < 0) l_op = -1;
				else if (liczba == 0) l_op = 0;
				else l_op = 1;
				switch (l_op)
				{
				case 1:
				{
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}
				case 0:
				{
					ilosc += 1;
					putchar('0');
					break;
				}
				case -1:
				{
					putchar('-');
					ilosc += 1;
					liczba = liczba * (-1);
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}

				}
				//koniec drukowania y
				ilosc += 1;
				putchar(')');

			}
			else if (znak == 'f')
			{
				//zapisac przed i po kropce w float dwie liczby typu int
				//drukowac je po sobie, pomiedzy nimi kropke dac
				double number = va_arg(ap, double);
				if (number == 0)
				{
					putchar('0');
					putchar('.');
					putchar('0');
					putchar('0');
					putchar('0');
					putchar('0');
					putchar('0');
					putchar('0');
					ilosc = 7;

				}
				else
				{
					int liczba1 = (int)number;
					number = number - (double)liczba1;
					//teraz mamy 0.xxxxxx
					//musimy policzyc dlugosc liczby
					int minus = 0;
					if (number < 0) minus = 1;
					int liczba = liczba1;
					int l_op;
					if (liczba < 0) l_op = -1;
					else if (liczba == 0) l_op = 0;
					else l_op = 1;
					switch (l_op)
					{
					case 1:
					{
						while (1)
						{
							if (liczba == 0) break;
							int backup = liczba;
							int b;
							int powrot;
							int rozmiar = 0;
							int ilosc_zer = 0;
							while (1)
							{
								b = backup % 10;
								backup = backup - b;
								if (b == 0)
								{
									powrot = backup;
									ilosc_zer += 1;
									backup = backup / 10;
									while (1)
									{
										b = backup % 10;
										backup = backup - b;
										if (b != 0)
										{
											break;
										}
										ilosc_zer += 1;
										backup = backup / 10;
									}
									if (backup == 0) break;
									backup = backup / 10;
									ilosc_zer = 0;
									backup = powrot;

								}
								if (backup == 0) break;
								backup = backup / 10;
								rozmiar += 1;
							}
							putchar('0' + b);
							int l = 0;
							for (; l < ilosc_zer; l++, ilosc++) putchar('0');
							int reszta = 1;
							int p = 0;
							rozmiar = rozmiar + ilosc_zer;
							while (1)
							{
								if (p == rozmiar) break;
								reszta *= 10;
								p++;
							}
							liczba = liczba - (reszta*b);
							ilosc++;
						}
						break;
					}
					case 0:
					{
						ilosc += 1;
						putchar('0');
						break;
					}
					case -1:
					{
						putchar('-');
						ilosc += 1;
						liczba = liczba * (-1);
						while (1)
						{
							if (liczba == 0) break;
							int backup = liczba;
							int b;
							int powrot;
							int rozmiar = 0;
							int ilosc_zer = 0;
							while (1)
							{
								b = backup % 10;
								backup = backup - b;
								if (b == 0)
								{
									powrot = backup;
									ilosc_zer += 1;
									backup = backup / 10;
									while (1)
									{
										b = backup % 10;
										backup = backup - b;
										if (b != 0)
										{
											break;
										}
										ilosc_zer += 1;
										backup = backup / 10;
									}
									if (backup == 0) break;
									backup = backup / 10;
									ilosc_zer = 0;
									backup = powrot;

								}
								if (backup == 0) break;
								backup = backup / 10;
								rozmiar += 1;
							}
							putchar('0' + b);
							int l = 0;
							for (; l < ilosc_zer; l++, ilosc++) putchar('0');
							int reszta = 1;
							int p = 0;
							rozmiar = rozmiar + ilosc_zer;
							while (1)
							{
								if (p == rozmiar) break;
								reszta *= 10;
								p++;
							}
							liczba = liczba - (reszta*b);
							ilosc++;
						}
						break;
					}

					}
					//nowa liczba
					putchar('.');
					ilosc += 1;
					if (minus == 1) number *= (-1);
					int o=0;
					for(;o<=4;o++)
					{
						number*=10;
						int w=(int)number%10;
						char znak='0'+w;
						putchar(znak);
						ilosc++;
					}
				}
			}
			else if (znak == 'd')
			{
				int liczba = va_arg(ap, int);
				int l_op;
				if (liczba < 0) l_op = -1;
				else if (liczba == 0) l_op = 0;
				else l_op = 1;
				switch (l_op)
				{
				case 1:
				{
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}
				case 0:
				{
					ilosc += 1;
					putchar('0');
					break;
				}
				case -1:
				{
					putchar('-');
					ilosc += 1;
					liczba = liczba * (-1);
					while (1)
					{
						if (liczba == 0) break;
						int backup = liczba;
						int b;
						int powrot;
						int rozmiar = 0;
						int ilosc_zer = 0;
						while (1)
						{
							b = backup % 10;
							backup = backup - b;
							if (b == 0)
							{
								powrot = backup;
								ilosc_zer += 1;
								backup = backup / 10;
								while (1)
								{
									b = backup % 10;
									backup = backup - b;
									if (b != 0)
									{
										break;
									}
									ilosc_zer += 1;
									backup = backup / 10;
								}
								if (backup == 0) break;
								backup = backup / 10;
								ilosc_zer = 0;
								backup = powrot;

							}
							if (backup == 0) break;
							backup = backup / 10;
							rozmiar += 1;
						}
						putchar('0' + b);
						int l = 0;
						for (; l < ilosc_zer; l++, ilosc++) putchar('0');
						int reszta = 1;
						int p = 0;
						rozmiar = rozmiar + ilosc_zer;
						while (1)
						{
							if (p == rozmiar) break;
							reszta *= 10;
							p++;
						}
						liczba = liczba - (reszta*b);
						ilosc++;
					}
					break;
				}

				}
			}
			else if (znak == 's')
			{
				char *tab = va_arg(ap, char *);
				int j = 0;
				while (1)
				{
					if (*(tab + j) == '\0') break;
					if (*(tab + j) != '\0')
					{
						char znak = *(tab + j);
						ilosc += 1;
						putchar(znak);
					}
					j++;
				}
			}
			i += 1;
		}
		if (flaga == 1)
		{
			char znak = *(text + i);
			putchar(znak);
			ilosc += 1;
			flaga=0;
		}
		i++;
	}
	return ilosc;
}

int my_scanf(char* text, ...)
{
	int i = 0;
	if (text == NULL) return 0;
	va_list ap;
	int walidacja = 0;
	int ilosc = 0;
	va_start(ap, text);
	while (1)
	{
		if (*(text + i) == '\0')
		{
			va_end(ap);
			break;
		}
		if (*(text + i) == '%')
		{
			char znak = *(text + i + 1);
			switch (znak)
			{
			case 'd':
			{
				int* number;
				number = va_arg(ap, int*);
				*number = 0;
				char c;
				int minus = 0;
				while (1)
				{
					c = getchar();
					if (c == ' ') continue;
					else if (c == '\n') continue;
					else if (c == '\t') continue;
					else if (c == '-')
					{
						minus = 1;
						break;
					}
					else
					{
						ungetc(c, stdin);
						break;
					}
				}
				int czy_liczba_byla = 0;
				while (1)
				{
					c = getchar();
					if (isalpha(c) && czy_liczba_byla == 0) walidacja = 1;
					if (isdigit(c) == 0)
					{
						if (minus == 1) *number *= -1;
						break;
					}
					else
					{
						*number *= 10;
						int liczba = c;
						liczba = liczba - '0';
						*number += liczba;
						czy_liczba_byla = 1;
					}

				}
				if (walidacja == 0)
				{
					ilosc++;
				}
				walidacja = 0;
				break;
			}
			case 'f':
			{
				double* number;
				number = va_arg(ap, double*);
				*number = 0;
				char znak;
				int minus = 0;
				//przewijanie bialych znakow
				while (1)
				{
					znak = getchar();
					if (znak == ' ') continue;
					else if (znak == '\n') continue;
					else if (znak == '\t') continue;
					else if (znak == '-')
					{
						minus = 1;
						break;
					}
					else
					{
						ungetc(znak, stdin);
						break;
					}
				}
				//przed kropka
				int flaga = 0;
				int litera = 0;
				int czy_liczba_byla = 0;
				while (1)
				{
					znak = getchar();
					if (znak == '.') break;
					if (znak == '\n')
					{
						flaga = 1;
						break;
					}
					if (isalpha(znak))
					{
						litera = 1;
						break;
					}
					int liczba = znak;
					liczba -= '0';
					*number *= 10;
					*number += liczba;
					czy_liczba_byla = 1;
				}
				if (flaga == 1)
				{
					flaga = 0;
					ilosc += 1;
					i++;
					continue;
				}
				if (litera == 1)
				{
					if(czy_liczba_byla==1) ilosc += 1;
					i++;
					continue;
				}
				int p = 1;
				//po kropce
				while (1)
				{
					znak = getchar();
					if (isdigit(znak))
					{
						int y = 0;
						double potega = 1;
						for (; y < p; y++) potega *= 10;
						p += 1;
						double liczba = znak;
						liczba -= '0';
						*number += liczba / potega;
					}
					else
					{
						if (minus == 1)	*number *= -1;
						break;
					}
				}
				ilosc++;
				break;
			}
			case 'p':
			{
				struct point_t* p;
				p = va_arg(ap, struct point_t*);
				char znak;
				while (1)
				{
					znak = getchar();
					if (znak == ' ') continue;
					else if (znak == '\n') continue;
					else if (znak == '\t') continue;
					else break;
				}
				int number = 0;
				int minus = 0;
				while (1)
				{
					znak = getchar();
					if (znak == '-') minus = 1;
					else if (isdigit(znak) == 0)
					{
						if (minus == 1) number *= -1;
						minus = 0;
						p->x = number;
						break;
					}
					else
					{
						int liczba = znak;
						liczba -= '0';
						number *= 10;
						number += liczba;
					}
				}
				if(znak==',')
				{
					i++;
					continue;
				}
				int number_2 = 0;
				while (1)
				{
					znak = getchar();
					if (znak == '-') minus = 1;
					else if (isdigit(znak) == 0)
					{
						if (minus == 1) number_2 *= -1;
						minus = 0;
						p->y = number_2;
						number_2 = 0;
						break;
					}
					else
					{
						int liczba = znak;
						liczba -= '0';
						number_2 *= 10;
						number_2 += liczba;
					}
				}
				ilosc += 2;
				break;
			}
			default:
			{
				i += 1;
				break;
			}
			}
		}
		i++;
	}
	return ilosc;
}


int main()
{

}

