#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int **wsk=NULL;
	wsk = (int **)calloc(10,sizeof(int *));
	if(wsk==NULL) return printf("Failed to allocate memory\n"),8;
	int i,j,i1=1,j1=1;
	for(i=0;i<10;i++)
	{
		*(wsk + i) = (int *)calloc(10 ,sizeof(int));
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
			return printf("Failed to allocate memory\n"),8;
		}
	}
	for (i = 0,i1=1; i < 10; i++,i1++)
	{
		for (j = 0,j1=1; j < 10; j++,j1++)
		{
			int l1,l2;
			l1=i1;
			l2=j1;
			int liczba = l1*l2;
			*(*(wsk + i) + j) = liczba;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			int liczba = *(*(wsk + i) + j);
			if(liczba<10) printf(" %d  ",liczba);
			else if(j==8 && i==9) printf("%d ",liczba);
			else if(liczba==100) printf("%d",liczba);
			else
			{
				printf("%d",liczba);
				if(j!=9) printf("  ");
			} 
		}
		printf("\n");

	}
	for (i = 0; i < 10; i++) free(*(wsk + i));
	free(wsk);
	return 0;
}
