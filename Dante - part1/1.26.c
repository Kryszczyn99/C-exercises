#include <stdio.h>

int main (){
	int d1,d2,m1,m2,y1,y2,y3,y4;
	printf("Podajdate dd-mm-yyyy: ");
	scanf("%1d%1d-%1d%1d-%1d%1d%1d%1d",&d1,&d2,&m1,&m2,&y1,&y2,&y3,&y4);
	printf("Day:%*d%d\nMonth:%*d%d\nYear:%*d%d%d%d",7,d1,d2,5,m1,m2,4,y1,y2,y3,y4);
	return 0;
}
