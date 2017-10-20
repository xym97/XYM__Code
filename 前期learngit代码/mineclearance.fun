#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include"mineclearance.h"
#include<stdlib.h>
#include<time.h>


#define ROWS 10
#define COLS 10


void menu()
{
    printf("---------------------\n");
    printf("---------------------\n");
    printf("-------1 play -------\n");
    printf("-------0 exit -------\n");
    printf("---------------------\n");
    printf("---------------------\n");
}

void game()
{
    char show[ROWS+2][COLS+2];
	char mine[ROWS+2][COLS+2];
    int count = 0;
	init_show(show,ROWS+2,COLS+2);
    init_mine(mine,ROWS+2,COLS+2);
	set_mines(mine,ROWS+2,COLS+2);
	while(1){
	display_board(show,mine,ROWS+2,COLS+2);
	if (count == 0)
    first_move_mine(mine,ROWS+2,COLS+2); 
	display_board(show,mine,ROWS+2,COLS+2);
	detect_mines(mine,show,ROWS+2,COLS+2);
	display_board(show,mine,ROWS+2,COLS+2);
    count++;
	//detect_mines(mine,show,ROWS+2,COLS+2);
	}
}

void init_show(char show[ROWS+2][COLS+2],int x,int y)
{
  
  memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char)); 
}

void init_mine(char mine[ROWS+2][COLS+2],int x,int y)
{
 memset(mine,'@',(ROWS+2)*(COLS+2)*sizeof(char));

}

void set_mines(char mine[ROWS+2][COLS+2],int x,int y)
{    
	 int i = 0;
	 int j = 0;
	 int a = 0;
	 int minecount = 0;
	 printf("Please Enter minecount :");
	 scanf("%d",&a);
	 
	 do{
	 i = rand()%10+1;
	 j = rand()%10+1;
	 
	 if(mine[i][j] == '@')
	 mine[i][j] = '!';
     minecount++;
	 }while(minecount<a);
     
}

void display_board(char show[ROWS+2][COLS+2],char mine[ROWS+2][COLS+2],int x,int y)
{  
   int i = 0;
   int j = 0;
   for(i=1;i<11;i++)
     printf("%4d",i);
     printf("\n");
   for(i=1;i<=ROWS;i++)
    { 
	  printf("%d",i);
      for(j=1;j<=COLS;j++)
	  {   
		 
		  printf("%4c",show[i][j]);
          
	  }
         printf("\n");
   }
   for(i=1;i<11;i++)
     printf("%4d",i);
     printf("\n");
      for(i=1;i<=ROWS;i++)
     {
	  printf("%d",i);
      for(j=1;j<=COLS;j++)
	   {  
	     
		  printf("%4c",mine[i][j]);
         
       }
          printf("\n");
	  }
}

void detect_mines(char mine[ROWS+2][COLS+2],char show[ROWS+2][COLS+2],int x,int y)
{
    int b = 0;
	int a = 0;
	int i = 0;
	int j = 0;
	int q = 0;
	int count = 0;
	printf("Plesae Enter coordinate:");
    scanf("%d %d",&a,&b);
	if(mine[a][b] == '!')
	   
	{
	printf("Game over.\n");
	   for(i=1;i<11;i++)
     printf("%4d",i);
     printf("\n");
      for(i=1;i<=ROWS;i++)
     {
	  printf("%d",i);
      for(j=1;j<=COLS;j++)
	   {  
	     
		  printf("%4c",mine[i][j]);
         
       }
          printf("\n");
	  }
	  system("pause");}
	if(mine[a][b] != '!');
	{
       if(mine[a-1][b-1] == '!')
		   count++;
       if(mine[a-1][b] == '!')
		   count++;
       if(mine[a-1][b+1] == '!')
		   count++;
       if(mine[a][b-1] == '!')
		   count++;
       if(mine[a][b+1] == '!')
  	       count++;
	   if(mine[a+1][b-1] == '!')
		   count++;
       if(mine[a+1][b] == '!')
		   count++;
	   if(mine[a+1][b+1] == '!')
		   count++;
	}  
	show[a][b] = '0'+count;     

}


int first_move_mine(char mine[ROWS+2][COLS+2]/*,char show[ROWS+2][COLS+2]*/,int x,int y)
{
 
    int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	printf("Please Enter the first coordiate:");
	scanf("%d %d",&a,&b);
	if(mine[a][b] == '@')
		return 0;
	if(mine[a][b] == '!')
	   mine[a][b] = '@';
	do{
		i = rand()%10+1;
		j = rand()%10+1;
		if(mine[i][j] == '!')
		flag = 1;
		else
		mine[i][j] = '!';
	}while(flag);


}