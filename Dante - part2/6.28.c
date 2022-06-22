#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "format_type.h"
#include <math.h>

struct statistic_t
{
  int min;
  int max;
  float avg;
  float standard_deviation;
  int range;
};

int statistics(int **ptr, struct statistic_t **stats)
{
	if(ptr==NULL || stats==NULL) return 1;
	*stats=(struct statistic_t *)malloc(sizeof(struct statistic_t));
	if(*stats==NULL) return 2;
	if(*ptr==NULL)
	{
		free(*stats);
		return 3;
	} 
	int g=0,p=0,ile_liczb=0;
	int min=**ptr;
	int max=**ptr;
	float avg=0;
	while(1)
	{
		if(*(ptr+p)==NULL) break;
		while(1)
		{
			if(*(*(ptr+p)+g)==-1) break;
			if(min>*(*(ptr+p)+g)) min=*(*(ptr+p)+g);
			if(max<*(*(ptr+p)+g)) max=*(*(ptr+p)+g);
			avg+=*(*(ptr+p)+g);
			g++;
			ile_liczb+=1;
		}
		g=0;
		p++;
	}
	if(ile_liczb==0)
	{
		free(*stats);
		return 3;
	}
	avg/=ile_liczb;
	int range=max-min;
	float odchylenie=0;
	p=0,g=0;
	while(1)
	{
		if(*(ptr+p)==NULL) break;
		while(1)
		{
			if(*(*(ptr+p)+g)==-1) break;
			odchylenie+=(*(*(ptr+p)+g)-avg)*(*(*(ptr+p)+g)-avg);
			g++;
		}
		g=0;
		p++;
	}
	odchylenie/=ile_liczb;
	odchylenie=sqrt(odchylenie);
	(*stats)->avg=avg;
	(*stats)->max=max;
	(*stats)->min=min;
	(*stats)->range=range;
	(*stats)->standard_deviation=odchylenie;
	return 0;
}

void display(int **ptr)
{
	if(ptr==NULL) return;
	int g=0,p=0;
	while(1)
	{
		if(*(ptr+p)==NULL) break;
		while(1)
		{
			if(*(*(ptr+p)+g)==-1) break;
			printf("%d ",*(*(ptr+p)+g));
			g++;
		}
		g=0;
		printf("\n");
		p++;
	}
}
int save(const char *filename, int **ptr, enum save_format_t format)
{
	if(filename==NULL || ptr==NULL) return 1;
	if(format==1)
	{
		FILE *f;
		f=fopen(filename,"w");
		if(f==NULL) return 2;
		int i=0;
		while(1)
		{
			if(*(ptr+i)==NULL) break;
			int j=0;
			while(1)
			{
				if(*(*(ptr+i)+j)==-1) break;
				fprintf(f,"%d ",*(*(ptr+i)+j));
				j++;
			}
			fprintf(f,"-1\n");
			i++;
		}
		fclose(f);
		return 0;
	}
	else if(format==2)
	{
		FILE *f;
		f=fopen(filename,"wb");
		if(f==NULL) return 2;
		int i=0;
		while(1)
		{
			if(*(ptr+i)==NULL) break;
			int j=0;
			while(1)
			{
				int value = *(*(ptr+i)+j);
				fwrite(&value,sizeof(int),1,f);
				if(*(*(ptr+i)+j)==-1) break;
				j++;
			}
			i++;
		}
		fclose(f);
		return 0;
	}
	return 1;
}

int main ()
{
	int A[] = {10, 20, 30, 40, 50, 60, 70, -1};
	int B[] = {100, 200, 300, 400, 500, 600, 700, 800, -1};
	int C[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1};
	int* D[] = {A, B, C, NULL};
	display(D);
	char *wsk=(char *)malloc(40*sizeof(char));
	if(wsk==NULL) return printf("Failed to allocate memory"),8;
	printf("Podaj nazwe pliku: ");
	int i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n') break;
		if(i>=39) break;
		*(wsk+i)=znak;
		i++;
	}
	char *wsk_b=(char *)malloc(44*sizeof(char));
	if(wsk_b==NULL)
	{
		free(wsk);
		return printf("Failed to allocate memory"),8;
	} 
	strcpy(wsk_b,wsk);
	strcat(wsk_b,".bin");
	char *wsk_t=(char *)malloc(44*sizeof(char));
	if(wsk_t==NULL)
	{
		free(wsk);
		free(wsk_b);
		return printf("Failed to allocate memory"),8;
	} 
	strcpy(wsk_t,wsk);
	strcat(wsk_t,".txt");
	int g=save(wsk_t,D,fmt_text);
	if(g==1 || g==2) printf("Couldn't create file\n");
	else printf("File saved\n");
	g=save(wsk_b,D,fmt_binary);
	if(g==1 || g==2) printf("Couldn't create file\n");
	else printf("File saved\n");
	struct statistic_t *wskaznik;
	statistics(D,&wskaznik);
	printf("%d\n%d\n%d\n%f\n%f\n",wskaznik->min,wskaznik->max,wskaznik->range,wskaznik->avg,wskaznik->standard_deviation);
	free(wskaznik);
	free(wsk);
	free(wsk_b);
	free(wsk_t);
	return 0;
}
