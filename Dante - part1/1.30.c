#include <stdio.h>

int main (void){
	int x,godzina,minuta,sekunda;
	printf("Podaj czas w sekundach: ");
	scanf("%d",&x);
	godzina=x/3600;
	minuta=(x-godzina*3600)/60;
	sekunda=x-((3600*godzina)+(60*minuta));
	printf("%02d:%02d:%02d",godzina,minuta,sekunda);
	
	return 0;
}
