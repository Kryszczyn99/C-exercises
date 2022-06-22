#include <stdio.h>
#include <ctype.h>
//w tym zadaniu jest 2477 elementow

int main ()
{
	char tab[31]={0};
	printf("Podaj sciezke do pliku: ");
	scanf("%30[^\n]s",tab);
	FILE *plik;
	plik=fopen(tab,"r");
	if(plik==NULL) return printf("Couldn't open file\n"),4;
	fseek(plik,0,SEEK_END);
	int dlugosc=ftell(plik);
	int l=0;
	int ilosc_liczb=0;
	char memory;
	while(1)
	{
		char znaczek=0;
		fseek(plik,l,SEEK_SET);
		fscanf(plik,"%c",&znaczek);
		if(isdigit(znaczek)) ilosc_liczb+=1;
		if(isalpha(znaczek) && isdigit(memory))
		{
			fclose(plik);
			return printf("File corrupted"),6;
		} 
		if(isalpha(memory) && isdigit(znaczek))
		{
			fclose(plik);
			return printf("File corrupted"),6;
		} 
		memory=znaczek;
		if(l==dlugosc) break;
		l++;
	}
	
	
	if(ilosc_liczb==0)
	{
		fclose(plik);
		return printf("File corrupted"),6;
	} 	
	
	int k=0;
	int p=0;
	while(1)
	{
		while(1)
		{
			int a=0;
			fseek(plik,k,SEEK_SET);
			fscanf(plik,"%d",&a);
			if(a>=dlugosc)
			{
				fclose(plik);
				return printf("File corrupted"),6;
			} 
			fseek(plik,0,SEEK_SET);
			char znak=0;
			int i=0;
			while(i<=a)
			{
				fscanf(plik,"%c",&znak);
				i++;
			}
			int d=a;
			int len=0;
	  		for(i=0;i<4;i++)
	  		{
		      	int b=d%10;
		      	d=d-b;
		      	d=d/10;
				len+=1;
		      	if(d==0) break;
	  		}
	  		if(p==1)printf("%c",znak);
			k+=len+1;
			fseek(plik,k,SEEK_SET);
			if(fscanf(plik,"%d",&a)==0) break;
		}
		p+=1;
		if(p==2) break;
		k=0;
	}

	fclose(plik);
	return 0;
}
