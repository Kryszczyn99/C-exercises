#include <stdio.h>
#include "vector_utils.h"


int create_histogram(const float *vec, int size, int *out, int out_size)
{
	if(vec==NULL) return 1;
	if(out==NULL) return 1;
	if(size<=0) return 1;
	if(out_size<=0) return 1;
	int i;
	for(i=0;i<size;i++)
	{
		if(*vec>=0 && *vec<1)
		{
			int *wsk2=out;
			*wsk2+=1;
		}
		else if(*vec>=1 && *vec<2)
		{
			int *wsk2=out;
			wsk2+=1;
			*wsk2+=1;
			
		}
		else if(*vec>=2 && *vec<3)
		{
			int *wsk2=out;
			wsk2+=2;
			*wsk2+=1;
			
		}
		else if(*vec>=3 && *vec<4)
		{
			int *wsk2=out;
			wsk2+=3;
			*wsk2+=1;
			
		}
		else if(*vec>=4 && *vec<5)
		{
			int *wsk2=out;
			wsk2+=4;
			*wsk2+=1;
			
		}
		else if(*vec>=5 && *vec<6)
		{
			int *wsk2=out;
			wsk2+=5;
			*wsk2+=1;
			
		}
		else if(*vec>=6 && *vec<7)
		{
			int *wsk2=out;
			wsk2+=6;
			*wsk2+=1;
			
		}
		else if(*vec>=7 && *vec<8)
		{
			int *wsk2=out;
			wsk2+=7;
			*wsk2+=1;
			
		}
		else if(*vec>=8 && *vec<9)
		{
			int *wsk2=out;
			wsk2+=8;
			*wsk2+=1;
			
		}
		else if(*vec>=9 && *vec<10)
		{
			int *wsk2=out;
			wsk2+=9;
			*wsk2+=1;
			
		}
		else if(*vec>=10 && *vec<11)
		{
			int *wsk2=out;
			wsk2+=10;
			*wsk2+=1;
			
		}
		vec++;
	}
	return 0;
}

int main ()
{
	printf("Podaj dane: ");
	float T1[100];
	int g=read_vector_float(T1,100,-1);
	if(g==-1 || g==0) return printf("Not enough data available\n"),3;
  	if(g==-2) return printf("Incorrect input\n"),1;
  	int T2[11]={0,0,0,0,0,0,0,0,0,0,0};
  	int p=create_histogram(T1,g,T2,11);
  	if(p==1) return printf("Incorrect input\n"),1;
  	display_vector(T2,11);
	
}
