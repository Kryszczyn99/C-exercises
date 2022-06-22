#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_sequence_length(const char tab[], int id);
int count_sequences(const char tab[]);

int main ()
{
	printf("Podaj tekst: \n");
	char tab1[200];
	fgets(tab1,200,stdin);
	int i;
	for(i=0;tab1[i]!='\0';i++)
	{
		if(isalpha(tab1[i]))
		{
			printf("Incorrect input\n");
			return 1;
		}
	}
	int len=strlen(tab1);
	char tab[200];
	for(i=0;i<len-1;i++) tab[i]=tab1[i]; 
	int wynik1=count_sequences(tab);
	printf("%d\n",wynik1);
	int p=get_sequence_length(tab,0);
  printf("%d\n",p);
	return 0;
}

int get_sequence_length(const char tab[], int id)
{
	int ilosc=0;
	int i;
	int len=strlen(tab);
	if(len==0) return -1;
	for(i=0;i<len;i++)
	{
		if(isalpha(tab[i])) return -1;
	}
	if(id==1)
	{
		for(i=0;tab[i]!='\0';i++)
		{
			if(tab[i]=='1') ilosc++;
			if(tab[i]=='-')
			{
				if(tab[i+1]=='1')
				{
					ilosc++;
					i+=1;
				}
			}
		}
	}
	if(id==0)
	{
    int v=-1;
    int back_up;
		for(i=0;tab[i]!='\0';i++)
		{

			if(tab[i]=='1')
      {
        ilosc++;
        v=1;
      } 
			if(tab[i]=='-')
			{
				if(tab[i+1]=='1')
				{
					ilosc++;
					i+=1;
          v=1;
				}
			}
      if(v==1 && tab[i]!='1')
      {
        v=-1;
        back_up=ilosc;
        ilosc=0;
        return back_up;	
    }
		}
		if(ilosc==0) return -1;
			
	}
	return ilosc;
}


int count_sequences(const char tab[])
{
	int i;
	int k=0;
	int ilosc=0;
	int dlugosc=0;
	dlugosc=strlen(tab);
	if(dlugosc==1 && tab[0]=='\n') return -1;
	for(i=0;tab[i]!='\0';i++)
	{
		if(isalpha(tab[i])) return -1;
		if(tab[i]=='1' && k==0)
		{
			k=1;
			ilosc++;
		}
		if(tab[i]=='-')
		{
			if(tab[i+1]=='1' && k==0)
			{
				k=1;
				ilosc++;
				i+=1;
			} 
		}
		if(tab[i]!='1') k=0;
		if(tab[i]=='\n') return -1;
	}
	return ilosc;
}
