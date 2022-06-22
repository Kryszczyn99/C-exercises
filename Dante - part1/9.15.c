#include <stdio.h>
#include <string.h>

int horner(const char binary[]);

int main ()
{
	
	printf("Podaj kod binarny: ");
	char binar[17];
	int a=0;
	while(a<16)
	{
		scanf("%c",&binar[a]);
		if(binar[a]=='\n')
		{
			binar[a]='\0';
			break;
		}
		a=a+1;
	}
	int b=horner(binar);
	if(b==-1)
  	{
		printf("\nIncorrect input\n");
    	return 1;
  	}
	printf("\nWynik: %d\n",horner(binar));
	return 0;
}


int horner(const char binary[]){
	int dlugosc=strlen(binary);
	int z=0;
	while(z<dlugosc)
	{
	if(binary[z]=='1' || binary[z]=='0') z=z+1;
	else return -1;
	}
	
	int Sum=binary[0]-48;
	z=1;
	while(z<dlugosc)
	{
		Sum=Sum*2+binary[z]-48;
		z=z+1;
	}
  	return Sum;
}

