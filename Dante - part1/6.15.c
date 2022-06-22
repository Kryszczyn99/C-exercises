#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define XX 1001
int main (void)
{
	char tablica[XX];
	printf("Podaj ciag: \n");
	fgets(tablica, XX, stdin);
	int len=strlen(tablica);
	int ii,kk=0,wyrazy=0;
	for(ii=0;ii<len-1;ii++)
	{
		if((tablica[ii]>='a' && tablica[ii]<='z' || tablica[ii]>='A' && tablica[ii]<='Z') && kk==1);
		else if(tablica[ii]!=(tablica[ii]>='a' && tablica[ii]<='z' || tablica[ii]>='A' && tablica[ii]<='Z') && kk==1) kk=0;
		else if((tablica[ii]>='a' && tablica[ii]<='z' || tablica[ii]>='A' && tablica[ii]<='Z') && kk==0)
		{
			kk=1;
			wyrazy+=kk;
		}
	}
	printf("Ilosc wyrazow: %d\n",wyrazy);    // bada iloœc wyrazów (sprawdzenie)
	
	char tab[wyrazy];
	int zmienna=0;
	int EL,dlugosc=0;
	for(EL=0;EL<len-1;EL++)
	{	
		if(tablica[EL]>='a' && tablica[EL]<='z' || tablica[EL]>='A' && tablica[EL]<='Z')
		{
			dlugosc+=1;
			tab[zmienna]=dlugosc;
		}
		else if(tablica[EL]!=(tablica[EL]>='a' && tablica[EL]<='z' || tablica[EL]>='A' && tablica[EL]<='Z'))
		{
			tab[zmienna]=dlugosc;
			dlugosc=0;
			zmienna++;
		}
	}                     // patrzymy jaka dlugosc maja te wyrazy
	for(ii=0;ii<wyrazy;ii++)
	{
		printf("Dlugosc: %d\n",tab[ii]); // sprawdzenie
	}
	int jp;
	char tab2[wyrazy];
	int d=0;
	for(ii=0;ii<wyrazy;ii++)
	{	
		for(jp=0;jp<wyrazy;jp++)
		{
			if(tab[ii]==tab[jp]) d+=1;
		}
		tab2[ii]=d;
		d=0;
	}
	for(ii=0;ii<wyrazy;ii++)
	{	
		printf("%d-%d\n",tab[ii],tab2[ii]);    // drukuje nam wyniki lecz powtarzajace sie
	}
	return 0;
}
