#include <stdio.h>

int read_vector_float(float *vec, int size, float stop_value)
{
    int i=0;
    if(vec==NULL) return -1;
    if(size<1)  return -1;
    float *wsk=vec;
    while(i<size)
    {
        int y=scanf("%f",wsk);
        if(y!=1) return -2;
        if(*wsk==stop_value) break;
        i+=1;
        wsk++;
    }
    
    if(i==0) return 0;
    return i;
}
int sum(const float* tab, unsigned int size, float *result)
{
	if(tab==NULL || result==NULL) return 1;
  *result=0;
  for(unsigned int i=0;i<size;i++,tab++) *result+=*tab;
  return 0;
}
int avg(const float* tab, unsigned int size, float *result)
{
	if(tab==NULL || result==NULL) return 1;
  	*result=0;
  
  	float ilosc_cyfr=0;
  	for(unsigned int i=0;i<size;i++,tab++)
  	{
    	ilosc_cyfr+=1;
    	*result+=*tab;
  	}
  	*result/=ilosc_cyfr;
  	return 0;
}
int main ()
{
  float Ta[100];
  float *T=Ta;
  printf("Podaj liczby: ");
  int g=read_vector_float(T,100,0);
  if(g==-1 || g==0) return printf("Not enough data available\n"),3;
  if(g==-2) return printf("Incorrect input\n"),1;
  printf("\n");
  float srednia=0,suma=0;
  int x=sum(T,g,&suma);
  if(x==1) return printf("Incorrect input\n"),1;
  printf("Suma : %.2f\n",suma);
  x=avg(T,g,&srednia);
  if(x==1) return printf("Incorrect input\n"),1;
  printf("Srednia : %.2f\n",srednia);
  return 0;
}
