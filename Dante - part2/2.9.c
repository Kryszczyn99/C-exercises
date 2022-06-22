#include <stdio.h>

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size)
{
	if(t1==NULL || t2==NULL || t3==NULL || t4==NULL || size<=0) return 1;
	const char *t11=t1;
	const char *t22=t2;
	const char *t33=t3;
	int ilosc=0;
	for(;*t11!='\0';t11++) ilosc++;
	for(;*t22!='\0';t22++) ilosc++;
	for(;*t33!='\0';t33++) ilosc++;
	
	if(ilosc>=size) return 1;
	
	int suma1=0;
	for(;*t1!='\0';t1++,suma1++)
	{
		*t4=*t1;
		t4++;
	}
	*t4=' ';
	t4+=1;
	int suma2=0;
	for(;*t2!='\0';t2++,suma2++)
	{
		*t4=*t2;
		t4++;
	}
	*t4=' ';
	t4+=1;
	int suma3=0;
	for(;*t3!='\0';t3++,suma3++)
	{
		*t4=*t3;
		t4++;
	}
	int suma_ogolna=suma1+suma2+suma3+2;
	if(suma_ogolna>=size) return 1;
	*t4='\0';
	return 0;
}

int main ()
{
	char tab1[1001]={0};
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab1);
	int c = getchar();
  	if (c != '\n') 
	{
	    while (c != '\n')   c = getchar();
  	}
  	
  	
	char tab2[1001]={0};
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab2);
  	c = getchar();
  	if (c != '\n') 
	{
	    while (c != '\n')   c = getchar();
  	}
  	
  	
	char tab3[1001]={0};
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab3);
	c = getchar();
  	if (c != '\n') 
	{
	    while (c != '\n')   c = getchar();
  	}
  	
	
	char tab4[3001]={0};
	connect(tab1,tab2,tab3,tab4,3001);
	char *wsk=tab4;
	for(;*wsk!='\0';wsk++) printf("%c",*wsk);
	return 0;
}
