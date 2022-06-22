#include <stdio.h>
#include "board.h"

int main()
{
	printf("Podaj kordy: ");
	int szerokosc,z;
	z=scanf("%d",&szerokosc);
	if(z!=1) return printf("Incorrect input"),1;
	int dlugosc;
	z=scanf("%d",&dlugosc);
	if(z!=1) return printf("Incorrect input"),1;
	if(szerokosc<=0) return printf("Incorrect input data"),2;
	if(dlugosc<=0) return printf("Incorrect input data"),2;
	struct board_t *plansza;
	if(create_board(&plansza,szerokosc,dlugosc)==2) return printf("Failed to allocate memory"),8;
	printf("Podaj kordy: ");
	int x;
	z=scanf("%d",&x);
	if(z!=1)
	{
		free_board(plansza);
		return printf("Incorrect input"),1;
	} 
	int y;
	z=scanf("%d",&y);
	if(z!=1)
	{
		free_board(plansza);
		return printf("Incorrect input"),1;		
	} 
	if(x<0 || szerokosc<=x) free_board(plansza);
	if(y<0 || dlugosc<=y) free_board(plansza);
	if(x<0 || szerokosc<=x) return printf("Incorrect input data"),2;
	if(y<0 || dlugosc<=y) return printf("Incorrect input data"),2;
	char znak;
	scanf("%c",&znak);
	set_player(plansza,x,y);
	display_board(plansza);
	int flaga=1;
	while(flaga)
	{
		printf("Podaj op: ");
		scanf("%c",&znak);
		char nowa_linia;
		scanf("%c",&nowa_linia);
		if(znak=='w') plansza=plansza->move_player_up(plansza);
		else if(znak=='s') plansza=plansza->move_player_down(plansza);
		else if(znak=='a') plansza=plansza->move_player_left(plansza);
		else if(znak=='d') plansza=plansza->move_player_right(plansza);
		else if(znak=='q')
		{
			flaga=0;
			continue;
		}
		else
		{
			printf("Incorrect choice\n");
			continue;
		}
		display_board(plansza);
	}
	return free_board(plansza),0;
}

