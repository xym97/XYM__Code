#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

void FoddBeven(int *arr,int len)
{
	int i = 0;
	int j = 0;
	for(i=0,j=len-1;i<j;){
		if(((arr[i]&1)==0)&&((arr[j]&1)==1)){
             arr[i]^=arr[j];
             arr[j]^=arr[i];
             arr[i]^=arr[j];
		}
	    if((arr[i]&1)==1)
			i++;
		if((arr[j]&1)==0)
			j--;
	}
}
int main()
{
	int arr[9] = {2,7,5,6,4,9,8,3,1};
	int i = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
	printf("Please Enter arr\n");
	/*for(;i<10;i++)
		scanf("%d",&arr[i]);*/
	//void FoddBeven(int *arr,int len);
	printf("FoddBeven:");
	FoddBeven(arr,len);
   	for(i=0;i<len;i++)
	printf("%d",arr[i]);
    system("pause");
	return 0;
}
//#include<stdio.h>  
//#include<stdlib.h>  
//void adjust_arr(int arr[], int size)  
//{  
//    int temp; int i, j;  
//  
//    for (i = 0,j = size-1; i <j; )  
//    {  
//        if ((arr[i] % 2 == 0) && (arr[j] % 2 == 1))     //如果奇数在后，偶数在前，则进行调换  
//        {  
//            temp = arr[i];  
//            arr[i] = arr[j];  
//            arr[j] = temp;  
//        }  
//        if (arr[i] % 2 == 1)   //如果arr[i]为奇数，i++  
//            i++;  
//        if (arr[j] % 2 == 0)   //如果arr[j]为偶数，j--  
//            j--;  
//    }  
//}  
//  
//int main()  
//{  
//    int arr[] = {  2, 3, 4, 5, 6, 7, 10,11,12,13,14,15,16,8, 9 ,17,18,19,20};  
//    int i;  
//    int size = sizeof(arr) / sizeof(arr[0]);  
//    adjust_arr(arr, size);    //函数调用，队数组进行排序，  
//    for (i = 0; i < size; i++)  
//        printf("%d ",arr[i]);  
//    printf("\n");  
//    system("pause");  
//    return 0;  
//} 
//		