#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int add(const char* number1, const char* number2, char* result, int size)
{
	if(number1==NULL || number2==NULL || result==NULL) return 1;
	if(size<=0) return 1;
	int g=validate(number1);
	if(g==-1 || g==0) return 1;
	g=validate(number2);
	if(g==-1 || g==0) return 1;
	
	
	int n1_len=0;
	int n2_len=0;
	const char* znak1=number1;
	const char* znak2=number2;
	char *backup_result=result;
	for(;*znak1!='\0';znak1++) n1_len++;
	for(;*znak2!='\0';znak2++) n2_len++;
	int max;
	if(n1_len>n2_len) max=n1_len;
	else if(n1_len<=n2_len) max=n2_len;
	if(max>=size) return 2;
	znak1=number1;
	znak2=number2;
	for(;*(znak1+1)!='\0';znak1++);  // ustawiamy wskazniki na ostatnie wyrazy (zaraz przed terminatorem)
	for(;*(znak2+1)!='\0';znak2++);
	
	int flaga_1=0;
	int flaga_2=0;
	int bonus=0;
	int rozmiar_result=0;
	
	for(;max>0;max--,n1_len--,n2_len--,znak1--,znak2--,result++,rozmiar_result++)
	{
			if(n1_len==0) flaga_1=1;
			if(n2_len==0) flaga_2=1;
			
			int a=0;
			int b = 0;
	
	
			if(flaga_1==0)
			{
				a = *znak1 - '0';
	
			}
			if(flaga_2==0)
			{
				b = *znak2 - '0';
			}
	    //printf("%d %d\n",a,b);
	    int wynik=a+b+bonus;
	    if(wynik>=10)
	    {
	      bonus=1;
	      int reszta=wynik%10;
	      *result=reszta+'0';
	    }
	    else
	    {
	      bonus=0;
	      *result=wynik+'0';
	    }

	}
	if(bonus==1)
	{
		*result=1+'0';
		result++;
		rozmiar_result++;
	}
	if(rozmiar_result>=size) return 2;
  	*result='\0';
  	result=backup_result;
  	int i,j;
  	for(j=0;j<rozmiar_result;j++)
  	{
  		for(i=0;i<rozmiar_result-1-j;i++)
  		{
  			char temp=*(result+1);
			*(result+1)=*result;
			*result=temp;
			result++;	
		  }
      result=backup_result;
	  }
	return 0;
}

int validate(const char * number)
{
	if(number==NULL) return -1;
	if(*number=='\n') return 0;
	int len=0;
	const char *znak=number;
	for(;*znak!='\0';znak++) len++;
	if(*number=='0' && len==1) return 1;
	if(*number=='0' && *(number+1)!='0') return 0;
	int i,flaga=0;
	for(i=0;*number!='\0';number++,i++)
	{
		if(isdigit(*number)==0) return 0;
		if(i==0 && *number=='0') flaga=1;
		else if(isdigit(*number) && *number!='0' && flaga==1) return 0;
	}
	return 1;
}

int main ()
{
	char tab1[201]={0};
	printf("Podaj tekst: ");
	scanf("%200[^\n]s",tab1);
	int c = getchar();
  	if (c != '\n') 
	{
	    while (c != '\n')   c = getchar();
  	}
	char tab2[201]={0};
	printf("Podaj tekst: ");
	scanf("%200[^\n]s",tab2);
	char result[202]={0};
  	int g=add(tab1,tab2,result,202);
  	if(g==1 || g==2) return printf("Incorrect input\n"),1;
  	printf("%s",result);
	
	return 0;
}
