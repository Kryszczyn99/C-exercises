#include <stdio.h>

void replace(char tab[], char from, char to)
{
	int i;
	int ilosc=0;
	for(i=0;tab[i]!='\0';i++) ilosc++;
	if(tab[0]=='\n')
	{
		printf("%c",to);
		return ;
	} 
	for(i=0;tab[i]!='\0';i++)
	{
		if(tab[i]==from) printf("%c",to);
		else printf("%c",tab[i]);
	}
}
void replace_string(char tab[], const char from[], const char to[])
{
	int i;
	int j;
	int k;
	for(i=0;tab[i]!='\0';i++)
	{
		k=0;
		if(tab[i]==from[0])
		{
			k+=1;
			for(j=1;from[j]!='\0';j++)
			{
				if(tab[i+j]==from[j])	k+=1;
			}
			if(k==3)
			{
				printf(" ");
				i+=2;
			}
		
		}
		if(k!=3) printf("%c",tab[i]);
	}
}

int main ()
{
	printf("Podaj tekst: \n");
	char tab[1000];
	fgets(tab,1000,stdin);
	replace(tab,'a','b');
	char tab1[]={'t','h','e'};
	char tab2[]={' '};
	replace_string(tab,tab1,tab2);
	return 0;
}
