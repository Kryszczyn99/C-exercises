#include <stdio.h>
#include <stdlib.h>
int main ()
{	                                            
	int dat[1000];
	printf("Podaj liczby: \n");
	int n;
	for(n=0;n<999;n++)
	{
		int c=scanf("%d",&dat[n]);
		while(getchar()!='\n');
		if(c!=1)
		{
			printf("Incorrect input\n");
			return 1;
		}
		if(dat[n]==0) break;
	}
	if(n==999) dat[n]=0;
	int i;
	printf("Podane liczby to: ");
	for(i=0;i<=n;i++) 
	{
			printf("%d ",dat[i]);
	}	
	printf("\n");              
	if(n<2)
	{
			printf("Incorrect input\n");
			return 1;
	}  
	int dif[1000];
	i=0;
	while(dat[i+1]!=0)
	{
		dif[i]=dat[i+1]-dat[i];
		i++;
	}
	n=i+1;
	int	imax[500];
	int jmax=0;
	int k=0;
	int j;
	for(i=0;i<n;i++)
	{
			j=0;while(dif[i+j]>0 && i+j<n) j++;
				if(j==jmax) imax[k++]=i;
				if(j>jmax) 
				{
					jmax=j; 
					k=0;
					imax[k++]=i;
				}
			i+=j;
	}
	if(jmax>0) jmax++;
	printf("%d\n",jmax);
	printf("%d\n",k);
	int im;
	for(i=0;i<k;i++)
	{
		im=imax[i];
		printf("%d - ",im);
			for(j=im;j<im+jmax;j++)	
			{
				printf("%d ",dat[j]);				
			}

		printf("\n");
	}	
	return 0;
}
