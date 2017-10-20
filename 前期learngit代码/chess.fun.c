#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include"chessboard.h"
#include<stdlib.h>
#include<time.h>


#define ROWS 3
#define COLS 3


void menu()
{
    printf("---------------------\n");
    printf("---------------------\n");
    printf("-------1 play -------\n");
    printf("-------0 exit -------\n");
    printf("---------------------\n");
    printf("---------------------\n");
}


void init_board(char board[ROWS][COLS],int x,int y)
{
  
  memset(board,' ',ROWS*COLS*sizeof(char)); 

}

void game()
{
  /*int a,b;
  scanf("%d",&a,&b);*/
  
  char board[ROWS][COLS];
  init_board(board,ROWS,COLS);
  do
  {
  display_board(board,ROWS,COLS);
  player_play(board,ROWS,COLS); 
  check_win(board,ROWS,COLS);
  computer_play(board,ROWS,COLS);
  check_win(board,ROWS,COLS);
  }while(1);
}


void display_board(char board[ROWS][COLS],int x,int y)
{
   int i = 0;
   for(i=0;i<ROWS;i++)
   {
	   printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
	   if(2!=i)
	   printf("--------------\n");
   }
    
}

void player_play(char board[ROWS][COLS],int x,int y/*int* a,int* b*/)
{ 
	int a = 0,b = 0,flag = 1;
	do{
	printf("please enter :");
	scanf("%d %d",&a,&b);
    if((a<x+1 && b<x+1)&&(board[a-1][b-1] == ' '))
	{ board[a-1][b-1] = 'X';
	 flag = 0;}
	//printf("错误输入\n");
	}while(flag);
}

void  computer_play(char board[ROWS][COLS],int x,int y)
{ 
  int i = 0,j = 0;
  do{

   i = rand()%3;
   j = rand()%3;

  //i = rand()%3;
  //j = rand()%3;
  }while(board[i][j] != ' ');
  board[i][j] = '0';
  
}

void check_win(char board[ROWS][COLS],int x,int y)
{ 
  int i;
  if(((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))||\
  ((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])))
  {
     if(board[1][1] == 'X')
         printf("player win\n");
     if(board[1][1] == '0')
			printf("computer win\n");

  }
    
    for(i=0;i<3;i++)
  {
    if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[0][i] != ' '))
    //((board[0][i]==board[1][i])&&(board[1][i]==board[2][i]))
	{
        if(board[i][0] == 'X')//&&(board[0][i] == 'X'))
			printf("player win\n");
		if(board[i][0] == '0')//&&(board[i][0] == '0'))
			printf("computer win\n");

	}
  }
  for(i=0;i<3;i++)
  {
	  if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[0][i] != ' '))
	  {
		  if(board[0][i] == 'X');
	          printf("player win\n");
		  if(board[0][i] == '0');
		     printf("computer win\n");
	  }
  }
}