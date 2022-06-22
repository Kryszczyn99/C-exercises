#include <stdio.h>

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3);


int read_vector(int vec[], int size, int stop_value)
{
	int i=0;
	if(size<1)  return -1;
	while(i<size)
	{
		int y=scanf("%d",&vec[i]);
		if(y!=1) return -2;
		if(vec[i]==stop_value) break;
		i+=1;
	}
	if(i==0) return -1;
	int zmienna;
    if ((vec[i] != stop_value || size==i && vec[i-1]!=stop_value))
    {
    	scanf("%d",&zmienna);
        while(zmienna!=stop_value)  scanf("%d", &zmienna);
    }
	return i;
}

void display_vector(const int vec[], int size)
{	
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d ",vec[i]);
	}
}

int main ()
{
	printf("Podaj pierwszy wektor: ");
	int tab1[50];
	int a=read_vector(tab1,50,0);
	if(a==-1) return printf("Not enough data available"), 2;
	if(a==-2) return printf("Incorrect input"), 1;
	printf("Podaj drugi wektor: ");
	int tab2[50];
	int b=read_vector(tab2,50,0);
	if(b==-1) return printf("Not enough data available"), 2;
	if(b==-2) return printf("Incorrect input"), 1;
	display_vector(tab1,a);
	printf("\n");
  	display_vector(tab2,b);
  	printf("\n");
  	int tab3[50];
  	int c=concat_begin(tab1,a,tab2,b,tab3,50);
  	if(c<0)  return printf("Output buffer is too small"), 0;
  	if(c>0) display_vector(tab3,c);
  	printf("\n");
  	int tab4[50];
  	int d=concat_end(tab1,a,tab2,b,tab4,50);
  	if(d<0) return printf("Output buffer is too small"), 0;
  	if(d>0) display_vector(tab4,d);
	printf("\n");
  	int tab5[50];
  	int e=concat_zip(tab1,a,tab2,b,tab5,50);
  	if(e<0) return printf("Output buffer is too small"), 0;
  	if(e>0) display_vector(tab5,e);
	printf("\n");
	return 0;
}


int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
	int i,j=0;
	if(size<=0) return -1;
	if(size2<=0) return -1;	
	if(size3<=0) return -1;
	if(size+size2>size3) return -2;
	for(i=0;i<size;i++)
	{
		dest[i]=first[i];
	}
	while(j<size2)
	{
		dest[i]=second[j];
		j+=1;
		i+=1;
	}
	size3=i;
	return  size3;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
	int i,j=0;
	if(size<=0) return -1;
	if(size2<=0) return -1;
	if(size3<=0) return -1;
	if(size==0 && size2==0) return -1;
	if(size+size2>size3) return -2;
	for(i=0;i<size2;i++)
	{
		dest[i]=second[i];
	}
	while(j<size)
	{
		dest[i]=first[j];
		j+=1;
		i+=1;
	}
	size3=i;
	return  size3;	
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
	int i,s=0,f=0,k=0;
	if(size<=0) return -1;
	if(size2<=0) return -1;	
	if(size3<=0) return -1;
	if(size==0 && size2==0) return -1;
	if(size+size2>size3) return -2;
	for(i=0;i<size+size2;i++)
	{
		if(k==1)
		{
			if(s==size2) break;
			dest[i]=second[s];
			s++;
			k=0;

		}
		else if(k==0)
		{
			if(f==size) break;
			dest[i]=first[f];
			f++;
			k=1;
		}
		
	}
	if(s==size2) 
	{
		for(;i<size+size2;i++)
		{
			dest[i]=first[f];
			f++;
		}
	}
	if(f==size)
	{
		for(;i<size+size2;i++)
		{
			dest[i]=second[s];
			s++;
		}
	}
	size3=i;
	return size3;
}

