#include <stdio.h>
#include <stdlib.h>

int **create_array_2d(int width, int height)
{
	if(width<=0 || height<=0) return NULL;
	int **wsk=(int **)calloc(height,sizeof(int *));
	if(wsk==NULL) return NULL;
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
			return NULL;
		} 
	}
	
	return wsk;
}
void display_array_2d(int **ptr, int width, int height)
{
	if(ptr==NULL || width<=0 || height<=0) return;
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%d ", *(*(ptr + i) + j));
		}
		printf("\n");
	}
}
void destroy_array_2d(int **ptr, int height)
{
	if(ptr==NULL || height <=0) return;
	int i;
	for (i = 0; i < height; i++) free(*(ptr + i));
	free(ptr);
}

int main ()
{
	int height, width;
	printf("Podaj szerokosc i dlugosc: ");
	int y = scanf("%d %d", &width, &height);
	if (y != 2) return printf("Incorrect input\n"), 1;
	if (width <= 0 || height <= 0) return printf("Incorrect input data\n"), 2;
	int **wsk=create_array_2d(width,height);
	if(wsk==NULL) return printf("Failed to allocate memory\n"), 8;
	printf("Podaj dane: \n");
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int liczba;
			int y = scanf("%d", &liczba);
			if(y!=1)
			{
				destroy_array_2d(wsk,height);
				return printf("Incorrect input\n"), 1;
			}
			*(*(wsk + i) + j) = liczba;
		}

	}
	display_array_2d(wsk,width,height);
	destroy_array_2d(wsk,height);
	return 0;
}
