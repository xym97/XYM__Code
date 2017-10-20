#include<iostream>
#include<stdlib.h>

using namespace std;

int Binaryreserch(int* arr, int left, int right, int data)
{
	if (left < right){
		int mid = left +( (right - left) >> 1);
		if (arr[mid] == data)
			return arr[mid];
		else if (data > arr[mid])
			return Binaryreserch(arr,mid+1 , right, data);
		else if (data < arr[mid])
			return Binaryreserch(arr, left, mid, data);
	}
	return -1;
}

void FunTest()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << Binaryreserch(arr, 0, 9, 3) << endl;
}

long long Fib(int f, int s, int N)
{
	if (N < 3)
	{
		return 1;
	}
	if (N == 3)
	{
		return f + s;
	}
	return Fib(s, f + s, N - 1);
}

int Fac(int N)
{
	if (0 == N)
		return 1;
	return Fac(N - 1)*N;
}

int main()
{
	FunTest();
	cout << Fib(1, 1, 9) << endl;
	cout << Fac(3) << endl;
	system("pause");
	return 0;
}