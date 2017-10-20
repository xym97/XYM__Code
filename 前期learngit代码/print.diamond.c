#define N 8
#include<stdio.h>
int main()
{
  int i,j,k;
  for(i=0;i<=N;i++)
  {
     for(j=0;j<=((N-1)-i);j++)//
		 printf(" ");
	 for(k=0;k<=i*2;k++)
		 printf("*");
	 printf("\n");
  }
  for(i=0;i<=(N-1);i++)
  {
     for(j=0;j<=i;j++)
		 printf(" ");
	 for(k=0;k<=((2*N+1-2-1)-i*2);k++)
		 printf("*");
	 printf("\n");
  }
  return 0;
}