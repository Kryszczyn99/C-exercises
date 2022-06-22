#include <stdio.h>


int main (void)
{
	float ect;
	float ects;
	printf("Podaje kwote: ");
	if(scanf("%f",&ect)!=1 || ect<0 ) 
	{
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj ilosc miesiecy: ");
	if(scanf("%f",&ects)!=1 || ects<0 )
	{
		printf("Incorrect input");
		return 1;
	}
	float ppp;
	for(ppp=0;ppp<ects;ppp++)ect=ect+ect*0.01;
	
	printf("%.2f",ect);
	return 0;
}
