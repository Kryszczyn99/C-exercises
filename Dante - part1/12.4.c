#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main ()
{
	char tablica[1000];
	printf("Podaj tekst: ");
	scanf("%1000[^\n]",tablica);
	int i;
	int k=0;
	int  b=0;
	int len = strlen(tablica);
	int len2=0;
	for(i=0;i<len;i++) if(!isalpha(tablica[i])) len2+=1;
	int len3=len-len2;
	char tablica2[len3];
	for(i=0;tablica[i]!='\0';i++)
	{
		if(isalpha(tablica[i]) && k==0)
		{
			if(isupper(tablica[i]))
			{
				tablica2[b]=tablica[i];
				b+=1;
			}
			else
			{
				tablica2[b]=toupper(tablica[i]);
				b+=1;
			}
			k=1;
		}
		else if(isalpha(tablica[i]) && k==1)
		{
			if(islower(tablica[i]))
			{
				tablica2[b]=tablica[i];
				b+=1;
			}
			else
			{
				tablica2[b]=tolower(tablica[i]);
				b+=1;
			}
		}
		else if (!isalpha(tablica[i])) k=0;
	}
	if(b==0 )
	{
		printf("NothingToShow\n");
		return 0;
	}
	
	for(i=0;i<len3;i++)
	{
		printf("%c",tablica2[i]);
	}
	return 0;
}
