#include <stdio.h>
#include <stdlib.h>


int dd_test(const int *ptr, int width, int height)
{
  if(ptr==NULL) return -1;
  if(width!=height) return -1;
  if(width<=0 || height <=0) return -1;
  int x=0;
  while(x<width)
  {
  	int y=0,suma_p=0,suma=0;
    while(y<height)
    {
        if(x==y)
        {
            int zm=abs(*ptr);
            suma_p+=zm; 
        }
        else
        {
            int zm=abs(*ptr);
            suma+=zm;
        }
        y++;
        ptr++;  
    }
    if(suma_p<=suma) return 0;
    x++;
  }
  return 1;
}

int main ()
{
    int tablica[5][5]={0};
    printf("Podaj macierz 5 na 5: \n");
    int i;
    int *wsk=&**tablica;
    for(i=0;i<25;i++)
    {
            int y=scanf("%d",wsk+i);
            if(y!=1)
            {
                return printf("Incorrect input\n"),1;
            }
    }
    int *ptr=&**tablica;
    int p=dd_test(ptr,5,5);
    if(p==1) printf("YES\n");
    else if(p==0) printf("NO\n");
    else if (p==-1) printf("Incorrect input\n");
    //-177 46 57 66 60 -79 -32 14 -71
    //1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1
    return 0;
}
