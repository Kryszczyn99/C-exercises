#include <stdio.h>

int main (void){
	int e;
	printf("Podaj zuzyta energie: ");
	if(scanf("%d",&e)!=1){
		printf("Incorrect input");
		return 1;
	}else if(e<0){
		printf("Incorrect input");
		return 1;
	}else if(e>=0 && e<=50){
		printf("%f",0.5*e*1.22);
	}else if(e>50 && e<=150){
		printf("%f",(0.5*50+(e-50)*0.75)*1.22);
	}else if(e>150 && e<=250){
		printf("%f",(0.5*50+100*0.75+(e-150)*1.2)*1.22);
	}else{
		printf("%f",(0.5*50+100*0.75+100*1.2+(e-250)*1.5)*1.22);
	}
	
	return 0;
}
