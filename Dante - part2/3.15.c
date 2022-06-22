#include <stdio.h>

int main()
{
	char tab[31] = { 0 };
	printf("Podaj sciezke do pliku: \n");
	scanf("%30[^\n]s", tab);
	FILE *plik1;
	plik1 = fopen(tab, "r");
	if (plik1 == NULL)		return printf("Couldn't open file"), 4;
	int k = 1;
	char znak=0;
	fseek(plik1, 0, SEEK_END);
	int len = ftell(plik1);
	int i;
	int p = 0;
	for (i = 0; i < len; i++)
	{
		if (p == 0)
		{
			printf("%d. ", k);
			p = 1;
		}
		fseek(plik1, i, SEEK_SET);
		fscanf(plik1, "%c", &znak);
		if (znak == '\n')
		{
			printf("\n");
			p = 0;
			k += 1;
		}
		else printf("%c", znak);
	}
	
	fclose(plik1);
	
	if(len==0 && k==1)
	{
		k=0;
		printf("%d",k);
	}
	else printf("\n%d", k);
	
	return 0;
}
