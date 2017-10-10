#include<iostream>
#include<windows.h>

using namespace std;

//数字在排序数组中出现的次数
//求数字第一次出现的位置
int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = start + (end - start) / 2;//该求平均数的方法可以防止大小越界的问题
	int middleData = data[middleIndex];//找到中间的数字

	if (middleData == k){
		if ((middleIndex > 0 && data[middleIndex - 1] != k)\
			|| middleIndex == 0)//如果中间的数字是第一个出现的该数字 或只有一个数字
			return middleIndex;//返回第一个该数字的位置
		else
			end = middleIndex - 1;//如果不是说明 还要在前半部分找第一个
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	return GetFirstK(data,length,k,start,end);
}
//同理求最后的位置
int GetLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = start + (end - start) / 2;
	int middleData = data[middleIndex];

	if (middleData == k){
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k)\
			|| middleIndex == length - 1)
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
}
//知道了该数字第一次和最后一次出现的位置 将两个位置相减加一就是出现的个数
int GetNumberOfK(int* data, int length, int k)
{
	int number = 0;
	if (data != NULL && length > 0){//处理特殊情况
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);
		if (first >= 0 && last >= 0)
			number = last - first + 1;
	}
	return number;
}

//找数组中只出现一次的数字 数组中其他数字均出现了两次 有两个数字只出现了一次
//在整数num的二进制位中找最低的是1的位
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
//查看 num的二进制表示中从右边数起的indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumsAppearOnce(int data[], int length)
{
	if (data == NULL || length < 2)
		return ;
	int result = 0;
	for (size_t i = 0; i < length; ++i)
		result ^= data[i];
	unsigned int indexOf1 = FindFirstBitIs1(result);
	int num1 = 0;
	int num2 = 0;
	for (int j = 0; j < length; ++j){
		if (IsBit1(data[j], indexOf1))
			num1 ^= data[j];
		else
			num2 ^= data[j];
	}
	cout << num1 << " " << num2 << endl;
}

//翻转单词顺序   左旋字符串
//1.
void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;
	while (pBegin < pEnd){
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentencs(char* pData)
{
	if (pData == NULL)
		return NULL;
	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0'){
		++pEnd;
	}
	--pEnd;
	Reverse(pBegin, pEnd);
	pBegin = pEnd = pData;
	while (*pBegin != '\0'){
		if (*pBegin == ' '){
			pBegin++;
			pEnd++;
		}//为什么*pBegin ！= ‘、0’要在最前面判断
		//因为否则下面三行代码如果最先判断会形成死循环
	    else if (*pEnd == ' ' || *pEnd == '\0'){
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else{
			pEnd++;
		}
	}
	return pData;
}

//2.
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != NULL){
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength){
			char* pStrFS = pStr;
			char* pStrFE = pStr + n - 1;
			char* pStrSS = pStr + n;
			char* pStrSE = pStr + nLength - 1;
			Reverse(pStrFS, pStrFE);
			Reverse(pStrSS, pStrSE);
			Reverse(pStr, pStrSE);
		}
	}
	return pStr;
}

//和为s的两个数字 ------和为s的连续正数序列
//1.找出数组中和为s的两个数字 找到了不同找其他的。
bool FindNumBerWithSum(int data[], int length, int sum, int* num1, int*num2)
{
	bool found = false;
	if (num1 == NULL || num2 == NULL || length < 1)
		return found;
	size_t begin = 0;
	size_t end = length - 1;
	while (begin < end){
		long long curSum = data[begin] + data[end];
		if (curSum == sum){
			*num1 = data[begin];
			*num2 = data[end];
			found = true;
			break;
		}
		else if (curSum < sum)
			begin++;
		else
			end--;
	}
	return found;
}

//----将此问题迁移到和为s的连续整数序列
//输入一个正数s，打印出所有和为s的连续正数序列
void Print(int smal, int big)
{
	for (int i = smal;  i <= big; ++i)
		cout << i ;
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;
	int smal = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = smal + big;//请注意这里curSum是动态变化的 最初是1+2
	while (smal < middle){
		if (curSum == sum)
			Print(smal, big);
		while (smal < middle && curSum > sum){
			curSum -= smal;
			smal++;
			if (curSum == sum)
				Print(smal, big);
		}
		big++;
		curSum += big;
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8 };
	int brr[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int crr[] = { 1, 2, 4, 7, 11, 15 };
	int a = 0;
	int b = 0;
	int* num1 = &a;
	int* num2 = &b;
	char sentence[] = "I am a student";
	char test[] = "abcdefg";
	cout<<LeftRotateString(test,2)<<endl;
	printf("%s\n",ReverseSentencs(sentence));
	
	FindNumBerWithSum(crr, sizeof(crr) / sizeof(crr[0]),15,num1,num2);
	cout << *num1 << " " << *num2 << endl;
	FindContinuousSequence(15);
	//cout<< GetNumberOfK(arr, sizeof(arr) / sizeof(arr[0]), 3) << endl;
	//FindNumsAppearOnce(brr, sizeof(brr) / sizeof(brr[0]));
	system("pause");
	return 0;
}