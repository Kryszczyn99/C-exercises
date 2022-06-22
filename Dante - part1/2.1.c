#include <stdio.h>

int main (void){
	int a,b;
	printf("Podaj dwie liczby calkowite: ");
	int c=scanf("%i %i",&a,&b);
	
	if((c>>1 && a+b>=c) || (c>>1 && a+b<=c)){
		printf("suma: %d",a+b);
	}else{
		printf("Incorrect input");
		return 1;
	}
	return 0;
}

