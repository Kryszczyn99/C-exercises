#include <stdio.h>
#include <string.h>
#include <math.h>

float average(const int tab[], int size);
float stdDev(const int tab[], int size);

int main(void) {

int i=0;
int tab[100];
int a=0;
printf("Podaj liczby: ");
while(a<=100)
{
  int y=scanf("%d",&tab[i]);
  if(y!=1)
  {
    printf("Incorrect input\n");
    return 1;
  }
  if(i==100) break;
  if(tab[i]==0) break;
  i=i+1;
  a=a+1;
}
if(i==0)
{
  printf("not enough data available");
  return 2;
}
float srednia=average(tab,i);
float odchylenie=stdDev(tab,i);
printf("%.2f\n",srednia);
printf("%.2f\n",odchylenie);
return 0;
}

float average(const int tab[], int size)
{
  int i;
  float wynik=0;
  float ilosc=0;
  if(size<=0) return -1;
  for(i=0;i<size;i++)
  {
    wynik+=tab[i];
    ilosc++;
  }
  float srednie;
  srednie=wynik/ilosc;
  return srednie;
}
float stdDev(const int tab[], int size)
{
	  int i;
  float wynik=0;
  float ilosc=0;	
  if(size<=0) return -1;
  for(i=0;i<size;i++)
  {
    wynik+=tab[i];
    ilosc++;
  }
  float srednie;
  srednie=wynik/ilosc;
  float suma=0;
  for(i=0;i<size;i++)
  {
  	suma+=(tab[i]-srednie)*(tab[i]-srednie);
  }
  float koniec=sqrt(suma/size);
  return koniec;
}
