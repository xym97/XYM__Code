//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//void showarr(int* arr,int len)
//{
//	int i = 0;
//	assert(arr);
//	for(;i<len;i++)
//	{
//        printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//int intcmp(void* x,void* y)
//{
//	int* _x = (int*)x;
//	int* _y = (int*)y;
//	return *_x - *_y;
//}
///* 这部分错误 可忽略
////void maopao(void* data,int num,int width,int(*cmp)(void*,void*)/*void* dataend*/)
////{
////	int i = 0;
////	assert(data);
////	for(;i<num-1;i++){
////        int flag = 0;
////		int j = 0;
////	    char* start = (char*)data;
////   		for(;j<num-1-i;j++){
////			if( (cmp(start,start+width))>0 ){
////				int k = 0;
////				flag = 1;
////   				for(;k<width;k++){
////				   start[k]^=start[k+width];
////				   start[k+width]^=start[k];
////				   start[k]^=start[k+width];
////				}
////				//flag = 1;
////   			}
////			start+=width;
////		}
////		if(!flag){break;}
////	}
////}
////                 */
//
//int maopao(void* data,int num,int width,int(*cmp)(void*,void*)/*void* dataend*/)
//{
//	int pivotkey = 0;
//	int* start = (int*)data;
//	//int* end = (int*)dataend;
//	int i = 0;
//    int j = num - 1;
//    //int* end = (int*)(dataend);
//	assert(data);
//	//start[0] = *start;
//	pivotkey = *start;
//	while(i<j){
//	     while(i<j && start[j]>=pivotkey)
//			 --j;
//		 start[i] = start[j];
//		 //start[j] ^= start[i];
//		 //start[i] ^= start[j];
//	     while(i<j && start[i]<=pivotkey)
//			 ++i;
//		 start[j] = start[i];
//		//start[j] ^= start[i];
//		// start[i] ^= start[j];
//	}
//    start[0] = pivotkey;
//	//*start = start[0];
//    //*start = *((int*)data);
//	//return strat
//}
//int main()
//{
//	//int arr[] = {15,8,6,56,7,9,12,4,2,};
//	int arr[] = {8,7,5,2,9,6,3,1,4}; 
//	int len = sizeof(arr)/sizeof(arr[0]);
//	showarr(arr,len);
//    maopao(arr,len,sizeof(arr[0]),intcmp/*arr+len-1*/);
//	showarr(arr,len);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void floatshow(float *arr,int len)
{
	int i = 0;
	for(;i<len;i++){
	   printf("%f",arr[i]);
	   printf("\n");
	}
	printf("\n");
}
static int floatcmp(const void* x,const void* y)
{
	assert(x);assert(y);
	return (*(float*)x < *(float*)y)? -1:1;
}
void floatqsort(float* arr,int len)
{
	assert(arr);
	qsort(arr,len,sizeof(float),floatcmp);
}
void stringshow(char* arr[],int len)
{
	int i = 0;
	for(;i<len;i++){
        printf("%s",arr[i]);
		printf("\n");
	}
	printf("\n");
}
static int stringcmp(const void* x,const void* y)
{
	assert(x);assert(y);
	return strcmp(*((char **)x),*((char **)y));
}
stringqsort(char *arr[],int len)
{
	assert(arr);
	qsort(arr,len,sizeof(char*),stringcmp);
}
int main()
{
	char* carr[] = {"dad","afa","xxx","ggg","ppp"};
	float farr[] = {1.1,2.4,3.5,7.6,3.1,4.4};
	int lenf = sizeof(farr)/sizeof(farr[0]);
	int lenc = sizeof(carr)/sizeof(carr[0]);
	floatshow(farr,lenf);
	floatqsort(farr,lenf);
	floatshow(farr,lenf);
 	stringshow(carr,lenc);
	stringqsort(carr,lenc);
	stringshow(carr,lenc);
	system("pause");
	return 0;
}