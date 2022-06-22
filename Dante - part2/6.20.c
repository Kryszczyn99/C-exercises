#include <stdio.h>
#include <stdlib.h>

int create_array_2d_2(int ***ptr, int width, int height)
{
	if(ptr==NULL || width<=0 || height<=0) return 1;
	*ptr=(int **)calloc(height,sizeof(int *));
	if(*ptr==NULL) return 2;
	int i;
	for (i = 0; i < height; i++)
	{
		*(*ptr + i) = (int *)calloc(width ,sizeof(int));
		if(*(*ptr+i)==NULL)
		{
			i-=1; //by wrocic na poprzedni wskaznik bo ten bylby null
			while(i>=0)
			{
				free(*(*ptr+i));
				i--;
			}
			free(*ptr);
			return 2;
		} 
	}
	
	return 0;
}
void destroy_array_2d(int ***ptr, int height)
{
	if(ptr==NULL || height<=0) return;
	int i;
	for (i = 0; i < height; i++) free(*(*ptr + i));
	free(*ptr);
	*ptr=NULL;
}
int sum_array_2d(int **ptr, int width, int height)
{
	if(ptr==NULL || width<=0 || height<=0) return -1;
	int **wsk = ptr;
	int i, j,sum=0;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			sum+=*(*(wsk + i) + j);
		}
	}
	return sum;
}
int sum_row(int *ptr, int width)
{
	if(ptr==NULL || width<=0) return -1;
	int i,sum=0;
	for(i=0;i<width;i++)
	{
		sum+=*(ptr+i);
	}
	return sum;
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

int main ()
{
	printf("Podaj szerekosc i wysokosc: ");
	int height, width;
	int y = scanf("%d %d", &width, &height);
	if (y != 2) return printf("Incorrect input\n"), 1;
	if (width <= 0 || height <= 0) return printf("Incorrect input data\n"), 2;
	int **wsk;
	int g=create_array_2d_2(&wsk,width,height);
	if (g == 1)
	{
		return printf("Incorrect input\n"), 1;
	} 
	if (g == 2)
	{
		return printf("Failed to allocate memory\n"), 8;
	} 
	int i, j;
	printf("Podaj dane: ");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int liczba;
			int y = scanf("%d", &liczba);
			if(y!=1)
			{
				destroy_array_2d(&wsk,height);
				return printf("Incorrect input\n"), 1;
			}
			*(*(wsk + i) + j) = liczba;
		}

	}
	display_array_2d(wsk,width,height);
	for(i=0;i<height;i++)
	{
		g=sum_row(*(wsk+i),width);
		if (g == -1)
		{
			destroy_array_2d(&wsk,height);
			return printf("Incorrect input\n"), 1;
		} 
		printf("%d\n",g);
	}
	g=sum_array_2d(wsk,width,height);
	if (g == -1)
	{
		destroy_array_2d(&wsk,height);
		return printf("Incorrect input\n"), 1;
	} 
	printf("%d\n",g);
	destroy_array_2d(&wsk,height);
	return 0;
}
