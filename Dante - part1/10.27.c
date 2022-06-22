#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_destination_reachable(int sx, int sy, int dx, int dy);

int main()
{
	int a1,b1;
	int a2,b2;
	printf("Podaj wspolrzedne poczatkowe: ");
	if(scanf("%d %d",&a1,&b1)!=2)   return printf("Incorrect input"),1;
	printf("Podaj wspolrzedne poczatkowe : ");
	if(scanf("%d %d",&a2,&b2)!=2)	return printf("Incorrect input"), 1;
	int k=is_destination_reachable(a1,b1,a2,b2);
	if(k==0)	return printf("NO\n"),0;
	printf("YES");
	return 0;
}

int is_destination_reachable(int sx, int sy, int dx, int dy)
{
	if(dx==sx)
		{
			if(dy==sy) return 1;
		}  
	if(sx>dx ) return 0;
	if(sy>dy ) return 0;
	return  is_destination_reachable(sx,sx+sy,dx,dy) || is_destination_reachable(sx+sy,sy,dx,dy) ;
}
