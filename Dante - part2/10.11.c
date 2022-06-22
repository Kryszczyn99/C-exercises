#include <stdio.h>
#include <stdlib.h>


int main (int argc, char** argv)
{
	if(argc<=2)	return printf("Not enough arguments"),9;
	FILE *z;
	z=fopen(*(argv+1),"r");
	if(z==NULL) return printf("Couldn't open file"),4;
	FILE *c;
	c=fopen(*(argv+2),"w");
	if(c==NULL)
	{
		fclose(z);
		return printf("Couldn't create file"),5;
	}
	while(1)
	{
		char znak;
		int y=fscanf(z,"%c",&znak);
		if(y!=1) break;
		fprintf(c,"%c",znak);
	}
	printf("File copied");
	fclose(c);
	fclose(z);
	return 0;
}




