#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//int Seek(int arr[3][3],int a)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while(i<3){
//	if(a<arr[i][j]){
//         return 0;	
//	}
//	else if(a>arr[i][j]){
//		for(k=0;k<3;k++){
//			if(arr[i][k]==a){
//               return arr[i][k];		
//			}
//		}
//	}
//	else 
//		return arr[i][j];
//	i++;
//	}
//	return 0;
//}
int Seek(int(*arr)[3],int data)
{
    int row = 0;
    int col = 2;
	assert(arr);
   while(row<3 && col>=0){
	   if(data>arr[row][col]){
		   
            row++;	   
	   }
	   else if(data<arr[row][col]){
	        col--;
	   }
	   else
		   return arr[row][col];
   }
   return 0;
}
int main()
{
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int row = 0;
	int col = 0;
	int ret = 0;
	int data = 0;
	printf("Please Enter Your Seek:");
	scanf("%d",&data);

	//int Seek(int arr[3][3],int a);
	ret = Seek(arr,data);
	if(ret!=0)
	printf("There are a number is :%d",ret);
	else
		printf("No number");
	system("pause");
	return 0;
}

