#include <stdio.h>
#include <math.h>

float distance(int x1, int y1, int x2, int y2)
{
  if(x1== x2 && y1==y2) return -1;
	float d,e;
	e=((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
	d=sqrt(e);
	return d;
}
float perimeter(float a, float b, float c)
{
	float f;
	f=(a+b+c);
	if(a<=0 || b<=0 || c<=0) return -1;
	if(f>0 && (a+b>=c && a+c>=b && b+c>=a)) return f;
	return -1;
}
float area(float a, float b, float c)
{
	float u=perimeter(a,b,c)/2;
  float r = sqrt(u*(u-a)*(u-b)*(u-c));
  if(a<=0 || b<=0 || c<=0) return -1;
  if(r>0) return r;
  return -1;
}
int main()
{
	int x1,x2,x3,y1,y2,y3;
	printf("Podaj wspolrzedne pierwszego punktu: ");
	if(scanf("(%d, %d)",&x1,&y1)!=2)
	{
		printf("Incorrect input");
		return 1;
	}
  scanf("%*c");
	printf("Podaj wspolrzedne drugiego punktu: ");
	if(scanf("(%d, %d)",&x2,&y2)!=2)
	{
		printf("Incorrect input");
		return 1;
	}
  scanf("%*c");
	printf("Podaj wspolrzedne trzeciego punktu: ");
	if(scanf("(%d, %d)",&x3,&y3)!=2)
	{
		printf("Incorrect input");
		return 1;
	}
	if(x1==x2==x3 || y1==y2==y3)
	{
		printf("Incorrect input\n");
		return 1;
	}
	float a;
	a=distance(x1,y1,x2,y2);
	float b;
	b=distance(x1,y1,x3,y3);
	float c;
	c=distance(x3,y3,x2,y2);
  float pole=area(a,b,c);
  if(pole<0)
  {
  	printf("Incorrect input\n");
  	return 1;
  }
  printf("%.2f",pole);
	return 0;
} 

