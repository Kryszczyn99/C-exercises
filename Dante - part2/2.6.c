#include <stdio.h>

int my_strlen(const char* str)
{
	if(str==NULL) return -1;
	int dlugosc=0;
	for(;*str!='\0';str++,dlugosc++);
	return dlugosc; 
}

char* my_strcat(char* dest, const char* src)
{
	if(dest==NULL) return NULL;
	if(src==NULL) return NULL;
	int len=my_strlen(dest);
	for(int i=0;*(src+i);i++)   *(dest+len+i) = *(src+i);
	*(dest+len+i)='\0';
	return dest;  //+len+i
}

char* my_strcpy(char* dest, const char* src)
{
	if(dest==NULL) return NULL;
	if(src==NULL) return NULL;
	for(int i=0;*(src+i);i++)   *(dest+i) = *(src+i);
	*(dest+i)='\0';
	return dest; //+i
}

int main ()
{
	char txt1[1001]={0};
	char txt2[2001]={0};
	printf("Podaj tekst: ");
	scanf("%1000[^\n]s",txt1);
	int c = getchar();
  	if (c != '\n') 
	{
	    while (c != '\n')   c = getchar();
  	}
  	printf("Podaj drugi tekst: ");
  	scanf("%1000[^\n]s",txt2);
  	c = getchar();
  	if (c != '\n')
	{
	    while (c != '\n')   c = getchar();
  	}
  	
  	
	int g=my_strlen(txt1);
	if(g==-1) return printf("Incorrect input\n"),1;
	int p=my_strlen(txt2);
	if(p==-1) return printf("Incorrect input\n"),1;
	printf("%d %d\n",g,p);
	
	
	char *pointer = my_strcat(txt2,txt1);
	if(pointer==NULL) return printf("Incorrect input\n"),1;
	for(;*pointer!='\0';pointer++) printf("%c",*pointer);
	printf("\n");

	pointer = my_strcpy(txt2,txt1);
	if(pointer==NULL) return printf("Incorrect input\n"),1;
	for(;*pointer!='\0';pointer++) printf("%c",*pointer);
	return 0;
}
