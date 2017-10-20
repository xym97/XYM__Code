#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int arr[] = {1,8,6,4,7,2,5,9,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	void BigSmall(int* arr,int len);
	BigSmall(arr,len);
	for(;i<len;i++)
		printf("%d",arr[i]);
	printf("\n");
	system("pause");
	return 0;
}
void BigSmall(int* arr,int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(arr[j]>arr[i]){
			   arr[i]^=arr[j];
			   arr[j]^=arr[i];
			   arr[i]^=arr[j];
			}
		}
	}
}



