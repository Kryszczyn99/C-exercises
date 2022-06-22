#include <stdio.h>

int sum_of_digits(long long number);
int is_divisible_by_3(int number);

int main()
{
	printf("Podaj liczbe: ");
	long long liczba;
	if(scanf("%lld",&liczba)!=1)   return printf("Incorrect input\n"),1;
	int k=is_divisible_by_3(liczba);
	if(k==1)   return printf("YES\n"),0;
	printf("NO\n");
	return 0;
}

int sum_of_digits(long long number)
{
	if(number==0)	return 0;
	if(number<0)	number=-1*number;
	return  sum_of_digits(number/10)+number%10 ;
}

int is_divisible_by_3(int number)
{
	int x=sum_of_digits(number);
	if(x==0 ||x==3 ||x==6 ||x==9 ||x==12 ||x==15 ||x==18 ||x==21 ||x==24 ||x==27 ||x==30 ||x==33 ||x==36 ||x==39 ||x==42 ||x==45 ||x==48 ||x==51 ||x==54 ||x==57 ||x==60 ||x==63 ||x==66 ||x==69 ||x==72 ||x==75 ||x==78 ||x==81 ||x==84 ||x==87 ||x==90 ||x==93 ||x==96 ||x==99 ||x==102 ||x==105 ||x==108 ||x==111 ||x==114 ||x==117)	return 1;
	return 0;
}
