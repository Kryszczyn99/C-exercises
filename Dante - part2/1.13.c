#include <stdio.h>

int swap(int*number_1, int*number_2)
{
	if(number_1==NULL || number_2==NULL) return 1;
	int wynik;
	wynik=*number_1;
	*number_1=*number_2;
	*number_2=wynik;
	return 0;
}

int main ()
{
	printf("Podaj dwie liczby: ");
	int number_1,number_2;
	int y=scanf("%d",&number_1);
	if(y!=1) return printf("Incorrect input\n"),1;
	y=scanf("%d",&number_2);
	if(y!=1) return printf("Incorrect input\n"),1;
	swap(&number_1,&number_2);
	printf("%d  %d",number_1,number_2);
	return 0;
}
