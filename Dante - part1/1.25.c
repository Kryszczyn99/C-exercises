#include <stdio.h>

int main (void)
{
	int t1,t2,t3,k1,k2,t4,t5,t6,t7;
	printf("Podaj numer telefonu w formacie ddd-dd-dd: ");
	scanf("%1d%1d%1d-%1d%1d-%1d%1d",&t1,&t2,&t3,&t4,&t5,&t6,&t7);
	printf("Podaj numer kierunkowy format dd: ");
	scanf("%1d%1d",&k1,&k2);
	printf("(%1d%1d) %1d%1d%1d-%1d%1d-%1d%1d",k1,k2,t1,t2,t3,t4,t5,t6,t7);
	return 0;
}
