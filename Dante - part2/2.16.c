#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char *rekurencja(const char *expr)
{
	if(*(expr+1)=='\0') return expr;
	return rekurencja(expr+1);
}

int rekurencja_v2(const char *expr)
{
	if((*expr=='/' || *expr=='-' || *expr=='+' || *expr=='*') && (*(expr+1)=='/' || *(expr+1)=='-' || *(expr+1)=='+' || *(expr+1)=='*')) return -1;
	if(*expr=='/' && *(expr+1)=='0') return -1;
	if(*(expr+1)=='\0') return 0;
	return rekurencja_v2(expr+1);
}

int validate_expression(const char *expr)
{
	if(expr==NULL) return -1;
	int len=strlen(expr);
	int p=strspn(expr,"1234567890/*-+");
	if(len!=p) return 0;
	const char *backup=expr;
	int k=strspn(expr,"1234567890");
	if(k==0) return 0;
	const char *value=rekurencja(backup);
	int u=strspn(value,"/*-+");
	if(u!=0) return 0;
	int value1=rekurencja_v2(expr);
	if(value1==-1) return 0;
	return 1;
}

int rekurencja_v3(const char* expr, float *result, char dzialanie, float liczba)
{
	if(*expr=='\0')
	{	
		if(dzialanie=='/') *result/=liczba;
		else if(dzialanie=='+') *result+=liczba;
		else if(dzialanie=='-') *result-=liczba;
		else if(dzialanie=='*') *result*=liczba;
		return 0;
	}
	if(*expr=='/') 
	{	
		if(dzialanie=='/') *result/=liczba;
		else if(dzialanie=='+') *result+=liczba;
		else if(dzialanie=='-') *result-=liczba;
		else if(dzialanie=='*') *result*=liczba;
		else *result=liczba;
		dzialanie='/';
		liczba=0;
	}
	else if(*expr=='+')
	{	
		if(dzialanie=='/') *result/=liczba;
		else if(dzialanie=='+') *result+=liczba;
		else if(dzialanie=='-') *result-=liczba;
		else if(dzialanie=='*') *result*=liczba;
		else *result=liczba;
		liczba=0;
		dzialanie='+';
	} 
	else if(*expr=='-')
	{	
		if(dzialanie=='/') *result/=liczba;
		else if(dzialanie=='+') *result+=liczba;
		else if(dzialanie=='-') *result-=liczba;
		else if(dzialanie=='*') *result*=liczba;
		else *result=liczba;
		liczba=0;
		dzialanie='-';
	} 
	else if(*expr=='*')
	{	
		if(dzialanie=='/') *result/=liczba;
		else if(dzialanie=='+') *result+=liczba;
		else if(dzialanie=='-') *result-=liczba;
		else if(dzialanie=='*') *result*=liczba;
		else *result=liczba;
		dzialanie='*';
		liczba=0;
	}
	if(isdigit(*expr))
	{
		int number=*expr-'0';
		liczba+=number*1.0;
		if(isdigit(*(expr+1))) liczba*=10;
	}
	return rekurencja_v3(expr+1,result,dzialanie,liczba);
}

int calculate(const char* expr, float *result)
{
	if(expr==NULL || result==NULL) return 0;
	int y=validate_expression(expr);
	if(y==-1 || y==0) return 0;
	int k=strspn(expr,"1234567890");
	int p=strlen(expr);
	if(k==p)
	{
		*result=atof(expr);
		return 1;
	}
	char dzialanie=0;
	float liczba=0;
	rekurencja_v3(expr,result,dzialanie,liczba);
	return 1;
}


int main ()
{
	char tab[201]={0};
	printf("Podaj tekst: ");
	scanf("%200[^\n]s",tab);
	float wynik;
	float *res;
	res=&wynik;
	//int g=validate_expression(tab);
	//if(g==-1 || g==0) return printf("Incorrect input\n"),1;
	int p=calculate(tab,res);
	if(p==0) return printf("Incorrect input\n"),1;
	printf("%.2f\n",wynik);
	return 0;
}
