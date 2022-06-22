#include <stdio.h>
#include <string.h>

int main ()
{
	int i;
	char tab1[100];
  printf("Podaj dzialanie: \n");
  char op[3];
  int tablica[30];
  int tablica1[30];
	scanf("%100[^\n]",tab1);
	while(getchar()!='\n');
	char tab2[100];
	scanf("%100[^\n]",tab2);
	while(getchar()!='\n');
	char tab3[100];
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
  int zmienna1=0;
  if(tablica[0]==1) zmienna1=1;
  else if(tablica[0]==2) zmienna1=2;
  else if(tablica[0]==3) zmienna1=3;
  else if(tablica[0]==4) zmienna1=4;
  else if(tablica[0]==5) zmienna1=5;
  else if(tablica[0]==6) zmienna1=6;
  else if(tablica[0]==7) zmienna1=7;
  else if(tablica[0]==8) zmienna1=8;
  else if(tablica[0]==9) zmienna1=9;
  else if(tablica[0]==0) zmienna1=0;

  if(zmienna1!=0)
  {
    for(i=1;i<ilosc;i++)
    {
        if(tablica[i]==1)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+1;
        }
        else if(tablica[i]==2)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+2;
        }
        else if(tablica[i]==3)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+3;
        }
        else if(tablica[i]==4)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+4;
        }
        else if(tablica[i]==5)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+5;
        }
        else if(tablica[i]==6)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+6;
        }
        else if(tablica[i]==7)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+7;
        }
        else if(tablica[i]==8)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+8;
        }
        else if(tablica[i]==9)
        {
          zmienna1=zmienna1*10;
          zmienna1=zmienna1+9;
        }
        else if(tablica[i]==0)
        {
          zmienna1=zmienna1*10;
        }
    }
  }
  int zmienna2=0;
  if(tablica1[0]==1) zmienna2=1;
  else if(tablica1[0]==2) zmienna2=2;
  else if(tablica1[0]==3) zmienna2=3;
  else if(tablica1[0]==4) zmienna2=4;
  else if(tablica1[0]==5) zmienna2=5;
  else if(tablica1[0]==6) zmienna2=6;
  else if(tablica1[0]==7) zmienna2=7;
  else if(tablica1[0]==8) zmienna2=8;
  else if(tablica1[0]==9) zmienna2=9;
  else if(tablica1[0]==0) zmienna2=0;

  if(zmienna2!=0)
  {
    for(i=1;i<ilosc1;i++)
    {
        if(tablica1[i]==1)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+1;
        }
        else if(tablica1[i]==2)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+2;
        }
        else if(tablica1[i]==3)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+3;
        }
        else if(tablica1[i]==4)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+4;
        }
        else if(tablica1[i]==5)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+5;
        }
        else if(tablica1[i]==6)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+6;
        }
        else if(tablica1[i]==7)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+7;
        }
        else if(tablica1[i]==8)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+8;
        }
        else if(tablica1[i]==9)
        {
          zmienna2=zmienna2*10;
          zmienna2=zmienna2+9;
        }
        else if(tablica1[i]==0)
        {
          zmienna2=zmienna2*10;
        }
    }
  }
  int wynik;
  if(op[0]=='+')  wynik=zmienna1+zmienna2;
  else if(op[0]=='-') wynik=zmienna1-zmienna2;
  else if(op[0]=='*') wynik=zmienna1*zmienna2;
  else if(op[0]=='/') wynik=zmienna1/zmienna2;

  int tabliczka[7];
  int b;
  int d=wynik;
  for(i=7;i>=0;i--)
  {
      b=d%10;
      tabliczka[i]=b;
      d=d-b;
      d=d/10;
      if(d==0) break;
  }
  int backup=i-1;
  int j;
  if(i>=0)
  {
    for(j=backup;j>=0;j--)
    {
      tabliczka[j]=0;
    }

  }
  if(wynik==0)
  {
    printf(" _ \n| |\n|_|\n");
    return 0;
  }
  int g=0,h=0;
  int help=0;
  if(wynik>0)
  {
    for(g=0;g<3;g++)
    {
        for(h=0;h<8;h++)
        {
            if(tabliczka[h]==0 && help==0) continue;
            else if(g==0)
            {
                if(tabliczka[h]==1) printf("   ");
                else if(tabliczka[h]==2) printf(" _ ");
                else if(tabliczka[h]==3) printf(" _ ");
                else if(tabliczka[h]==4) printf("   ");
                else if(tabliczka[h]==5) printf(" _ ");
                else if(tabliczka[h]==6) printf(" _ ");
                else if(tabliczka[h]==7) printf(" _ ");
                else if(tabliczka[h]==8) printf(" _ ");
                else if(tabliczka[h]==9) printf(" _ ");
                else if(tabliczka[h]==0) printf(" _ ");
                help=1;
            }
            else if(g==1)
            {
                if(tabliczka[h]==1) printf("  |");
                else if(tabliczka[h]==2) printf(" _|");
                else if(tabliczka[h]==3) printf(" _|");
                else if(tabliczka[h]==4) printf("|_|");
                else if(tabliczka[h]==5) printf("|_ ");
                else if(tabliczka[h]==6) printf("|_ ");
                else if(tabliczka[h]==7) printf("  |");
                else if(tabliczka[h]==8) printf("|_|");
                else if(tabliczka[h]==9) printf("|_|");
                else if(tabliczka[h]==0) printf("| |");
                help=1;
            }
            else if(g==2)
            {
                if(tabliczka[h]==1) printf("  |");
                else if(tabliczka[h]==2) printf("|_ ");
                else if(tabliczka[h]==3) printf(" _|");
                else if(tabliczka[h]==4) printf("  |");
                else if(tabliczka[h]==5) printf(" _|");
                else if(tabliczka[h]==6) printf("|_|");
                else if(tabliczka[h]==7) printf("  |");
                else if(tabliczka[h]==8) printf("|_|");
                else if(tabliczka[h]==9) printf(" _|");
                else if(tabliczka[h]==0) printf("|_|");
                help=1;
            }
            if(h==7) break;
            printf(" ");
        }
        printf("\n");
        help=0;
    }
  }
  if(wynik<0)
  {
    for(g=0;g<3;g++)
    {
        if(g==0) printf("    ");
        if(g==1)  printf(" -  ");
        if(g==2)  printf("    ");
        for(h=0;h<8;h++)
        {
            if(tabliczka[h]==0 && help==0) continue;
            else if(g==0)
            {
                if(tabliczka[h]==1) printf("   ");
                else if(tabliczka[h]==2) printf(" _ ");
                else if(tabliczka[h]==3) printf(" _ ");
                else if(tabliczka[h]==4) printf("   ");
                else if(tabliczka[h]==5) printf(" _ ");
                else if(tabliczka[h]==6) printf(" _ ");
                else if(tabliczka[h]==7) printf(" _ ");
                else if(tabliczka[h]==8) printf(" _ ");
                else if(tabliczka[h]==9) printf(" _ ");
                else if(tabliczka[h]==0) printf(" _ ");
                else if(tabliczka[h]==-1) printf("   ");
                else if(tabliczka[h]==-2) printf(" _ ");
                else if(tabliczka[h]==-3) printf(" _ ");
                else if(tabliczka[h]==-4) printf("   ");
                else if(tabliczka[h]==-5) printf(" _ ");
                else if(tabliczka[h]==-6) printf(" _ ");
                else if(tabliczka[h]==-7) printf(" _ ");
                else if(tabliczka[h]==-8) printf(" _ ");
                else if(tabliczka[h]==-9) printf(" _ ");
                help=1;
            }
            else if(g==1)
            {
                if(tabliczka[h]==1) printf("  |");
                else if(tabliczka[h]==2) printf(" _|");
                else if(tabliczka[h]==3) printf(" _|");
                else if(tabliczka[h]==4) printf("|_|");
                else if(tabliczka[h]==5) printf("|_ ");
                else if(tabliczka[h]==6) printf("|_ ");
                else if(tabliczka[h]==7) printf("  |");
                else if(tabliczka[h]==8) printf("|_|");
                else if(tabliczka[h]==9) printf("|_|");
                else if(tabliczka[h]==0) printf("| |");
                else if(tabliczka[h]==-1) printf("  |");
                else if(tabliczka[h]==-2) printf(" _|");
                else if(tabliczka[h]==-3) printf(" _|");
                else if(tabliczka[h]==-4) printf("|_|");
                else if(tabliczka[h]==-5) printf("|_ ");
                else if(tabliczka[h]==-6) printf("|_ ");
                else if(tabliczka[h]==-7) printf("  |");
                else if(tabliczka[h]==-8) printf("|_|");
                else if(tabliczka[h]==-9) printf("|_|");
                help=1;
            }
            else if(g==2)
            {
                if(tabliczka[h]==1) printf("  |");
                else if(tabliczka[h]==2) printf("|_ ");
                else if(tabliczka[h]==3) printf(" _|");
                else if(tabliczka[h]==4) printf("  |");
                else if(tabliczka[h]==5) printf(" _|");
                else if(tabliczka[h]==6) printf("|_|");
                else if(tabliczka[h]==7) printf("  |");
                else if(tabliczka[h]==8) printf("|_|");
                else if(tabliczka[h]==9) printf(" _|");
                else if(tabliczka[h]==0) printf("|_|");
                else if(tabliczka[h]==-1) printf("  |");
                else if(tabliczka[h]==-2) printf("|_ ");
                else if(tabliczka[h]==-3) printf(" _|");
                else if(tabliczka[h]==-4) printf("  |");
                else if(tabliczka[h]==-5) printf(" _|");
                else if(tabliczka[h]==-6) printf("|_|");
                else if(tabliczka[h]==-7) printf("  |");
                else if(tabliczka[h]==-8) printf("|_|");
                else if(tabliczka[h]==-9) printf(" _|");
                help=1;
            }
            if(h==7) break;
            printf(" ");
        }
        printf("\n");
        help=0;
    }
  }
	return 0;
}

