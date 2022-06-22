#include <stdio.h>
#include "vector_utils.h"

int reverse_vector(int* tab, int size)
{
	if(tab==NULL) return 1;
	if(size<=0) return 1;
	int i,j,temp;
  int *backup;
  backup=tab;
  for(j=0;j<size;j++)
  {
    for(i=0;i<size-1-j;i++)
    {
      temp=*(tab+1);
      *(tab+1)=*tab;
      *tab=temp;
      tab++;
    }
    tab=backup;
  }
	return 0;
}

int main ()
{
	printf("Podaj dane: ");
	int T[100];
	int g=read_vector(T,100,0);
	if(g==-1 || g==0) return printf("Not enough data available\n"),3;
  	if(g==-2) return printf("Incorrect input\n"),1;
  	display_vector(T,g);
    printf("\n");
  	int p=reverse_vector(T,g);
  	if(p==1) return printf("Incorrect input\n"),1;
  	display_vector(T,g);
	return 0;
}
