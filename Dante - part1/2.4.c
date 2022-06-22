#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int re,in;
	char op;
	printf("Podaj liczbe zespolona: ");
	int c=scanf("%d%ci%d",&re,&op,&in);
	if(c!=3 || (op!='+' && op !='-') || in<0)
	{
		printf("Incorrect input\n");
		return 1;
	}
	int sgn= 1; if(op=='-') sgn=-1;
	printf("Czesc rzeczywista: %d\n", re);
	printf("Czesc urojona: %d\n",sgn*in);
	
	return 0;
}
