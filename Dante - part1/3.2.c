#include <stdio.h>

int main (){
	int a;
	printf("Podaj liczbe: ");
	scanf("%d",&a);
	switch((a==1)+2*(a==2)+3*(a==3)+4*(a==4)+5*(a==5)+6*(a==6)+7*(a==7)+8*(a==8)+9*(a==9)+10*(a==10)+11*(a==11)+12*(a==12)){
					case 1:
			printf("Styczen");
			break;
					case 2:
			printf("Luty");
			break;
					case 3:
			printf("Marzec");
			break;
					case 4:
			printf("Kwiecien");
			break;
					case 5:
			printf("Maj");
			break;
					case 6:
			printf("Czerwiec");
			break;
					case 7:
			printf("Lipiec");
			break;
					case 8:
			printf("Sierpien");
			break;
					case 9:
			printf("Wrzesien");
			break;
					case 10:
			printf("Pazdziernik");
			break;
					case 11:
			printf("Listopad");
			break;
					case 12:
			printf("Grudzien");
			break;
					default:
			printf("Incorrect input");
			return 1;
	}
	
	
	return 0;
}
