#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
//#define SWAP_ODDEVEN(x) 
// void swap_oddeven(int x)
// {                
//	  int arr[32] = {0};
//	  int i = 0;
//	  scanf("%d",&x);
//      while(x!=0)
//	  {   
//		  printf("before swap bit:");
//         for(i=0;i<32;i++)
//		 {                
//			 arr[i] = x&1;
//			 x>>=1;
//		   
//		 } 
//		 for(i=31;i>=0;i--)
//		 {
//			 printf("%d",arr[i]);
//		 }
//		 printf("\n");
//	  }   
//        for(i=0;i<32;i+=2)
//		 {  
//			 if(arr[i]!=arr[i+1]){
//			arr[i]^=arr[i+1];
//			arr[i+1]^=arr[i];
//			arr[i]^=arr[i+1];}
//   		 }
//		printf("after:");
//          for(i=31;i>=0;i--)
//		 {
//			 printf("%d",arr[i]);
//		 }
//		 printf("\n");
// }
//int main()
//{  
//   //SWAP_ODDEVEN(x)
//   int x = 0;
//   swap_oddeven(x);
//   return 0;
//}

//#define SWAP_ODDEVEN(x)
//int swap_oddeven(int* value)
//{
//	int i = 0;
//    *value&1^*value&2;
//	*value&2^*value&1;
//	*value&1^*value&2;
// 
//
//}
//
//int main()
//{  
//	int a = 0;
//	int ret = 0;
//	printf("Please Enter :");
//	scanf("%d",&a);
//	printf("Before Swap:%d",a);
//    int *value = a;
//    ret = swap_oddeven(&value);   	
//	printf("After Swap:%d",ret);
//	return 0;
//}

#define  SWAP_ODDEVEN(x)  ((n&0xaaaaaaaa))>>1 | ((n&0x55555555)<<1)
#include<stdio.h>
int main()
{
	int n = 0;
	int a = 0;
	scanf("%d",&n);
    a = SWAP_ODDEVEN(x);
	printf("After:%d",a);
	return 0;
}