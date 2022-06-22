#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main ()
{
	double promien;
	printf("Podaj promien: ");
	while(scanf("%lf",&promien)!=1 || promien<=0)
	{
		printf("incorrect input\n");
		printf("Podaj promien: ");
		char c;
		while((c = getchar()) !='\n');
	}
	
	printf("Obwod kola: %lf\n",2*M_PI*promien);
	printf("Pole kola: %lf \n",M_PI*promien*promien);
	
	return 0;
}

