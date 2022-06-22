#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define XX 1001
#define G 0

int main (void)
{
	char tablica[XX];
	printf("Podaj ciag: \n");
	fgets(tablica, XX, stdin);
	int len=strlen(tablica);
	int ii=G,kk=G,wyrazy=G;
	while(ii<len-1)
	{
		if(isalpha(tablica[ii]) && kk==1);
		else if(!isalpha(tablica[ii]) && kk==1) kk=G;
		else if(isalpha(tablica[ii]) && kk==G)
		{
			kk=1;
			wyrazy+=kk;
		}
		ii=ii+1;
	}
	printf("%d\n",wyrazy);
	return G;
}
