#include<iostream>
#include<windows.h>
#include<algorithm>
#include<list>

using namespace std;

//���ӵ�����������
//�ݹ�ⷨ  (n �ܴ�ʱЧ�ʲ���)
int g_maxValue = 6;
void _Probability(int origin, int current, int sum, int* probability)
{
	if (current == 1 )//(current == origin / 2 + 1)
		probability[sum - origin]++;//origin�ǲ�������ӵĸ���
	else{
		for (size_t i = 1; i <= g_maxValue; ++i){//�������ڵ�sum��֮ǰ��������ӿ��ܵĵ�����
												// i �ǵ�ǰ���ӿ��ܵĵ���
			_Probability(origin, current - 1, i + sum, probability);
			//�ݹ����ÿһ���˻ص���ǰλ��˵���Ѿ�ͳ�ƺ�����������ӵ���Ϊiʱ ���ܵ����ж����ֿ��ܳ���
			//��һ��ѭ���Ǽ��㵱ǰ���ӵ���Ϊ i+1ʱ ���ܵ����ж����ֿ��ܳ��� 
		}
	}
}

void Probability(int num, int* probability)
{
	for (size_t i = 1; i <= g_maxValue; ++i)
		_Probability(num, num, i, probability);//�����һ������Ϊiʱ ���ܵ����ж����ֿ��ܳ���
}

void PrintProbability(int num)
{
	if (num < 1)
		return;
	int maxSum = num * g_maxValue;//num�����ӵ���֮�����Ϊ 6 * num
	int* probability = new int[maxSum - num + 1];//��Ϊnum�����ӵ���֮������Ϊnum
	for (size_t i = num; i <= maxSum; ++i){
		probability[i - num] = 0;//num��������֮�ʹ���� �±�i - num �г�ʼ��Ϊ0
	}
	Probability(num, probability);//�������зź�ÿһ������֮�ʹ��ڼ�����ϵĿ�����
	int total = pow((double)g_maxValue, num);
	for (size_t i = num; i <= maxSum /*maxSum / 2 + num / 2*/; ++i){//ÿһ���ܵ������ֵĿ����Դ���������num�����ӳ��ֵ��������
		double ratio = (double)probability[i - num] / total;
		//printf("%d, %d: %e\n", i, num * (g_maxValue+1) - i, ratio);
		printf("%d  :%e\n", i, ratio);
	}
	delete[] probability;
}

//�ǵݹ�ⷨ ѭ�����ʱ�����ܽϺ�
//�������齻����Ϊ�Է��� ��ֹ��һ�����Ӹ������������ĳ��ִ���
void PrintProbability2(int num)
{
	if (num < 1)
		return;
	int* probability[2];//�������鱣��ÿһ���������ֵĸ���
	probability[0] = new int[num * g_maxValue + 1];
	probability[1] = new int[num * g_maxValue + 1];
	for (int i = 0; i < g_maxValue * num + 1; ++i){
		probability[0][i] = 0; probability[1][i] = 0;
	}
	size_t flag = 0;
	for (size_t i = 1; i <= g_maxValue; ++i){
		probability[flag][i] = 1;//ֻ��һ������ʱ ���Ӻ�Ϊ1~6�Ĵ���Ϊ1
	}
	for (size_t k = 2; k <= num; ++k)//k������������������������
	{
		for (size_t i = 0; i < k; ++i){
			probability[1 - flag][i] = 0;
		}//��ΪҪ��¼��һ������ʱ���������������� ������ ������������֮�����֮�Ͳ�����С����
		
		for (size_t i = k; i <= g_maxValue * k; ++i){
			probability[1 - flag][i] = 0;//��ʱprobabity[1-flag][i]�ǻ�������������k-1����ʱ�� ��������
			for (size_t j = 1; j <= i && j <= g_maxValue; ++j){
				probability[1 - flag][i] += probability[flag][i - j];
				//��һ�������n������Ϊǰһ�������Ӧ�ĵ� n-1 n-2 .��������n-6 ֮��
			}
		}
		flag = 1 - flag;//��������������
	}
	double total = pow((double)g_maxValue, num);
	for (size_t i = num; i <= g_maxValue * num; ++i){
		double ratio = (double)probability[flag][i] / total;
		printf("%d : %e\n", i, ratio);
	}
	delete[] probability[0];
	delete[] probability[1];
}

//�˿���˳��
int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinue(int* arr, int length)
{
	if (NULL == arr || length < 1)
		return false;

	qsort(arr, length, sizeof(int), compare);
	int numOfZero = 0;
	int numOfGap = 0;
	for (size_t i = 0; i < length; ++i){
		if (arr[i] == 0){
			numOfZero++;//���ж��ٸ���
		}
	}
	int smal = numOfZero;
	int big = smal + 1;
	while (big < length){//���ȱ��
		if (arr[smal] == arr[big]){//˳��
			return false;
		}
		numOfGap += arr[big] - arr[smal] - 1;
		++big;
		++smal;
	}
	return numOfGap <= numOfZero;
}

//ԲȦ�����ʣ�µ�����

//1.���������Լɪ�򻷽ⷨ //ʹ�ÿ⺯���͵�����
int LastRemaining(int n, int m)
{
	if (n < 0 || m < 0)
		return -1;
	size_t i = 0;
	list<int> number;
	for (i = 1; i <= n; ++i)
		number.push_back(i);
	list<int>::iterator current = number.begin();
	while (number.size() > 1)
	{
		for (size_t i = 1; i < m; ++i){
			current++;
			if (current == number.end())
				current = number.begin();
		}
		list<int>::iterator next = ++current;//�� next���汻ɾ��������һ�����
		if (next == number.end())
			next = number.begin();
		--current;
		number.erase(current);
		current = next;
	}
	return *current;
}

//���½ⷨ ������ѧ֪ʶ
int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;
	return last;
}


int main()
{
	PrintProbability(6);
    //PrintProbability2(6);
	cout << LastRemaining(17, 3) << endl;
	system("pause");
	return 0;
}