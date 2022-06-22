#include <stdio.h>

int is_equal(int a, int b);
int is_negative(int value);
int neguj(int i);

int main ()
{
	int p;
	printf("Podaj liczby: ");
	int y=scanf("%d",&p);
	if(1&y)
	{
		int w;
		y=scanf("%d",&w);
		if(1&y)
		{
			y=is_equal(p,w);
			if(1&y)	printf("rowne\n");	
			else printf("nierowne\n");
			y=is_negative(p);
			if(1&y) printf("ujemna");
			else printf("nieujemna");
			printf(" ");
			y=is_negative(w);
			if(1&y) printf("ujemna");
			else printf("nieujemna");
			return 0;
		}
	}
	return 1;
}
int neguj(int i)
{
	int h=i&(sizeof(int)*8);
	int p=!h;
	return p;
}

int is_equal(int a, int b)
{
	int i=0;
	int h= i&(sizeof(int)*8);
	int p=!h;
	for(;p;++i)
	{
		int a1=1<<i;
		int g=a&a1;
		int w=b&a1;
		if(g && w);
		else if(!g && w) return 0;
		else if(g && !w) return 0;
		p=neguj(i);
	}
	return 1;
}

int is_negative(int value)
{
	int l=1<<(sizeof(int)*7+3);
	if(!(value&l)) return 0;
	return 1;
}
