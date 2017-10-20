#include<iostream>
#include<windows.h>

using namespace std;
 
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Prem(int* arr,int size,int N)
{
	if (size == N){
		for (int idx = 0; idx < N; idx++)
		{
			cout << arr[idx];
		}
		cout << endl;
	}
	else{
		for (int jdx = N; jdx <= size; jdx++){
			swap(&arr[jdx],&arr[N]);
			Prem(arr, size, N + 1);
			swap(&arr[jdx], &arr[N]);

		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5};
	Prem(arr,sizeof(arr)/sizeof(arr[0]),2);
	system("pause");
	return 0;
}