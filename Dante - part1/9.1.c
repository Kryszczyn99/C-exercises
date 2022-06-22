#include <stdio.h>
#include <ctype.h>


unsigned int my_strlen(const char tab[]);
int my_atoi(const char tab[]);
float my_atof(const char tab[]);

int main() 
{   
  char tablica[16];
  printf("podaj ciag znakow: ");
	scanf("%15[^\n]",tablica);
	while(getchar()!='\n');
  printf("%u \n", my_strlen(tablica));
  printf("%d \n", my_atoi(tablica));
  printf("%.4f",my_atof(tablica));
  return 0;
}




unsigned int my_strlen(const char tab[])
{
	int number;
	for (number=0; tab[number]!='\0'; ++number);
	return number;
}

int my_atoi(const char tab[])
{
  	int p=0;
	if(tab[p]==0) return 0;
	if(tab[p]!='-' && tab[p]!='+' && !isdigit(tab[p])) return 0;
	int i=1;
	while(tab[i]!=0) 
	{
	if(!isdigit(tab[i])) break;
	i=i+1;
	}
	p=i;
	if(p==1 && !isdigit(tab[0])) return 0;
	int d=(!isdigit(tab[0]))? 1:0;
	int value=0;
	i=d;
	while(i<p)
	{
		value*=10;
		value+=tab[i]-'0';
		i=i+1;
	}
	return (tab[0]=='-')? -value:value;;
}
float my_atof(const char tab[])
{
	int p=0;
	if(tab[p]==0) return 0;
	if(tab[p]!='-' && tab[p]!='+' && !isdigit(tab[p])) return 0;
	int i;
	for(i=1; tab[i]!=0;i=i+1) if((!isdigit(tab[i]))) break;
	p=i;
	if(p==1 && !isdigit(tab[0])) return 0;
	int d=(!isdigit(tab[0]))? 1:0;
	int value1=0;
	for(i=d; i<p; i=i+1)
	{
		value1*=10;
		value1+=tab[i]-'0';
	}
	float value=0.0;
	int max;
	for(i=1; tab[i]!=0;i=i+1) if((tab[i]!='.') && (!isdigit(tab[i]))) break;
	max=i;
	int zmienna=(max-p-1);
	long long zmienna2=1;
	int g;
	for(g=0;g<zmienna;g++) zmienna2=zmienna2*10;
	for(d=p+1;d<max;d++)
	{
		value*=10;
		value+=tab[d]-'0';
	}
	value=value/zmienna2;
	value=value+value1;
	return (tab[0]=='-')? -value:value;;
}

