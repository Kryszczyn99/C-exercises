#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int a)
{
	int b;
	for(b=2;b<=sqrt(a);b++)
	{
		if(a%b==0)
		return 0;
	}
	if(a<=1)
		return 0;
	return 1;
}

int main()
{
	int a,b;
	printf("Podaj poczatek przedzialu: ");
	if (scanf("%d",&a)!=1) 
	{
        printf("Incorrect input");
        return 1;
    }
	printf("Podaj koniec przedzialu: ");
	if (scanf("%d",&b)!=1||b<a) 
	{
        printf("Incorrect input");
        return 1;
    }
    int i,c=0;
	for(i=a;i<=b;i++)
	{
		if(is_prime(i)==1)
		{
			printf("%d ",i);
			c+=1;
		}
	}
	if(c==0)
	{
		printf("Nothing to show\n");
	}
	return 0;
}
