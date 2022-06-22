#include <stdio.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct segment_t
{
    struct point_t start;
    struct point_t end;
};

struct segment_t* read_segment(struct segment_t* p)
{
	if(p==NULL) return NULL;
	int x1,x2,y1,y2,z;
	printf("Podaj pierwsze dane: \n");
	printf("Podaj X: ");
	z=scanf("%d",&x1);
	if(z!=1) return NULL;
	printf("Podaj Y: ");
	z=scanf("%d",&y1);
	if(z!=1) return NULL;
	/*********************************/
	printf("Podaj drugie dane: \n");
	printf("Podaj X: ");
	z=scanf("%d",&x2);
	if(z!=1) return NULL;
	printf("Podaj Y: ");
	z=scanf("%d",&y2);
	if(z!=1) return NULL;
	/*********************************/
	p->start.x=x1;
	p->start.y=y1;
	p->end.x=x2;
	p->end.y=y2;
	return p;
}
void show_segment(const struct segment_t* p)
{
	if(p==NULL) return;
	int x1,x2,y1,y2;
	x1=p->start.x;
	y1=p->start.y;
	x2=p->end.x;
	y2=p->end.y;
	printf("Dane poczatkowe: x = %d; y = %d\n",x1,y1);
	printf("Dane koncowe: x = %d; y = %d\n",x2,y2);
}
float length(const struct segment_t* s, int *err_code)
{
	if(s==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return -1;
	}
	int x1,x2,y1,y2;
	x1=s->start.x;
	x2=s->end.x;
	y1=s->start.y;
	y2=s->end.y;
	float result=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*1.0);
	if(err_code!=NULL) *err_code=0;
	return result;
}

int main ()
{
	struct segment_t a;
	if(read_segment(&a)==NULL)
	{
		printf("Incorrect input\n");
		return 1;
	}
	show_segment(&a);
	float result;
	int err_code;
	int *err_code1=&err_code;
	result=length(&a,err_code1);
	printf("%.2f",result);
	return 0;
}
