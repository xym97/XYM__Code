#include<iostream>
#include<windows.h>
#include<assert.h>
//void bubblesort(int *arr,int le)
//{
//    int i = 0;
//	int j = 0;
//	assert(arr);
//	for(;i<le-1;i++){
//		int flag = 0;
//		for(j=0;j<le-i-1;j++){
//			if(arr[j]>arr[j+1]){
//				 flag = 1;
//                 arr[j]^=arr[j+1];
//                 arr[j+1]^=arr[j];			
//  				 arr[j]^=arr[j+1];			
//   			}
//		}
//       if(flag==0)
//	   break;
//	}
//	
//}

template<class T>
class Less
{
public: 
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<class T>
class Greate
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<class T ,class Compare>
void bubblesort(T* arr, int le)
{
	assert(arr);
	for (T i = 0; i < le - 1; i++)
	{
		bool flag = false;
		for (T j = 0; j < le - i - 1; j++)
		{
			if (Compare()(arr[j], arr[j + 1])){
			    flag = true;
				arr[j] ^= arr[j + 1];
			    arr[j+1]^=arr[j];			
				arr[j]^=arr[j+1];
			}
			
		}
		if (!flag)
			return;
	}
}
 
int main()
{
	int arr[] = {2,8,5,9,4,7,1,6,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	/*less<int> L;
	Greate<int> G;*/
	bubblesort<int,Greate<int> >(arr, len);
	//bubblesort(arr, len);
	printf("small to big:");
	for(;i<len;i++)
	printf("%d",arr[i]);
	system("pause");
	return 0;
}
