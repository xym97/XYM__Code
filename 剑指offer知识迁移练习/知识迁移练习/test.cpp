#include<iostream>
#include<windows.h>

using namespace std;

//���������������г��ֵĴ���
//�����ֵ�һ�γ��ֵ�λ��
int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = start + (end - start) / 2;//����ƽ�����ķ������Է�ֹ��СԽ�������
	int middleData = data[middleIndex];//�ҵ��м������

	if (middleData == k){
		if ((middleIndex > 0 && data[middleIndex - 1] != k)\
			|| middleIndex == 0)//����м�������ǵ�һ�����ֵĸ����� ��ֻ��һ������
			return middleIndex;//���ص�һ�������ֵ�λ��
		else
			end = middleIndex - 1;//�������˵�� ��Ҫ��ǰ�벿���ҵ�һ��
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	return GetFirstK(data,length,k,start,end);
}
//ͬ��������λ��
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
//֪���˸����ֵ�һ�κ����һ�γ��ֵ�λ�� ������λ�������һ���ǳ��ֵĸ���
int GetNumberOfK(int* data, int length, int k)
{
	int number = 0;
	if (data != NULL && length > 0){//�����������
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);
		if (first >= 0 && last >= 0)
			number = last - first + 1;
	}
	return number;
}

//��������ֻ����һ�ε����� �������������־����������� ����������ֻ������һ��
//������num�Ķ�����λ������͵���1��λ
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
//�鿴 num�Ķ����Ʊ�ʾ�д��ұ������indexBitλ�ǲ���1
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

//��ת����˳��   �����ַ���
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
		}//Ϊʲô*pBegin ��= ����0��Ҫ����ǰ���ж�
		//��Ϊ�����������д�����������жϻ��γ���ѭ��
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

//��Ϊs���������� ------��Ϊs��������������
//1.�ҳ������к�Ϊs���������� �ҵ��˲�ͬ�������ġ�
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

//----��������Ǩ�Ƶ���Ϊs��������������
//����һ������s����ӡ�����к�Ϊs��������������
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
	int curSum = smal + big;//��ע������curSum�Ƕ�̬�仯�� �����1+2
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