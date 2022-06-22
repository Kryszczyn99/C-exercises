#include <stdio.h>
#include <stdlib.h>

int main ()
{
	float *wsk;
	wsk=(float*)malloc(sizeof(float));
	if(wsk==NULL){
		printf("Failed to allocate memory\n");
		return 8;
	}
	*wsk=3.141593;
	printf("%f %p",*wsk,(void*)wsk);
	free(wsk);
	return 0;
}
