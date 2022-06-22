#include <stdio.h>

int main ()
{
	printf("Podaj glebokosc: ");
	int deep;
	int y=scanf("%d",&deep);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(deep>6 || deep<1)
	{
		printf("Incorrect input data\n");
		return 2;
	}
	if(deep==1) printf("___");
	if(deep==2) printf("___\n_ _\n");
	if(deep==3) printf("_________\n___   ___\n_ _   _ _\n");
	if(deep==4) printf("___________________________\n_________         _________\n___   ___         ___   ___\n_ _   _ _         _ _   _ _\n");
	if(deep==5) printf("_________________________________________________________________________________\n___________________________                           ___________________________\n_________         _________                           _________         _________\n___   ___         ___   ___                           ___   ___         ___   ___\n_ _   _ _         _ _   _ _                           _ _   _ _         _ _   _ _");
	int i;
	if(deep==6)
	{
		for(i=0;i<243;i++) printf("_");
		printf("\n");
		for(i=0;i<81;i++) printf("_");
		for(i=0;i<81;i++) printf(" ");
		for(i=0;i<81;i++) printf("_");
		printf("\n");
		for(i=0;i<27;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<27;i++) printf("_");
		for(i=0;i<81;i++) printf(" ");
		for(i=0;i<27;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<27;i++) printf("_");
		printf("\n");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<81;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<9;i++) printf("_");
		printf("\n");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<81;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<27;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<9;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		for(i=0;i<3;i++) printf(" ");
		for(i=0;i<3;i++) printf("_");
		printf("\n");
		printf("_ _   _ _         _ _   _ _");
		for(i=0;i<27;i++) printf(" ");
		printf("_ _   _ _         _ _   _ _");
		for(i=0;i<81;i++) printf(" ");
		printf("_ _   _ _         _ _   _ _");
		for(i=0;i<27;i++) printf(" ");
		printf("_ _   _ _         _ _   _ _");
	}
	return 0;
}
