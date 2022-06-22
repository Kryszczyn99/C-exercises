#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define XX 1001
#define G 0

int main(void)
{
    char tablica[XX];
    printf("Podaj ciag: \n");
    fgets(tablica, XX , stdin);
    int len=strlen(tablica);
    int ii=G;
    int k=G,kkk=G;
    while(ii<len-1)
	{
		if((tablica[ii]>='a' && tablica[ii]<='z' || tablica[ii]>='A' && tablica[ii]<='Z') && k==1);
		else if(tablica[ii]!=(tablica[ii]>='a' && tablica[ii]<='z' || tablica[ii]>='A' && tablica[ii]<='Z') && k==1) k=G;
    	else if((tablica[ii]=='a' || tablica[ii]=='A' || tablica[ii]=='e' || tablica[ii]=='E' ||tablica[ii]=='I' || tablica[ii]=='i' || tablica[ii]=='O' || tablica[ii]=='o' || tablica[ii]=='U' ||tablica[ii]=='u' || tablica[ii]=='y' || tablica[ii]=='Y' ) && (tablica[ii+1]=='a' || tablica[ii+1]=='A' || tablica[ii+1]=='e' || tablica[ii+1]=='E' ||tablica[ii+1]=='I' || tablica[ii+1]=='i' || tablica[ii+1]=='O' || tablica[ii+1]=='o' || tablica[ii+1]=='U' ||tablica[ii+1]=='u' || tablica[ii+1]=='y' || tablica[ii+1]=='Y' ))
    	{
    		k+=1;
    		kkk=kkk+k;
		}
		ii=ii+1;
	}
    
    printf("%d",kkk);
    return G;
}
