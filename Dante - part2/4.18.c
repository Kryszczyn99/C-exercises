#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct file_t
{
	FILE *f;
	int size;
};
int open_file(struct file_t* f, const char *filename);
struct file_t* find_min(const struct file_t* files, int size);
int file_size_from_file(FILE *f);
void close_file(struct file_t* f);
/****************************************/
int main()
{
	struct file_t jeden;
	struct file_t dwa;
	struct file_t trzy;
	struct file_t cztery;
	struct file_t piec;
	printf("Podaj nazwy plikow: \n");
	int k = 1;
	while (1)
	{
		char tab[30] = { 0 };
		fgets(tab, 30, stdin);
		char *wsk = tab;
		if (*wsk == '\n');
		else
		{
			for (; *(wsk + 1) != '\0'; wsk++);
			*wsk = '\0';
		}
		wsk = tab;
		int wielkosc = 0;
		if (*wsk == '\n') break;
		wielkosc++;
		wsk++;
		if (k == 1)
		{
			int b = open_file(&jeden, tab);
			if (b == 1 || b == 2);
			else k += 1;
		}
		else if (k == 2)
		{
			int b = open_file(&dwa, tab);
			if (b == 1 || b == 2);
			else k += 1;
		}
		else if (k == 3)
		{
			int b = open_file(&trzy, tab);
			if (b == 1 || b == 2);
			else k += 1;
		}
		else if (k == 4)
		{
			int b = open_file(&cztery, tab);
			if (b == 1 || b == 2);
			else k += 1;
		}
		else if (k == 5)
		{
			int b = open_file(&piec, tab);
			if (b == 1 || b == 2);
			else k += 1;
		}
	}
	if (k == 1) return printf("Couldn't open file"), 4;
	printf("Podaj tekst: \n");
	struct file_t tabl[5] = {jeden,dwa,trzy,cztery,piec};
	while (1)
	{

		char tab2[1000] = { 0 };
		fgets(tab2, 1000, stdin);
		char *wsk = tab2;
		if (*wsk == '\n') break;
		struct file_t *result;
		result = find_min(tabl, k - 1);
		if (result == NULL) break;
		int len = strlen(tab2);
		fwrite(tab2,sizeof(char),len,(result->f));
	}
	close_file(&jeden);
	close_file(&dwa);
	close_file(&trzy);
	close_file(&cztery);
	close_file(&piec);
	printf("Files saved");
	return 0;
}

/***************************************/
void close_file(struct file_t* f)
{
	if (f == NULL) return;
	if ((f->f) == NULL) return;
	fclose(f->f);
}
/***************************************/
int open_file(struct file_t* f, const char *filename)
{
	if (f == NULL) return 1;
	if (filename == NULL) return 1;
	FILE *plik;
	plik = fopen(filename, "a");
	if (plik == NULL)
	{
		plik = fopen(filename, "w");
		if (plik == NULL) return 2;
	}
	int wielkosc = file_size_from_file(plik);
	(f->f) = plik;
	(f->size) = wielkosc;
	return 0;
}
/********************************************/
int file_size_from_file(FILE *f)
{
	if (f == NULL) return -2;
	int backup = ftell(f);
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, backup, SEEK_SET);
	return size;
}

/********************************************/
struct file_t* find_min(const struct file_t* files, int size)
{
	if (files == NULL || size <= 0) return NULL;
	int i = 0;
	int min = 0;
	const struct file_t* wynik=files;
	while (i < size)
	{
		int wielkosc = file_size_from_file((files + i)->f);
		if (min > wielkosc)
		{
			min = wielkosc;
			wynik = (files + i);
		}
		else if (min == 0 && i == 0) min = wielkosc;
		i++;
	}
	return (struct file_t*) wynik;
}


