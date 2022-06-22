#include <stdio.h>


char * my_strpbrk ( const char * tab1, const char * tab2)
{
    for(;*tab1;tab1++)
    {
      	const char *wsk1,*wsk2;
      	wsk1=tab1;
        for(wsk2=tab2; *wsk2; wsk2++)
		{
			if (*wsk1!=*wsk2) continue;
			return  (char*) wsk1;
		}        
    }
    return NULL;
}


int main()
{
    char tab1[1001];
    printf("Podaj ciag znakow:\n");
    scanf("%1000[^\n]s",tab1);
	char tab2[13]={'a','A','e','E','o','O','i','I','y','Y','u','U'};
    char *wsk1=my_strpbrk (tab1,tab2);
    int suma;
    suma=0;
    for(;wsk1!=NULL;)
	{
	   wsk1 = wsk1 + 1;
       wsk1 = my_strpbrk(wsk1,tab2);
       suma=suma+1;
    }
    printf("Wynik : %d\n",suma);
    return 0;
}
