#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	
	
	float r1,r2,u1,u2;

	
	printf("Podaj czesc rzeczywista pierwszej liczby zespolonej:");
	scanf("%f",&r1);
	
	printf("Podaj czesc urojona pierwszej liczby zespolonej:");
	scanf("%f",&u1);
	
	printf("Podaj czesc rzeczywista drugiej liczby zespolonej:");
	scanf("%f",&r2);
	
	printf("Podaj czesc urojona drugiej liczby zespolonej:");
	scanf("%f",&u2);
	
	printf("x=%.3f+i%.3f  y=%.3f+i%.3f\n",r1,u1,r2,u2);
	printf("suma=%.3f+i%.3f\n",r1+r2,u1+u2);
	printf("roznica=%.3f+i%.3f\n",r1-r2,u1-u2);
	printf("iloczyn=%.3f+i%.3f\n",r1*r2-u1*u2,r1*u2+u1*r2);
	printf("iloraz=%.3f+i%.3f",r1*r2+u1*u2/(pow(r2,2)+pow(u2,2)), u1*r2-r1*u2/(pow(r2,2)+pow(u2,2)));
	return 0;
}
