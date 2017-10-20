//每瓶汽水1元，两个空瓶可以置换一瓶汽水；现有20元，最多能喝对少瓶汽水
//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//    int a;
//	int b;
//	//int c;
//	printf("How much money do you have?");
//	scanf("%d",&a);
//	b = (a/2)*3+a%2;
//	printf("you can drink %d 瓶汽水");
//
//	return 0;
//}
#include <stdio.h>  
#define MAX  15
  
int main()  
{  
     int money=MAX;  
     int count=MAX;  
     while(1)  
     {  
          
               count=count+money-1;  
               break;   
		  
     }   
     printf("%d\n",count);  
     return 0;  
} 
