#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
      int a;
      int b;
      int i;
      int arr[32] = {0};
      int brr[32] = {0};
      int count = 0;
      printf("Please Enter a compared figure :");
      scanf("%d %d",&a,&b);
      for(i=0;i<32;i++)
	   {
           if(a!=0)
		   {
			 arr[i] = (a&1);
			 printf("%d",arr[i]);
		     a>>=1;
		   }
	     }
	     printf("\n");   
	   for(i=0;i<32;i++)
	   {
           if(b!=0)
		   {
			   brr[i] = (b&1);
			   printf("%d",brr[i]);
			   b>>=1;
		   }
	   }
		   printf("\n");
       for(i=0;i<32;i++)
	   {   
		   
           if(arr[i] != brr[i])
           count++;
	   }
   
   printf("%d",count);


   return 0;
}