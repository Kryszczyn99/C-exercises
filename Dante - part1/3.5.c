#include <stdio.h>

int main (void){
	
	printf("Podaj literke: ");
	
	char q;
	
	scanf(" %c",&q);
	
	int bop= q=='a' || q=='e' || q=='i' || q=='o' || q=='u' || q=='y' || q=='A' || q=='E' || q=='I' || q=='O' || q=='U' || q=='Y';
	
	
	int bap= q>='a' && q<='z' || q>='A' && q<='Z';
	
	int beep=bap+bop;
	
	
	switch(beep)
	
	
	{
	    case 2:	
	   		printf("vowel\n");
	    	break;
		case 0:
			printf("Incorrect input\n");
			return 1;
		default:
	    	printf("consonant\n");
	}
	
	
	return 0;
}
