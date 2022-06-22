#include <stdio.h>

int main()
{
	int x;
	char l;
	printf("Podaj litere i cyfre po spacji:");
	if(scanf(" %c%d",&l,&x)!=2)
	{
		printf("Incorrect input");
		return 1;
	}
	if(l<'a' || l>'h' || x<1 || x>8)
	{
		printf("Incorrect input");
		return 1;
	}

	else if(x>=1 && x<=8 && l>='a' && l<='h')
	{
		if(l=='a' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("black");
		}
		if(l=='a' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("white");
		}
		if(l=='b' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("white");
		}
		if(l=='b' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("black");
		}
		if(l=='c' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("black");
		}
		if(l=='c' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("white");
		}
		if(l=='d' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("white");
		}
		if(l=='d' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("black");
		}
		if(l=='e' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("black");
		}
		if(l=='e' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("white");
		}
		if(l=='f' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("white");
		}
		if(l=='f' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("black");
		}
		if(l=='g' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("black");
		}
		if(l=='g' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("white");
		}
		if(l=='h' && (x==1 || x==3 || x==5 || x==7))
		{
			printf("white");
		}
		if(l=='h' && (x==2 || x==4 || x==6 || x==8))
		{
			printf("black");
		}	
	
	}
	
}
