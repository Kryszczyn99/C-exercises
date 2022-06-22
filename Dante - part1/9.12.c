#include <stdio.h>
#include <string.h>

int main ()
{
	int i;
	printf("Podaj dzialanie: \n");
	char tab1[100];
  	char op[3];
  	int tablica[30];
  	int tablica1[30];
  	printf("Podaj dzialanie: \n");
	scanf("%100[^\n]",tab1);
	while(getchar()!='\n');
	char tab2[100];
	printf("Podaj dzialanie: \n");
	scanf("%100[^\n]",tab2);
	while(getchar()!='\n');
	char tab3[100];
	printf("Podaj dzialanie: \n");
	
	scanf("%100[^\n]",tab3);
	while(getchar()!='\n');
  int len1=0,len2=0,len3=0;
  for(i=0;tab1[i]!='\0';i++) len1+=1;
  for(i=0;tab2[i]!='\0';i++) len2+=1;
  for(i=0;tab3[i]!='\0';i++) len3+=1;
  int ilosc=0;
  for(i=0;i<len1;i+=4)
  {
    if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|')
    {
      tablica[ilosc]=1; // To jest liczba 1
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]==' ')
    {
      tablica[ilosc]=2; // To jest tablica 2
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=3; // To jest tablica 3
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=4; // To jest tablica 4
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=5; // To jest tablica 5
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]==' ' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=6; // To jest tablica 6
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=7; // To jest tablica 7
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=8; // To jest tablica 8
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=9; // To jest tablica 9
      ilosc+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica[ilosc]=0; // To jest tablica 0
      ilosc+=1;
    }
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='-' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]==' ') 
    {
      op[0]='-'; // To jest znak -
      break;
    }
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='+' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]==' ') 
    {
      op[0]='+'; // To jest znak +
      break;
    }    
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='*' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]==' ') 
    { 
      op[0]='*'; // To jest znak *
      break;
    }
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='/' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]==' ') 
    {
      op[0]='/'; // To jest znak /
      break;
    }
    
  }
  int backup=i+4;
  int ilosc1=0;
  for(i=i+4;i<len1;i+=4)
  {
    if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|')
    {
      tablica1[ilosc1]=1; // To jest liczba 1
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]==' ')
    {
      tablica1[ilosc1]=2; // To jest tablica 2
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=3; // To jest tablica 3
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]==' ' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=4; // To jest tablica 4
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]==' ' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=5; // To jest tablica 5
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]==' ' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=6; // To jest tablica 6
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]==' ' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]==' ' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=7; // To jest tablica 7
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=8; // To jest tablica 8
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]=='_' && tab2[i+2]=='|' && tab3[i]==' ' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=9; // To jest tablica 9
      ilosc1+=1;
    } 
    else if(tab1[i]==' ' && tab1[i+1]=='_' && tab1[i+2]==' ' && tab2[i]=='|' && tab2[i+1]==' ' && tab2[i+2]=='|' && tab3[i]=='|' && tab3[i+1]=='_' && tab3[i+2]=='|') 
    {
      tablica1[ilosc1]=0; // To jest tablica 0
      ilosc1+=1;
    }
  }
  if(op[0]=='/' && tablica1[0]==0)
  {
    printf("Operation not permitted\n");
    return 4;
  }
  
  for(i=0;i<ilosc;i++) printf("%d",tablica[i]);
  printf("%c",op[0]);
  for(i=0;i<ilosc1;i++) printf("%d",tablica1[i]);




	return 0;
}
