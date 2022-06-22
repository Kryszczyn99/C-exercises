#include <stdio.h>
#include <stdlib.h>

int* create_array_int(int N)
{
	if(N<=0) return NULL;
	int *ptr=(int *)malloc(N*sizeof(int));
	if(ptr==NULL) return NULL;
	return ptr;
}
int* copy_array_int(const int* ptr, int N)
{
	if(ptr==NULL || N<=0) return NULL;
	int *ptr2=(int *)malloc(N*sizeof(int));
	if(ptr2==NULL) return NULL;
	int i;
	for(i=0;i<N;i++)
	{
		*(ptr2+i)=*(ptr+i);
	}
	return ptr2;
}
void display_array_int(const int* ptr, int N)
{
	if(N<=0 || ptr==NULL) return;
	int i;
	for(i=0;i<N;i++)	printf("%d ",*(ptr+i));
	printf("\n");
}

int main ()
{
	printf("Podaj rozmiar tablicy: ");
	int size;
	int y=scanf("%d",&size);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(size<=0) return printf("Incorrect input data\n"),2;
	int zmienna;
	int *ptr=&zmienna;
	ptr=create_array_int(size);
	if(ptr==NULL) return printf("Failed to allocate memory\n"),8;
	int i;
	printf("Podaj dane: ");
	for(i=0;i<size;i++)
	{
		int z=scanf("%d",ptr+i);
		if(z!=1)
		{
			free(ptr);
			return printf("Incorrect input\n"),1;
		} 
	}
	int zmienna2;
	int *ptr2=&zmienna2;
	ptr2=copy_array_int(ptr,size);
	if(ptr2==NULL)
	{
		free(ptr);
		return printf("Failed to allocate memory"),8;
	} 
	
	display_array_int(ptr,size);
	display_array_int(ptr2,size);
	free(ptr2);
	free(ptr);
	return 0;
}
