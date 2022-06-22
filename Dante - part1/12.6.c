#include <stdio.h>

int is_balanced(unsigned long long a)
{
	int k=a+a;
	int liczba_P=0;
	int liczba_NP=0;
	int i;
	for(i=1;i<k;i++)
	{
		 if((a)%i==0)
		 {
		 	if(i%2==0) liczba_P+=1;
		 	else if(i%2==1) liczba_NP+=1;
		 }
	}
	if(liczba_P==liczba_NP) return 1;
	return 0;
}

int main ()
{
	printf("Podaj liczbe: \n");
	long long a;
	int y=scanf("%lld",&a);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(a<=0)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(is_balanced(a)==1)
	{
		printf("%lld",a+4);
		return 0;
	}
		int k=a+a;
		int liczba_P=0;
		int liczba_NP=0;
		int i;
		punkt:
		for(i=1;i<k;i++)
		{
			 if((a+1)%i==0)
			 {
			 	if(i%2==0) liczba_P+=1;
			 	else if(i%2==1) liczba_NP+=1;
			 }
		}
		if(liczba_P==liczba_NP) 
		{
			printf("%lld",a+1);
			return 0;
		}
		a+=1;
		liczba_P=0;
		liczba_NP=0;
		goto punkt;
}
