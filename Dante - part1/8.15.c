#include <stdio.h>
#define PI 3.14159

float toRadian(float xxx)
{
	return xxx*PI/180;
}
float toDegree(float yyy)
{
	return yyy*180/PI;
}
int main ()
{
	int konwersja;
	printf("Wybierz rodzaj konwersji (1=ST na RD, 2=RD na ST): ");
	int y=scanf("%d",&konwersja);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(konwersja<1 || konwersja>2)
	{
		printf("Incorrect input\n");
		return 1;
	}
	printf("Podaj miare kata: ");
	float kat;
	int yy=scanf("%f",&kat);
	if(yy!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(konwersja==1)
	{
		printf("%.2f",toRadian(kat));
	}
	else if(konwersja==2)
	{
		printf("%.2f",toDegree(kat));
	}
	return 0;
}



