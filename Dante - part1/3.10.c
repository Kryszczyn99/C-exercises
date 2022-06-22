#include <stdio.h>

int main (){
	int a;
	printf("Podaj liczbe: ");
	scanf("%d",&a);
	switch((a==1 || a==2 || a==3 || a==4 || a==5 )+2*(a==6 || a==7)){
					case 1:
			printf("Dzien roboczy");
			break;
					case 2:
			printf("Weekend");
			break;
					default:
			printf("Incorrect input");
			return 1;
	}
	
	
	return 0;
}
