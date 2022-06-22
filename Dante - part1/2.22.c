#include <stdio.h>

int main ()
{
	int wiek;
	char kobieta, mezczyzna,a;
	printf("Podaj swoj wiek: ");
	scanf("%d",&wiek);
	printf("kobieta czy mezczyzna: ");
	scanf("%s",&a);
if((a==kobieta || a==mezczyzna)&& wiek>=0 ){
	printf("123");
	}
 			else{
 				printf("Incorrect input");
				return 1;
					}
	return 0;
}
