#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#define num 1001


char* concatenate(int N, ...)
{
	if (N<=0) return NULL;
	va_list ap_test;
	va_start(ap_test, N);
	int len = 0;
	int i=0;
	for (; i < N; i++)
	{
		len+=strlen(va_arg(ap_test, const char*)); //same teksty oblicza
	}

	len += N - 1; //spacje
	len += 1; // terminator
	char *wynik=(char *)calloc(len,1);
	if(wynik==NULL)
	{
		va_end(ap_test);
		return NULL;
	} 
	va_end(ap_test);

	va_list ap_work;
	va_start(ap_work, N);
	i=0;
	for (; i < N; i++)
	{
		strcat(wynik, va_arg(ap_work, const char*));
		if(i+1!=N) strcat(wynik, " ");
	}
	va_end(ap_work);
	return wynik;
}

int main ()
{
	char **tab=(char **)calloc(4,sizeof(char *));
	if(tab==NULL)	return printf("Failed to allocate memory"),8;
	int i=0;
	for(;i<4;i++)
	{
		char *ptr=*(tab+i);
		ptr=(char *)calloc(num,1);
		if(ptr==NULL)
		{
			int j=0;
			for(;j<i;j++) free(*(tab+j));
			free(tab);
			return printf("Failed to allocate memory"),8;
		}
		*(tab+i)=ptr;
	}
	printf("Podaj liczbe: ");
	int liczba;
	int y=scanf("%d",&liczba);
	if(y!=1)
	{
		int j=0;
		for(;j<4;j++) free(*(tab+j));
		free(tab);
		return printf("Incorrect input"),1;
	} 
	if(liczba<=1)
	{
		int j=0;
		for(;j<4;j++) free(*(tab+j));
		free(tab);
		return printf("Incorrect input data"),2;
	}
	if(liczba>=5)
	{
		int j=0;
		for(;j<4;j++) free(*(tab+j));
		free(tab);
		return printf("Incorrect input data"),2;
	}
	int c=getchar();
	if(c!='\n') while(c!='\n') c=getchar();
	printf("Podaj tekst: ");
	i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(*(tab+0)+i)='\0';
			break;
		}
		if(i==1000)
		{
			*(*(tab+0)+i)='\0';
			c=getchar();
			if(c!='\n') while(c!='\n') c=getchar();
			break;
		}
		*(*(tab+0)+i)=znak;
		i++;
	}
	i=0;
	while(1)
	{
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(*(tab+1)+i)='\0';
			break;
		}
		if(i==1000)
		{
			*(*(tab+1)+i)='\0';
			c=getchar();
			if(c!='\n') while(c!='\n') c=getchar();
			break;
		}
		*(*(tab+1)+i)=znak;
		i++;
	}	
	if(liczba>=3)
	{
		i=0;
		while(1)
		{
			char znak;
			scanf("%c",&znak);
			if(znak=='\n')
			{
				*(*(tab+2)+i)='\0';
				break;
			}
			if(i==1000)
			{
				*(*(tab+2)+i)='\0';
				c=getchar();
				if(c!='\n') while(c!='\n') c=getchar();
				break;
			}
			*(*(tab+2)+i)=znak;
			i++;
		}		
	}
	if(liczba>=4)
	{
		i=0;
		while(1)
		{
			char znak;
			scanf("%c",&znak);
			if(znak=='\n')
			{
				*(*(tab+3)+i)='\0';
				break;
			}
			if(i==1000)
			{
				*(*(tab+3)+i)='\0';
				c=getchar();
				if(c!='\n') while(c!='\n') c=getchar();
				break;
			}
			*(*(tab+3)+i)=znak;
			i++;
		}		
	}
	char *wynik;
	switch(liczba)
	{
		case 2:
			{
				wynik=concatenate(liczba,*(tab+0),*(tab+1));
				break;
			}
		case 3:
			{
				wynik=concatenate(liczba,*(tab+0),*(tab+1),*(tab+2));
				break;
			}
		case 4:
			{
				wynik=concatenate(liczba,*(tab+0),*(tab+1),*(tab+2),*(tab+3));
				break;
			}
	}
	if(wynik==NULL)
	{
		int j=0;
		for(;j<4;j++) free(*(tab+j));
		free(tab);
		return printf("Failed to allocate memory"),8;
	}
	else printf("%s",wynik);	
	int j=0;
	for(;j<4;j++) free(*(tab+j));
	free(tab);
	free(wynik);
	return 0;
}
