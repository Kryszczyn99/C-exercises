#include <stdio.h>

int is_palindrom(const char *text)
{
	if(text==NULL) return -1;
	const char *znak=text;
	int len=0;
	for(;*text!='\0';text++) len++;
	if(len<=1) return 0;
	text=znak;
	for(;*(text+1)!='\0';text++); // ustawiamy na ostatni element 
	int i;
	for(i=0;i<len/2;i++,text--,znak++)
	{
		if(*znak!=*text) return 0; 
	}
	return 1;
}
char* find_palindrom(char *text, int len)
{
	if(text==NULL) return NULL;
	if(len<=1) return NULL;

	char *znak=text;
	int len_2=0;
	for(;*znak!='\0';znak++,len_2++); 
	if(len_2<len) return NULL; // jeœli dlugosc text jest mniejsza niz len
	int i;
	for(;*text!='\0';text++)
	{
		char *backup=text;
		char tab[3001]={0};
		char *wsk=tab;
		for(i=0;i<len;i++)
		{
			*wsk=*text;
			wsk++;
      text++;
		}
		*wsk='\0';
		int h=is_palindrom(tab);
		if(h==1)
    {
      *text='\0';
      return backup;
    } 
		text=backup;
	}
	return NULL; 
}

int create_palindrom(const char *text, char *out, int size)
{
	if(text==NULL || out==NULL) return 1;
	if(size<=0) return 1;
	const char *znak=text;
	int len=0;
	for(;*znak!='\0';znak++,len++);
	if((2*len)>=size) return 2;
	int i;
	for(i=0;i<len;i++,out++)
	{
		if(i!=0) text++;
		*out=*text;
	}
	for(i=0;i<len;i++,out++)
	{
		if(i!=0) text--;
		*out=*text;
	}
	*out='\0';
	return 0;
}

int main ()
{

	char tab[1001]={0};
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",tab);
	int d = getchar();
  	if (d != '\n') 
	{
	    while (d != '\n')   d = getchar();
  	}
	int g=is_palindrom(tab);
	if(g==1) printf("YES");
	else if(g==0)
	{
		printf("NO\n");
		printf("Co dalej? \n");
		char sign;
		scanf("%c",&sign);
		switch(sign)
		{
			case 'f':
				{
					printf("Podaj dlugosc: ");
					int dlg;
					int y=scanf("%d",&dlg);
					if(y!=1) return printf("Incorrect input\n"),1;
					if(dlg<=0) return printf("Incorrect input data\n"),2;
					char *pointer=find_palindrom(tab,dlg);
	        if(pointer==NULL) printf("Couldn't find\n");
					else for(;*pointer!='\0';pointer++) printf("%c",*pointer);
					break;
				}
			case 'F':
				{
					printf("Podaj dlugosc: ");
					int dlg;
					int y=scanf("%d",&dlg);
					if(y!=1) return printf("Incorrect input\n"),1;
					if(dlg<=0) return printf("Incorrect input data\n"),2;
					char *pointer=find_palindrom(tab,dlg);
	        if(pointer==NULL) printf("Couldn't find\n");
					else for(;*pointer!='\0';pointer++) printf("%c",*pointer);
					break;
				}
			case 'C':
				{
					char tab2[2001]={0};
					int w=create_palindrom(tab,tab2,2001);
					if(w==1 || w==2) return printf("Incorrect input \n"),2;
					printf("%s",tab2);
					break;
				}
			case 'c': 
				{
					char tab2[2001]={0};
					int w=create_palindrom(tab,tab2,2001);
					if(w==1 || w==2) return printf("Incorrect input \n"),2;
					printf("%s",tab2);
					break;
				}
			default: return printf("Incorrect input data\n"),2;
		}   
	return 0;
	} 
	else return printf("Incorrect input\n"),1;
}
