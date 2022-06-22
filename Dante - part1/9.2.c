#include <stdio.h>

int find_char(const char tab[], char c);
int rfind_char(const char tab[], char c);


int main ()
{
	printf("Ciag wyrazow: \n");
	char znak;
	char tablica[1001];
	scanf("%1000[^\n]",tablica);
	while(getchar()!='\n');
	printf("Podaj dodatkowy znak: ");
	scanf("%c",&znak);
	printf("%d\n",find_char(tablica,znak));
	printf("%d\n\n",rfind_char(tablica,znak));
	return 0;
}


int find_char(const char tab[], char c){
	int x=0;
	while(tab[x]!='\0') 
	{
	if(tab[x]==c) return x;
	x=x+1;
	}
	return -1;
}
int rfind_char(const char tab[], char c){
	int a=0;
	int ilosc=0;
	while(tab[a]!='\0')
	{
		ilosc+=1;
		a=a+1;
	}
	a=ilosc;
	while(a>=0)
	{
	 	if(tab[a]==c) return a;
	 	a=a-1;
	}
	return -1;
}
