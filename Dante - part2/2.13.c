#include <stdio.h>

int starts_with(const char* txt, const char* find)
{
	if(txt==NULL || find==NULL) return -1;
	poczatek_petli:
		if(*find=='\0') goto koniec2;
		if(*txt!=*find) goto koniec;
		find+=1;
		txt+=1;
	goto poczatek_petli;
	koniec2: return 1;
	koniec: return 0;
}
int ends_with(const char* txt, const char* find)
{
	if(txt==NULL || find==NULL) return -1;
	int ilosc1=0,ilosc2=0;
	const char *x=txt;
	const char *y=find;
	
    petla1:
     if(*y=='\0') goto dalej1;
     ilosc2=ilosc2+1; 
     y++;
    goto petla1;
    
    dalej1:
    
    petla2:
      if(*x=='\0') goto dalej2;
      ilosc1=ilosc1+1;
      x++;
    goto petla2;  
    
    dalej2:
    
    if(ilosc2>ilosc1) return 0;
    int i=ilosc1-ilosc2;
    
    petla3:
		if(i>=ilosc1) goto returnik;
		if(*(txt+i)!=*(find+i-ilosc1+ilosc2)) return 0;
		i++;
	goto petla3;
    returnik: return 1;
}

int main()
{
	char tab1[101]={0};
	printf("Podaj tekst: ");
	scanf("%100[^\n]s",tab1);
  setbuf(stdin,NULL);
  char tab2[101]={0};
	printf("Podaj drugi tekst: ");
	scanf("%100[^\n]s",tab2);
	
	int g=starts_with(tab1,tab2);
	printf("%d\n",g);
	
	g=ends_with(tab1,tab2);
	printf("%d\n",g);
	
	return 0;
}
