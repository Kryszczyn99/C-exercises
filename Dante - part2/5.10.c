#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


enum figure_types {
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

struct point_t
{
    int x;
    int y;
};

struct rectangle_t
{
    struct point_t p;
    int width;
    int height;
};

struct circle_t
{
    struct point_t c;
    float r;
};

struct triangle_t
{
    struct point_t p1;
    struct point_t p2;
    struct point_t p3;
};

struct figure_t {
    union
    {
        struct rectangle_t rect;
        struct triangle_t triangle;
        struct circle_t circ;
    };
    enum figure_types type;
};

float area_triangle(const struct triangle_t *t);//
float area_rectangle(const struct rectangle_t *r);//
float area_circle(const struct circle_t *c);//
float area_figure(const struct figure_t *f);

void display_rectangle(const struct rectangle_t *rect);//
void display_triangle(const struct triangle_t *t);//
void display_circle(const struct circle_t *circ);//
void display_figure(struct figure_t *f);

int sort_by_area(struct figure_t **figures, int size);
int sprawdz(int x1, int y1, int x2, int y2, int x3, int y3);//

int main()
{
    struct figure_t tab[50]={0};
    struct figure_t *wsk[50];//Robisz se t¹ tablicê i w pêtli idziesz tak do 49 i musisz ka¿demy wskaŸnikowi z tablicy wskaŸników przypisaæ adres tablicy tab
    int pobrane = 0,flaga_1=0;
    int i = 0;
    while (1)
    {
        if (pobrane == 50) break;
        printf("Podaj typ figury: ");
        int x;
        int y = scanf("%d", &x);
        if (y != 1) return printf("Incorrect input\n"), 1;
        if (x == 0) break;
        if (x < 0 || x>3) return printf("Incorrect input data\n"), 2;
        if (x == 1)
        {
            (tab + i)->type = 1;
            printf("Podaj dane trojkata: ");
            int z = scanf("%d %d %d %d %d %d", &((tab+i)->triangle.p1.x),&((tab+i)->triangle.p1.y),&((tab+i)->triangle.p2.x),&((tab+i)->triangle.p2.y),&((tab+i)->triangle.p3.x),&((tab+i)->triangle.p3.y));
            if (z != 6) return printf("Incorrect input\n"), 1;
            int xxx=sprawdz((tab+i)->triangle.p1.x,(tab+i)->triangle.p1.y,(tab+i)->triangle.p2.x,(tab+i)->triangle.p2.y,(tab+i)->triangle.p3.x,(tab+i)->triangle.p3.y);
            if(xxx!=0)  flaga_1=1;
        }
        else if (x == 2)
        {
            (tab + i)->type = 2;
            printf("Podaj dane prostokatu: ");
            int z = scanf("%d %d %d %d", &((tab+i)->rect.p.x),&((tab+i)->rect.p.y),&((tab+i)->rect.width),&((tab+i)->rect.height));
            if( (tab+i)->rect.height <= 0 ||(tab+i)->rect.width <=0){
              flaga_1=1;
            }
            if (z != 4) return printf("Incorrect input\n"), 1;
            
        }
        else if (x == 3)
        {
            (tab+i)->type = 3;
            printf("Podaj dane kola: ");
            int z = scanf("%d %d %f", &((tab+i)->circ.c.x),&((tab+i)->circ.c.y),&((tab+i)->circ.r));
            if (z != 3) return printf("Incorrect input\n"), 1;
            if((tab+i)->circ.r <= 0){
              flaga_1=1;
            }

        }
        pobrane += 1;
        i += 1;
    }
    if(flaga_1==1) return printf("Incorrect input data"),2;
    int j = 0;
    while(j < 50){
      *(wsk+j)=tab+j;
      j++;
    }
    sort_by_area(wsk, pobrane);
    int index;
    for (index = 0; index < pobrane; index++)
    {
      display_figure(*(wsk+index));
    }
    return 0;
}
int sprawdz(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x1 == x2 && y1 == y2) return 1;
    if (x1 == x3 && y1 == y3) return 1;
    if (x2 == x3 && y2 == y3) return 1;
    if (y1 == y2 && y1 == y3) return 1;
    if (x1 == x2 && x1 == x3) return 1;
    return 0;
}
void display_triangle(const struct triangle_t *t)
{
    if (t == NULL) return;
    int x1, x2, x3, y1, y2, y3;

    x1 = t->p1.x;
    x2 = t->p2.x;
    x3 = t->p3.x;
    y1 = t->p1.y;
    y2 = t->p2.y;
    y3 = t->p3.y;
    int g = sprawdz(x1, y1, x2, y2, x3, y3);
    if (g == 1) return;
    printf("Triangle p1(%d, %d), p2(%d, %d), p3(%d, %d)\n", x1, y1, x2, y2, x3, y3);
}

void display_rectangle(const struct rectangle_t *rect)
{
    if (rect == NULL) return;
    printf("Rectangle (%d, %d), width = %d, height = %d\n", rect->p.x, rect->p.y, rect->width, rect->height);
}

void display_circle(const struct circle_t *circ)
{
    if (circ == NULL) return;
    printf("Circle (%d, %d), radius = %f\n", circ->c.x, circ->c.y, circ->r);
}

void display_figure(struct figure_t *f)
{
    if (f == NULL) return;
    if (f->type == TRIANGLE)
    {
        display_triangle(&f->triangle);
    }
    else if (f->type == RECTANGLE)
    {
        display_rectangle(&f->rect);
    }
    else if (f->type == CIRCLE)
    {
        display_circle(&f->circ);
    }
}

float area_triangle(const struct triangle_t *t)
{
    if (t == NULL) return -1;
    int x1, x2, x3, y1, y2, y3;
    x1 = t->p1.x;
    x2 = t->p2.x;
    x3 = t->p3.x;
    y1 = t->p1.y;
    y2 = t->p2.y;
    y3 = t->p3.y;
    int g = sprawdz(x1, y1, x2, y2, x3, y3);
    if (g == 1) return -1;
    int r1 = x2 - x1;
    int r2 = y3 - y1;
    int r3 = y2 - y1;
    int r4 = x3 - x1;
    float wynik = (float)abs((r1*r2 - r3 * r4)) / 2;
    return wynik;
}

float area_rectangle(const struct rectangle_t *r)
{
    if (r == NULL) return -1;
    if (r->height <= 0 || r->width <= 0) return -1;
    float wynik = r->height*r->width;
    return wynik;
}

float area_circle(const struct circle_t *c)
{
    if (c == NULL) return -1;
    float n = c->r;
    if (n <= 0) return -1;
    float wynik = 3.141592*n*n;
    return wynik;
}

float area_figure(const struct figure_t *f)
{
    if (f == NULL) return -1;
    float wynik = -1;
    if (f->type == TRIANGLE)
    {
        wynik = area_triangle(&f->triangle);
    }
    else if (f->type == RECTANGLE)
    {
        wynik = area_rectangle(&f->rect);
    }
    else if (f->type == CIRCLE)
    {
        wynik = area_circle(&f->circ);
    }
    return wynik;
}

int sort_by_area(struct figure_t **figures, int size)
{
    if (figures == NULL || size <= 0) return 1;
    if (size == 1) return 0;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            float wynik1 = area_figure(*(figures + j));
            float wynik2 = area_figure(*(figures + 1 + j));
            if (wynik1 == -1 || wynik2 == -1) return 1;
            if (wynik1 < wynik2)
            {
                struct figure_t *temp = *(figures + j);
                *(figures + j) = *(figures + 1 + j);
                *(figures + 1 + j) = temp;
            }
        }
    }
    return 0;
}
