#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main (void)
{
	int i,j,A[4][4],B[4][4],C[4][4];
	srand(time(NULL));
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			A[i][j]=rand () %10;
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{	
			B[i][j]=rand () %10;
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j) printf("1 "),C[i][j]=1;
			else printf("0 "),C[i][j]=0;
		}
		printf("\n");
	}
	
	printf("\n");
	
	int suma;
	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=A[i][j];
		}
		printf("%d ",suma);
	}
		
	printf("\n");
	
	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=A[j][i];
		}
		printf("%d ",suma);
	}
	
	printf("\n");
	

	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=B[i][j];
		}
		printf("%d ",suma);
	}
		
	printf("\n");
	
	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=B[j][i];
		}
		printf("%d ",suma);
	}

	printf("\n");
	
	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=C[i][j];
		}
		printf("%d  ",suma);
	}
		
	printf("\n");
	
	for(i=0;i<4;i++)
	{	
		suma=0;
		for(j=0;j<4;j++)
		{
			suma+=C[j][i];
		}
		printf("%d  ",suma);
	}

	
	
	return 0;
}
