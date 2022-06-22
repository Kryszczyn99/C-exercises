#include <stdio.h>

int main (void){
	int a1,a2,a3,a4,a5,a6,a7,a8,a9;
	printf("Podaj numer telefonu w formacie (dd) ddd-dd-dd: ");
if(scanf("(%1d%1d) %1d%1d%1d-%1d%1d-%1d%1d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9)!=9){
	printf("Incorrect input");
	return 1;
}
	printf("Numer kierunkowy: %1d%1d\nNumer telefonu: %1d%1d%1d-%1d%1d-%1d%1d",a1,a2,a3,a4,a5,a6,a7,a8,a9);
	return 0;

	
	
}
