#include <stdio.h>
#include <stdlib.h>

void display_vector(const int* tab, int size)
{
	if(tab==NULL || size<=0) return;
	int j;
	for(j=0;j<size;j++) printf("%d ",*(tab+j)); 
}
int *create_array_int(int N)
{
	if(N<=0) return NULL;
	int *ptr=(int *)realloc(NULL,N*sizeof(int));
	if(ptr==NULL) return NULL;
	return ptr;
}
int reverse(int* tab, int size)
{
	if(tab==NULL || size<=0) return 1;
	int i,j,*start=tab,*end=tab;
	for(j=0;j<size-1;j++,end++); 
	int rozmiar=size/2;
	for(i=0;i<rozmiar;i++)
	{
		int temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
  return 0;
}
int concatenate_arrays_int(int **a1, int size1, const int *a2, int size2)
{
	if(a1==NULL || a2==NULL || size1<=0 || size2<=0) return 1;
	int size_total=size1+size2,i;
	int *wsk=(int *)realloc(*a1,size_total*sizeof(int));
	if(wsk==NULL)
	{
		return 2;
	} 
	*(a1)=wsk;
	int *pointer1=*a1;
	for(i=0;i<size1;i++,pointer1++);
	int *pointer2=(int *)a2;
	for(;i<size_total;i++,pointer1++,pointer2++) *pointer1=*pointer2;
	return 0;
}

int main ()
{
	printf("Podaj rozmiar 1 tablicy: ");
	int liczba1,y;
	y=scanf("%d",&liczba1);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(liczba1<=0) return printf("Incorrect input data\n"),2;
	int *wsk1=create_array_int(liczba1);
	if(wsk1==NULL) return printf("Failed to allocate memory\n"),8;
	int i;
	printf("Podaj dane do 1 tablicy: ");
	for(i=0;i<liczba1;i++)
	{
		y=scanf("%d",(wsk1+i));
		if(y!=1)
		{
			free(wsk1);
			return printf("Incorrect input\n"),1;
		} 
	}
	int liczba2;
	printf("Podaj rozmiar 2 tablicy: ");
	y=scanf("%d",&liczba2);
	if(y!=1)
	{
		free(wsk1);
		return printf("Incorrect input\n"),1;
	} 
	if(liczba2<=0)
	{
		free(wsk1);
		return printf("Incorrect input data\n"),2;
	} 
	int *wsk2=create_array_int(liczba2);
	if(wsk2==NULL)
	{
		free(wsk1);
		return printf("Failed to allocate memory\n"),8;
	} 
	printf("Podaj dane do 2 tablicy: ");
	for(i=0;i<liczba2;i++)
	{
		y=scanf("%d",(wsk2+i));
		if(y!=1)
		{
			free(wsk1);
			free(wsk2);
			return printf("Incorrect input\n"),1;
		} 
	}
	int g=concatenate_arrays_int(&wsk1,liczba1,wsk2,liczba2);
	if(g==1)
	{
		free(wsk1);
		free(wsk2);
		return printf("Incorrect input\n"),1;
	} 
	if(g==2)
	{
		free(wsk1);
		free(wsk2);
		return printf("Failed to allocate memory\n"),8;
	} 
	reverse(wsk1,liczba1+liczba2);
	display_vector(wsk1,liczba1+liczba2);
	free(wsk1);
	free(wsk2);
	return 0;
}
