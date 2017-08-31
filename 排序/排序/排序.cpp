#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<algorithm>

using namespace std;

template<class T>
void Print(T* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
		cout << arr[i] << "  ";
	cout << endl;
}

//直接插入排序   写代码关键在于理解end的位置
template<class T>
void InsertSort(T* arr, size_t n)
{
	assert(arr && n > 0);
	size_t front = 0;

	for (; front < n - 1; ++front){
		int end = front;            //有序数列的最后一个是end
		T tmp = arr[end + 1];
		while (end >= 0){
			if (arr[end] > tmp){//比要插入的数字大就向后移
				arr[end + 1] = arr[end];
				--end;
			}
			else
				break;
		}    //必要插入的数字小就让它插在后面
		arr[end + 1] = tmp;
	}
	Print(arr, n);
}

//希尔排序 
template<class T>
void ShellSort(T* arr, size_t n)
{
	assert(arr && n>0);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t front = 0; front < n - gap; ++front){
			int end = front;
			T tmp = arr[end + gap];
			while (end >= 0){
				if (arr[end] > tmp){
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}

			arr[end + gap] = tmp;
		}
	}
	Print(arr, n);
}

//快速排序之 左右指针法(递归实现)
template<class T>
T SortPart1(T* arr, size_t begin, size_t end)
{
	assert(arr);
	int left = begin;
	int right = end;
	int key = arr[end];
	while (left < right)
	{
		while (arr[left] <= key && left < right){
			++left;
		}
		while (arr[right] >= key && left < right){
			--right;
		}
		if (left != right)
			swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[end]);
	return left;
}

template<class T>
void _FastSort1(T* arr, size_t begin, size_t end)
{
	assert(arr);
	if (begin >= end)
		return;
	T div = SortPart1(arr, begin, end);
	_FastSort1(arr, div + 1, end);
	_FastSort1(arr, begin,div - 1);
}

template<class T>
void FastSort1(T* arr, size_t begin, size_t end)
{
	_FastSort1(arr, begin, end);
	Print(arr, end+1);
}

//快速排序之挖坑法 （递归实现）
template<typename T>
T SortPart2(T* arr, size_t begin, size_t end)
{
	assert(arr);
	T key = arr[end];
	while (begin != end){
		while (arr[begin] <= key && begin < end)
			++begin;
		if (begin != end)
			arr[end] = arr[begin];
		while (arr[end] >= key && begin < end)
			--end;
		if (begin != end)
			arr[begin] = arr[end];
	}
	if (begin == end)
		arr[begin] = key;
	return begin;
}

template<typename T>
void _FastSort2(T* arr, size_t begin, size_t end)
{
	assert(arr);
	if (begin >= end)
		return;
	T div = SortPart2(arr,begin,end);
	_FastSort2(arr, begin, div - 1);
	_FastSort2(arr, div + 1, end);
}

template<class T>
void FastSort2(T* arr, size_t begin, size_t end)
{
	_FastSort2(arr, begin, end);
	Print(arr, end+1);
}


//快速排序之前后指针法 （递归实现）

template<class T>
T SortPart3(T* arr, size_t begin, size_t end)
{
	assert(arr);
	int cur = begin;
	int prev = cur - 1;
	int key = arr[end];
	while (cur < end){
		while (cur < end && arr[cur] >= key)
			++cur;
		if (cur < end && ++prev != cur)
			swap(arr[prev], arr[cur]);
		++cur;
	}
	swap(arr[++prev], arr[end]);
	return prev;
}

template<class T>
void _FastSort3(T* arr, size_t begin, size_t end)
{
	assert(arr);
	if (begin >= end)
		return;
	T div = SortPart3(arr, begin, end);
	_FastSort3(arr, begin, div - 1);
	_FastSort3(arr, div + 1, end);
}

template<class T>
void FastSort3(T* arr, size_t begin, size_t end)
{
	_FastSort3(arr, begin, end);
	Print(arr, end+1);
}

//选择排序 
template<class T>
void SelectSort1(T* arr, size_t n)
{
	assert(arr);
	for (size_t end = n - 1; end > 0; --end){
		size_t max = 0;
		for (size_t i = 1; i < end; ++i){
			if (arr[max] < arr[i])
				max = i;

		}
		if (max != end)
			swap(arr[max], arr[end]);
	}
	Print(arr, n);
}

//选择排序优化
template<class T>
void SelectSort2(T* arr, size_t n)
{
	assert(arr);
	size_t begin = 0;
	size_t end = n - 1;
	for (; begin < end; ++begin, --end){
		size_t min = begin;
		size_t max = begin;
		for (size_t i = begin; i < end; ++i){
			if (arr[max] < arr[i])
				max = i;
			if (arr[min] > arr[i])
				min = i;
		}
		if (max != end)
			swap(arr[max], arr[end]);
		if (end == min)
			min = max;
		if (min != begin)
			swap(arr[min], arr[begin]);
	}
	Print(arr, n);
}



int main()
{
	int arr[14] = { 7, 3, 46, 6, 0, 2, 90, 4, 3, 56, 12, 8, 45, 2 };
	/*int brr[14] = { 4, 17, 5, 2, 9, 8, 1, 3, 7, 0, 3, 56, 90, 1 };
	int crr[] = { 2, 5, 3, 7, 1, 8, 0, 3, 5, 8, 1, 9, 7 };*/
	//InsertSort<int> (arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort<int>  (arr, sizeof(arr) / sizeof(arr[0]));
	//FastSort1<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//FastSort2<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//FastSort3<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	SelectSort2<int>(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}

