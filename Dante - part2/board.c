#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#define SUCCESS 0
#define MEMORY 2
#define INPUT 1
int create_board(struct board_t **board, int width, int height)
{
	if(board==NULL) return INPUT;
	if(width<=0) return INPUT;
	if(height<=0) return INPUT;
	int size=sizeof(struct board_t);
	struct board_t* wsk=(struct board_t*)malloc(size);
	if(wsk==NULL) return MEMORY;
	*board=wsk;
	int dlugosc=height;
	int szerokosc=width;
	int size_2=sizeof(char*)*dlugosc;
	char **ptr1=(char**)malloc(size_2);
	if(ptr1==NULL)
	{
		free(wsk);
		*board=NULL;
		return MEMORY;
	}
	(*board)->board=ptr1;
	int i=0;
	while(1)
	{
		if(i==dlugosc) break;
		int new_size=szerokosc+1;
		char *helper=(char*)malloc(new_size);
		if(helper==NULL)
		{
			i-=1;
			while(1)
			{
				if(i<0) break;
				char *last=*((*board)->board+i);
				free(last);
				i--;
			}
			free((*board)->board);
			free(wsk);
			*board=NULL;
			return MEMORY;
		}
		*((*board)->board+i)=helper;
		int p=0;
		while(1)
		{
			if(p==szerokosc)
			{
				*(*((*board)->board+i)+p) = '\0';
				break;
			}
			else *(*((*board)->board+i)+p) = '.';
			p++;
		}
		i++;
	}
	(*board)->width=szerokosc;
	(*board)->height=dlugosc;
	(*board)->move_player_up=move_player_up;
	(*board)->move_player_down=move_player_down;
	(*board)->move_player_left=move_player_left;
	(*board)->move_player_right=move_player_right;
	(*board)->is_init=0;
	return SUCCESS;
}

void display_board(const struct board_t *board)
{
	if(board==NULL) return;
	int szerokosc=board->width,dlugosc=board->height;
	if(szerokosc<=0) return;
	if(dlugosc<=0) return;
	int i=0,j=0;
	while(1)
	{
		if(i==dlugosc) break;
		j=0;
		while(1)
		{
			if(j==szerokosc)
			{
				printf("\n");
				break;
			} 
			char znak=*(*(board->board+i)+j);
			if(znak=='@') printf("@");
			else printf(".");
			j++;
		}
		i++;
	}
	return;
}
void free_board(struct board_t *board)
{
	if(board==NULL) return;
	int szerokosc=board->width,dlugosc=board->height;
	if(szerokosc<=0) return;
	if(dlugosc<=0) return;
	if(board->board==NULL) return;
	int i=0;
	while(1)
	{
		if(i==dlugosc)
		{
			free(board->board);
			free(board);
			break;
		}
		char *tab=*(board->board+i);
		free(tab);
		i++;
	}
	return;	
}

int set_player(struct board_t *board, int x, int y)
{
	if(board==NULL) return INPUT;
	int szerokosc=board->width,dlugosc=board->height;
	if(szerokosc<=0) return INPUT;
	if(dlugosc<=0) return INPUT;
	if(x<=-1 || szerokosc<=x) return INPUT;
	if(y<=-1 || dlugosc<=y) return INPUT;
	if(board->is_init==1) return INPUT;
	if(board->board==NULL) return INPUT;
	board->is_init=1;
	board->player.x=x;
	board->player.y=y;
	char znak='@';
	*(*(board->board+y)+x)=znak;
	return SUCCESS;
}

int warunki(struct board_t* board)
{
	if(board==NULL) return INPUT;
	int szerokosc=board->width,dlugosc=board->height;
	if(szerokosc<=0) return INPUT;
	if(dlugosc<=0) return INPUT;
	if(board->is_init==0) return INPUT;
	if(board->board==NULL) return INPUT;
	int x=board->player.x;
	if(x<=-1 || szerokosc<=x) return INPUT;
	int y=board->player.y;
	if(y<=-1 || dlugosc<=y) return INPUT;
	return SUCCESS;
}
int job(struct board_t* board)
{
	int x=board->player.x,y=board->player.y,szerokosc=board->width,dlugosc=board->height,i=0,j=0;
	while(1)
	{
		if(i==dlugosc) break;
		j=0;
		while(1)
		{
			char znak1='.';
			char znak2='@';
			if(j==szerokosc) break;
			if(i!=y) *(*(board->board+i)+j)=znak1;
			else if(j!=x) *(*(board->board+i)+j)=znak1;
			else *(*(board->board+i)+j)=znak2;
			j++;
		}
		i++;
	}
	return SUCCESS;
}
struct board_t* move_player_up(struct board_t* board)
{
	int z=warunki(board);
	if(z==1) return NULL;
	int y=board->player.y,dlugosc=board->height;
	if(y-1<0) y = dlugosc-1;
  	else y=y-1;
  	board->player.y=y;
	job(board);
	return board;
}
struct board_t* move_player_down(struct board_t* board)
{
	int z=warunki(board);
	if(z==1) return NULL;
	int y=board->player.y,dlugosc=board->height;
	if(dlugosc>y+1) y=y+1;
	else y=0;
	board->player.y=y;
	job(board);
	return board;	
}
struct board_t* move_player_left(struct board_t* board)
{
	int z=warunki(board);
	if(z==1) return NULL;
	int x=board->player.x,szerokosc=board->width;
  	if(x-1<0) x=szerokosc-1;
  	else x=x-1;
  	board->player.x=x;
	job(board);
	return board;		
}
struct board_t* move_player_right(struct board_t* board)
{
	int z=warunki(board);
	if(z==1) return NULL;
	int x=board->player.x,szerokosc=board->width;
  	if(x+1>=szerokosc) x=0;
  	else x=x+1;
	board->player.x=x;
	job(board);
	return board;	
}

