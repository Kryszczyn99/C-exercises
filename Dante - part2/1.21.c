#include <stdio.h>

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg)
{
	if(ptr==NULL || max==NULL || min==NULL || avg==NULL) return 1;
	if(width<=0 || height<=0) return 1;
	if(column_id<0) return 1;
	if(column_id>=width) return 1;
	if(height!=width)
	{
		int temp=height;
		height=width;
		width=temp;
	}
  	*max=*(ptr+column_id);
  	*min=*(ptr+column_id);
  	*avg=0;
	int i;
	for(i=0;i<width;i++)
	{
		int value=*(ptr+column_id+i*height);
    	if(value>*max) *max=value;
    	if(value<*min) *min=value;
    	*avg+=value;
	}
  	if(height!=width)*avg/=width;
  	else *avg/=height;
	return 0;
}
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg)
{
  if(ptr==NULL || max==NULL || min==NULL || avg==NULL) return 1;
	if(width<=0 || height<=0) return 1;
	if(row_id<0) return 1;
	if(row_id>=height) return 1;
  *max=*(ptr+row_id*width);
  *min=*(ptr+row_id*width);
  *avg=0;
  int i;
  for(i=0;i<width;i++)
  {
    int value=*(ptr+row_id*width+i);
    if(value>*max) *max=value;
    if(value<*min) *min=value;
    *avg+=value;
  }
  *avg/=width;
  return 0;
}


int main ()
{
    int tablica[5][5]={0};
    printf("Podaj macierz 5 na 5: \n");
    int i;
    int *wsk=&**tablica;
    for(i=0;i<25;i++)
    {
            int y=scanf("%d",wsk+i);
            if(y!=1)
            {
                return printf("Incorrect input\n"),1;
            }
    }
    int *ptr=&**tablica;
    int max,min;
    float avg;
    int *a,*b;
    float *c;
    a=&max;
    b=&min;
    c=&avg;
    for(i=0;i<5;i++)
    {
    	int p=column_statistics(ptr,5,5,i,a,b,c);
   		if(p==1) return printf("Incorrect input\n"),1;
      printf("%d ",min);
      printf("%d ",max);
      printf("%.2f\n",avg);
	}
    for(i=0;i<5;i++)
    {
    	int p=row_statistics(ptr,5,5,i,a,b,c);
   		if(p==1) return printf("Incorrect input\n"),1;
      printf("%d ",min);
      printf("%d ",max);
      printf("%.2f\n",avg);
	}
    return 0;
}
