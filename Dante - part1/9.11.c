#include <stdio.h>

int my_strcmp(const char tab[], const char tab2[])
{
	int i;
	int len1=0;
	int len2=0;
	for(i=0;tab[i]!='\0';i++) len1++;
	for(i=0;tab2[i]!='\0';i++) len2++;
	for(i=0;tab[i]!='\0' && tab2[i]!='\0';i++)
	{
		if(tab[i]==tab2[i]) continue;
		if(tab[i]!=tab2[i])
		{
			int a,b;
			a=tab[i];
			b=tab2[i];
			if(a>b) return 1;
			else return -1;
		}
	}
	if(len1>len2) return 1;
	if(len1<len2) return -1;
	return 0;
}

int my_strncmp(const char tab[], const char tab2[], unsigned int n)
{
	unsigned int i;
	for(i=0;i<n;i++)
	{
		if(tab[i]==tab2[i]) continue;
		if(tab[i]!=tab2[i])
		{
			int a,b;
			a=tab[i];
			b=tab2[i];
			if(a>b) return 1;
			else return -1;
		}
	}
	return 0;	
}

int main ()
{
	char tab1[101];
	printf("Podaj tekst: \n");
	scanf("%100[^\n]s", tab1);
  int c = getchar();
  if (c != '\n') {
    while (c != '\n') {
      c = getchar();
    }
  }
	char tab2[101];
	printf("Podaj tekst: \n");
	scanf("%100[^\n]s", tab2);
  c = getchar();
  if (c != '\n') {
    while (c != '\n') {
      c = getchar();
    }
  }
	int n;
	printf("podaj liczbe: \n");
	int y=scanf("%d",&n);
	if(n<=0 || y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(n>100) n=100;
	int a=my_strcmp(tab1,tab2);
	printf("strcmp %d\n",a);
	int b=my_strncmp(tab1,tab2,n);
	printf("strncmp %d\n",b);
	return 0;
}
