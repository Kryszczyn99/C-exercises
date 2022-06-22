#include <stdio.h>

int main (){
	int a;
	printf("Podaj liczbe: ");
	scanf("%d",&a);
	switch((a==1)+2*(a==2)+3*(a==3)+4*(a==4)+5*(a==5)+6*(a==6)+7*(a==7)){
					case 1:
			printf("poniedzialek");
			break;
					case 2:
			printf("wtorek");
			break;
					case 3:
			printf("sroda");
			break;
					case 4:
			printf("czwartek");
			break;
					case 5:
			printf("piatek");
			break;
					case 6:
			printf("sobota");
			break;
					case 7:
			printf("niedziela");
			break;
					default:
			printf("Incorrect input");
			return 1;
	}
	
	
	return 0;
}
