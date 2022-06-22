#include <stdio.h>
#include <ctype.h>

int decode(const char *input, const char *output); // dwojkowy na dziesietny
int encode(const char *input, const char *output); //dziesietny na dwojkowy


int main ()
{
	printf("Podaj operacje (D/E): ");
	char znak;
	int y=scanf("%c",&znak);
	if(y!=1 || (znak!='E' && znak!='e' && znak!='d' && znak!='D')) return printf("Incorrect input data\n"),2;
	char input[30];
	char output[30];
	printf("Podaj wejsciowy folder: ");
	int c=getchar();
	if(c!='\n') while(c!='\n') c=getchar();
	scanf("%29[^\n]s",input);
	printf("Podaj wyjsciowy folder: ");
	c=getchar();
	if(c!='\n') while(c!='\n') c=getchar();
	scanf("%29[^\n]s",output);
	if(znak=='D' || znak=='d')
	{
		int result=decode(input,output);
		if(result==1) return printf("Incorrect input"),1;
		if(result==2) return printf("Couldn't open file"),4;
		if(result==3) return printf("File corrupted"),6;
		if(result==4) return printf("Couldn't create file"),5;
		printf("File saved");
		
	}
	else if(znak=='E' || znak=='e')
	{
		int result=encode(input,output);
		if(result==1) return printf("Incorrect input"),1;
		if(result==2) return printf("Couldn't open file"),4;
		if(result==3) return printf("File corrupted"),6;
		if(result==4) return printf("Couldn't create file"),5;
		printf("File saved");
	}
	return 0;
}

int decode(const char *input, const char *output)
{
	if(input==NULL || output==NULL) return 1;
	FILE *f1;
	f1=fopen(input,"r");
	if(f1==NULL) return 2;
	char znak1,znak2,znak3,znak4,znak5,znak6,znak7,znak8;
	int k=0;
	while(1)
	{
		int y=fscanf(f1,"%c",&znak1);
		if(y!=1)
		{
			if(k==0)
			{
				fclose(f1);
				return 3;
			} 
			else break;
		}
		y=fscanf(f1,"%c",&znak2);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak3);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak4);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak5);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak6);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak7);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak8);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		if((znak1!='1' && znak1!='0') || (znak2!='1' && znak2!='0') || (znak3!='1' && znak3!='0') || (znak4!='1' && znak4!='0') || (znak5!='1' && znak5!='0') || (znak6!='1' && znak6!='0') || (znak7!='1' && znak7!='0') || (znak8!='1' && znak8!='0'))
		{
			fclose(f1);
			return 3;
		}
		k=1;
	}
	FILE *f2;
	f2=fopen(output,"w");
	if(f2==NULL)
	{
		fclose(f1);
		return 4;
	}
	fseek(f1,0,SEEK_SET);
	while(1)
	{
		int wynik=0;
		int y=fscanf(f1,"%c",&znak1);
		if(y!=1)
		{
			break;
		}
		fscanf(f1,"%c",&znak2);
		fscanf(f1,"%c",&znak3);
		fscanf(f1,"%c",&znak4);
		fscanf(f1,"%c",&znak5);
		fscanf(f1,"%c",&znak6);
		fscanf(f1,"%c",&znak7);
		fscanf(f1,"%c",&znak8);
		if(znak1=='1') wynik+=128;
		if(znak2=='1') wynik+=64;
		if(znak3=='1') wynik+=32;
		if(znak4=='1') wynik+=16;
		if(znak5=='1') wynik+=8;
		if(znak6=='1') wynik+=4;
		if(znak7=='1') wynik+=2;
		if(znak8=='1') wynik+=1;

		if(wynik>=0 && wynik<=9) fprintf(f2,"00%d",wynik);
		if(wynik>=10 && wynik<=99) fprintf(f2,"0%d",wynik);
		if(wynik>=100 && wynik<=255) fprintf(f2,"%d",wynik);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
int encode(const char *input, const char *output)
{
	if(input==NULL || output==NULL) return 1;
	FILE *f1;
	f1=fopen(input,"r");
	if(f1==NULL) return 2;
	int k=0;
	while(1)
	{
		char znak1,znak2,znak3;
		int y=fscanf(f1,"%c",&znak1);
		if(y!=1)
		{
			if(k==0)
			{
				fclose(f1);
				return 3;
			}
			break;
		}
		y=fscanf(f1,"%c",&znak2);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		y=fscanf(f1,"%c",&znak3);
		if(y!=1)
		{
			fclose(f1);
			return 3;
		}
		int wynik=(znak1-'0')*100+(znak2-'0')*10+(znak3-'0')*1;
		if(wynik>255)
		{
			fclose(f1);
			return 3;
		}
		if(!isdigit(znak1) || !isdigit(znak2) || !isdigit(znak3))
		{
			fclose(f1);
			return 3;
		}
		k=1;
	}
	FILE *f2;
	f2=fopen(output,"w");
	if(f2==NULL)
	{
		fclose(f1);
		return 4;
	}
	fseek(f1,0,SEEK_SET);
	while(1)
	{
		char znak1,znak2,znak3;
		int y=fscanf(f1,"%c",&znak1);
		if(y!=1)
		{
			break;
		}
		y=fscanf(f1,"%c",&znak2);
		y=fscanf(f1,"%c",&znak3);
		int wynik=(znak1-'0')*100+(znak2-'0')*10+(znak3-'0')*1;
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
		while(wynik)
	  	{
		    a=wynik%2;
		    wynik/=2;
		    b=wynik%2;
		    wynik/=2;
		    c=wynik%2;
		    wynik/=2;
		    d=wynik%2;
		    wynik/=2;
		    e=wynik%2;
		    wynik/=2;
		    f=wynik%2;
		    wynik/=2;
		    g=wynik%2;
		    wynik/=2;
		    h=wynik%2;
		    wynik/=2;
	  	}
	  	int i;
	  	for(i=0;i<8;i++)
	  	{
	  		if(i==0) fprintf(f2,"%d",h);
	  		if(i==1) fprintf(f2,"%d",g);
	  		if(i==2) fprintf(f2,"%d",f);
	  		if(i==3) fprintf(f2,"%d",e);
	  		if(i==4) fprintf(f2,"%d",d);
	  		if(i==5) fprintf(f2,"%d",c);
	  		if(i==6) fprintf(f2,"%d",b);
	  		if(i==7) fprintf(f2,"%d",a);
		}
		k=1;
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
