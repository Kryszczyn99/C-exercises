#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct point_t* set(struct point_t* p, int a, int b)
{
	if(p==NULL) return NULL;
	(p->x)=a;
	(p->y)=b;
	return p;
}
void show(const struct point_t* p)
{
	if(p==NULL) return;
	printf("%d %d\n",p->x,p->y);
	return;
}
struct point_t* read(struct point_t* p)
{
	if(p==NULL) return NULL;
	
	printf("Podaj wspolrzedna x: ");
	int a=scanf("%d",&(p->x));
	if(a!=1) return NULL;
	
	printf("Podaj wspolrzedna y: ");
	a=scanf("%d",&(p->y));
	if(a!=1) return NULL;
	return p;
}
float distance(const struct point_t* p1, const struct point_t* p2, int *err_code)
{
	if((p1==NULL || p2==NULL) && err_code!=NULL)
	{
		*err_code=1;
		return -1;
	}  
	if(p1==NULL || p2==NULL)	return -1; 
	int x1,x2,y1,y2;
	x1=(p1->x);
	x2=(p2->x);
	y1=(p1->y);
	y2=(p2->y);
	float result=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*1.0);
	if(err_code!=NULL)*err_code=0;
	return result;
}

int main ()
{
	struct point_t value;
	if(read(&value)==NULL) return printf("Incorrect input\n"),1;
	show(&value);
	
	struct point_t value2;
	srand(time(NULL));
	int x1=rand()%10;
	int y1=rand()%10;
	if(set(&value2,x1,y1)==NULL) return printf("Incorrect input\n"),1;
	show(&value2);
	int err_code;
	int *result=&err_code;
	float wynik=distance(&value,&value2,result);
	if(err_code==1 || wynik==-1)  return printf("Incorrect input\n"),1;
	printf("%.2f\n",wynik);
	return 0;
}
