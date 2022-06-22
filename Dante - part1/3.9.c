#include <stdio.h>

int main (){
	int a;
	printf("Podaj liczbe: ");
	scanf("%d",&a);
	switch((a==1)+2*(a==2 || a==3 || a==4 || a==5 )+3*(a==6)){
					case 1:
			printf("Brak promocji do nastepnej klasy");
			break;
					case 2:
			printf("Promocja do nastepnej klasy");
			break;
					case 3:
			printf("Promocja z ocena celujaca");
			break;
					default:
			printf("Wprowadzona ocena jest niepoprawna");
			return 0;
	}
	
	
	return 0;
}
