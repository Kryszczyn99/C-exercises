#include <stdio.h>
#include "vector_utils.h"
#include <stdio.h>

int find_min(const int* tab, int size, int *min)
{
	if(tab==NULL || min==NULL || size<=0) return 1;
	int i;
	*min=*tab;
	for(i=0;i<size;i++,tab++)
	{
		if(*min>*tab) *min=*tab;
	}
	return 0;
}

int main ()
{
  int T[100];
  printf("Podaj liczby: ");
  int g=read_vector(T,100,-1);
  if(g==-1) return printf("Not enough data available\n"),3;
  if(g==0) return printf("Not enough data available\n"),3;
  if(g==-2) return printf("Incorrect input\n"),1;
  printf("\n");
  int c=0;
  int *min;
  min=&c;
  int p=find_min(T,g,min);
  if(p==1) return printf("Incorrect input\n"),1;
  printf("%d\n",c);
  return 0;
}
