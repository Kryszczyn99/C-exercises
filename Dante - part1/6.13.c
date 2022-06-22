#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define XX 1001
int main (void)
{
	char tablica[XX];
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0;
	int n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
	printf("Podaj tablice: \n");
	fgets(tablica, XX, stdin);
	int len=strlen(tablica);
	int ii;
	for(ii=0;ii<len;ii++)
	{
		if(tablica[ii]=='a' || tablica[ii]=='A') a++;
		else if(tablica[ii]=='b' || tablica[ii]=='B') b++;
		else if(tablica[ii]=='c' || tablica[ii]=='C') c++;
		else if(tablica[ii]=='d' || tablica[ii]=='D') d++;
		else if(tablica[ii]=='e' || tablica[ii]=='E') e++;
		else if(tablica[ii]=='f' || tablica[ii]=='F') f++;
		else if(tablica[ii]=='g' || tablica[ii]=='G') g++;
		else if(tablica[ii]=='h' || tablica[ii]=='H') h++;
		else if(tablica[ii]=='i' || tablica[ii]=='I') i++;
		else if(tablica[ii]=='j' || tablica[ii]=='J') j++;
		else if(tablica[ii]=='k' || tablica[ii]=='K') k++;
		else if(tablica[ii]=='l' || tablica[ii]=='L') l++;
		else if(tablica[ii]=='m' || tablica[ii]=='M') m++;
		else if(tablica[ii]=='n' || tablica[ii]=='N') n++;
		else if(tablica[ii]=='o' || tablica[ii]=='O') o++;
		else if(tablica[ii]=='p' || tablica[ii]=='P') p++;
		else if(tablica[ii]=='q' || tablica[ii]=='Q') q++;
		else if(tablica[ii]=='r' || tablica[ii]=='R') r++;
		else if(tablica[ii]=='s' || tablica[ii]=='S') s++;
		else if(tablica[ii]=='t' || tablica[ii]=='T') t++;
		else if(tablica[ii]=='u' || tablica[ii]=='U') u++;
		else if(tablica[ii]=='v' || tablica[ii]=='V') v++;
		else if(tablica[ii]=='w' || tablica[ii]=='W') w++;
		else if(tablica[ii]=='x' || tablica[ii]=='X') x++;
		else if(tablica[ii]=='y' || tablica[ii]=='Y') y++;
		else if(tablica[ii]=='z' || tablica[ii]=='Z') z++;
		
	}
	printf("a-%d\n",a);
	printf("b-%d\n",b);
	printf("c-%d\n",c);
	printf("d-%d\n",d);
	printf("e-%d\n",e);
	printf("f-%d\n",f);
	printf("g-%d\n",g);
	printf("h-%d\n",h);
	printf("i-%d\n",i);
	printf("j-%d\n",j);
	printf("k-%d\n",k);
	printf("l-%d\n",l);
	printf("m-%d\n",m);
	printf("n-%d\n",n);
	printf("o-%d\n",o);
	printf("p-%d\n",p);
	printf("q-%d\n",q);
	printf("r-%d\n",r);
	printf("s-%d\n",s);
	printf("t-%d\n",t);
	printf("u-%d\n",u);
	printf("v-%d\n",v);
	printf("w-%d\n",w);
	printf("x-%d\n",x);
	printf("y-%d\n",y);
	printf("z-%d\n",z);
	
	
	return 0;
}
