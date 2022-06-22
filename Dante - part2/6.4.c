#include <stdio.h>
#include <stdlib.h>

int create_array_int(int **ptr, int N)
{
	if(ptr==NULL || N<=0 ) return 1;
	*ptr=(int *)malloc(N*sizeof(int));
	if(*ptr==NULL) return 2;
	return 0;
}
void destroy_array_int(int **ptr)
{
	if(ptr==NULL || *ptr==NULL) return;
	free(*ptr);
	*ptr=NULL;
}


int main ()
{
	printf("Podaj rozmiar tablicy: ");
	int size;
	int y=scanf("%d",&size);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(size<=0) return printf("Incorrect input data\n"),2;
	int tab;
	int *ptr=&tab;
	int **ptr2=&ptr;
	int g=create_array_int(ptr2,size);
	if(g==1) return printf("Incorrect input\n"),1;
	if(g==2) return printf("Failed to allocate memory\n"),8;
	int i;
	printf("Podaj dane: ");
	for(i=0;i<size;i++)
	{
		int z=scanf("%d",(ptr+i));
		if(z!=1)
		{
			destroy_array_int(ptr2);
			return printf("Incorrect input\n"),1;
		} 
	}
	int f=size;
	for(i=0;i<size;i++,f--)
	{
		printf("%d ",*(ptr+f-1));
	}
	destroy_array_int(ptr2);
	return 0;
}
