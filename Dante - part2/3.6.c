#include <stdio.h>

int main ()
{
	FILE *plik1;
	plik1=fopen("0.txt","w");
	if(plik1==NULL)
	{
		return printf("Couldn't create file\n"),5;
	} 
	FILE *plik2;
	plik2=fopen("2.txt","w");
	if(plik2==NULL)
	{
		fclose(plik1);
		return printf("Couldn't create file\n"),5;
	} 
	FILE *plik3;
	plik3=fopen("3.txt","w");
	if(plik3==NULL)
	{
		fclose(plik1);
		fclose(plik2);
		return printf("Couldn't create file\n"),5;
	} 
	FILE *plik4;
	plik4=fopen("5.txt","w");
	if(plik4==NULL)
	{
		fclose(plik1);
		fclose(plik2);
		fclose(plik3);
		return printf("Couldn't create file\n"),5;
	} 
	printf("Podaj liczby: \n");
	while(1)
	{
		int a;
		scanf("%d",&a);
		if(a==0) break;
		int p=0;
		if(a%2==0)
		{
			fprintf(plik2,"%d\n",a);
			p=1;
		}		
		if(a%3==0)
		{
			fprintf(plik3,"%d\n",a);
			p=1;
		}
		if(a%5==0)
		{
			fprintf(plik4,"%d\n",a);
			p=1;
		}
		if(p==0) fprintf(plik1,"%d\n",a);
	}

	fclose(plik1);
	fclose(plik2);
	fclose(plik3);
	fclose(plik4);
	printf("Files saved\n");
	return 0;
}
