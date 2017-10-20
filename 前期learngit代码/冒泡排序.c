#include<stdio.h>
#include<windows.h>
#include<assert.h>
void PaiXu_print(int *arr,int le)
{
    int i = 0;
	int j = 0;
	assert(arr);
	for(;i<le-1;i++){
		int flag = 0;
		for(j=0;j<le-i-1;j++){
			if(arr[j]>arr[j+1]){
				 flag = 1;
                 arr[j]^=arr[j+1];
                 arr[j+1]^=arr[j];			
  				 arr[j]^=arr[j+1];			
   			}
		}
       if(flag==0)
	   break;
	}
	
}

int main()
{
	int arr[] = {2,8,5,9,4,7,1,6,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	//void PaiXu_print(int *arr,int len);
	PaiXu_print(arr,len);
	printf("small to big:");
	for(;i<len;i++)
	printf("%d",arr[i]);
	system("pause");
	return 0;
}
