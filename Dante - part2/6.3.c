#include <stdio.h>
#include <stdlib.h>

float* create_array(int N)
{
	if(N<=0) return NULL;
	float *wsk;
	wsk=(float *)malloc(N*sizeof(float));
	if(wsk==NULL) return NULL;
	return wsk;
}

int main ()
{
	printf("Podaj rozmiar tablicy: ");
	int size;
	int y=scanf("%d",&size);
	if(y!=1) return printf("Incorrect input\n"),1;
	if(size<=0) return printf("Incorrect input data\n"),2;
	float *ptr=create_array(size);
	if(ptr==NULL) return printf("Failed to allocate memory\n"),8;
	int i;
	printf("Podaj dane: ");
	for(i=0;i<size;i++)
	{
		int z=scanf("%f",ptr+i);
		if(z!=1)
		{
			free(ptr);
			return printf("Incorrect input\n"),1;
		} 
	}
	int f=size;
	for(i=0;i<size;i++,f--)
	{
		printf("%f ",*(ptr+f-1));
	}
	free(ptr);
	return 0;
}
