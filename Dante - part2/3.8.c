#include <stdio.h>
#include <ctype.h>

int main ()
{
    char tab[31]={0};
    printf("Podaj sciezke do pliku: \n");
    scanf("%30[^\n]s",tab);
    FILE *plik1;
    plik1=fopen(tab,"r");
    if(plik1==NULL)
    {
        return printf("Couldn't open file\n"),4;
    } 
    int a;
    int sum=0;
   	int result = 0;
	do {
    	result = fscanf(plik1, "%d", &a);
    	if(result != 1) {
        	printf("File corrupted\n");
        	fclose(plik1);
        	return 6;
    	}
    	else
		{
			sum+=a;
		} 
	} while(result != EOF);
    fclose(plik1);
    printf("Suma wynosi %d .\n",sum);
    return 0;
} 
