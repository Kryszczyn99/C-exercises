#include <stdio.h>
#include "vector_utils.h"
#include <stdio.h>


int sort(int* tab, int size)
{
	if(tab==NULL) return 1;
	if(size<=0) return 1;
  int *backup;
  backup=tab;
	for(int j=0;j<size;j++)
	{
		for(int i=0;i<size-1-j;i++)
		{
			if(*tab>*(tab+1))
			{
				int temp=*(tab+1);
				*(tab+1)=*tab;
				*tab=temp;
			}
      tab++;
		}
    tab=backup;
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
  int p=sort(T,g);
  if(p==1) return printf("Incorrect input\n"),1;
  display_vector(T,g);
  return 0;
}
