#include <stdio.h>
#include <stdlib.h>


struct matrix_t {
	int **ptr;
	int width;
	int height;
};

struct matrix_t* matrix_create_struct(int width, int height)
{
	
}

void matrix_destroy_struct(struct matrix_t **m);

struct matrix_t* matrix_transpose(const struct matrix_t *m);

int matrix_save_b(const struct matrix_t *m, const char *filename);
int matrix_save_t(const struct matrix_t *m, const char *filename);

int matrix_create(struct matrix_t *m, int width, int height)
{
	if (m == NULL || width <= 0 || height <= 0) return 1;
	m->width = width;
	m->height = height;
	int **wsk=NULL;
	wsk = (int **)calloc(height,sizeof(int *));
	if(wsk==NULL) return 2;
	m->ptr = wsk;
	int i;
	for (i = 0; i < height; i++)
	{
		*(wsk + i) = (int *)calloc(width ,sizeof(int));
		if(*(wsk+i)==NULL)
		{
			i-=1; //by wrocic na poprzedni wskaznik bo ten bylby null
			while(i>=0)
			{
				free(*(wsk+i));
				i--;
			}
			free(wsk);
			wsk=NULL;
			return 2;
		} 
	}
	
	return 0;
}
int matrix_read(struct matrix_t *m)
{
	if (m == NULL || m->height <= 0 || m->width <= 0 || m->ptr == NULL) return 1;
	printf("Podaj dane: \n");
	int **pointer = m->ptr;
	int i, j;
	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			int liczba;
			int y = scanf("%d", &liczba);
			if(y!=1) return 2;
			*(*(pointer + i) + j) = liczba;
		}

	}
	return 0;
}
void matrix_display(const struct matrix_t *m)
{

	if (m == NULL || m->ptr == NULL || m->width <= 0 || m->height <= 0) return;
	int **wsk = (m->ptr);
	int i, j;
	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			printf("%d ", *(*(wsk + i) + j));
		}
		printf("\n");
	}
}
void matrix_destroy(struct matrix_t *m)
{
	if (m == NULL || m->ptr == NULL) return;
	int **wsk = (m->ptr);
	int i;
	for (i = 0; i < m->height; i++) free(*(wsk + i));
	free(wsk);
}

int main()
{
	printf("Podaj szerekosc i wysokosc: ");
	int height, width;
	int y = scanf("%d %d", &width, &height);
	if (y != 2) return printf("Incorrect input\n"), 1;
	if (width <= 0 || height <= 0) return printf("Incorrect input data\n"), 2;
	struct matrix_t macierz;
	int g = matrix_create(&macierz, width, height);
	if (g == 1)
	{
		return printf("Incorrect input\n"), 1;
	} 
	if (g == 2)
	{
		return printf("Failed to allocate memory\n"), 8;
	} 
	g = matrix_read(&macierz);
	if (g == 1 || g == 2)
	{
		matrix_destroy(&macierz);
		return printf("Incorrect input\n"), 1;
	} 
	matrix_display(&macierz);
	matrix_destroy(&macierz);
	return 0;
}
