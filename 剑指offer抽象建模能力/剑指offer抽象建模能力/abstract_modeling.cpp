#include<iostream>
#include<windows.h>
#include<algorithm>
#include<list>

using namespace std;

//骰子点数概率问题
//递归解法  (n 很大时效率不高)
int g_maxValue = 6;
void _Probability(int origin, int current, int sum, int* probability)
{
	if (current == 1 )//(current == origin / 2 + 1)
		probability[sum - origin]++;//origin是不变的骰子的个数
	else{
		for (size_t i = 1; i <= g_maxValue; ++i){//本函数内的sum是之前算过的骰子可能的点数和
												// i 是当前骰子可能的点数
			_Probability(origin, current - 1, i + sum, probability);
			//递归调用每一次退回到当前位置说明已经统计好了如果本骰子点数为i时 其总点数有多少种可能出现
			//下一次循环是计算当前骰子点数为 i+1时 其总点数有多少种可能出现 
		}
	}
}

void Probability(int num, int* probability)
{
	for (size_t i = 1; i <= g_maxValue; ++i)
		_Probability(num, num, i, probability);//计算第一个骰子为i时 其总点数有多少种可能出现
}

void PrintProbability(int num)
{
	if (num < 1)
		return;
	int maxSum = num * g_maxValue;//num个骰子点数之和最大为 6 * num
	int* probability = new int[maxSum - num + 1];//因为num个骰子点数之和最少为num
	for (size_t i = num; i <= maxSum; ++i){
		probability[i - num] = 0;//num个骰子数之和存放在 下标i - num 中初始化为0
	}
	Probability(num, probability);//在数组中放好每一个点数之和存在几种组合的可能性
	int total = pow((double)g_maxValue, num);
	for (size_t i = num; i <= maxSum /*maxSum / 2 + num / 2*/; ++i){//每一个总点数出现的可能性次数除以仍num个骰子出现的所有情况
		double ratio = (double)probability[i - num] / total;
		//printf("%d, %d: %e\n", i, num * (g_maxValue+1) - i, ratio);
		printf("%d  :%e\n", i, ratio);
	}
	delete[] probability;
}

//非递归解法 循环解决时间性能较好
//两个数组交替作为对方的 截止上一个骰子各个点数总数的出现次数
void PrintProbability2(int num)
{
	if (num < 1)
		return;
	int* probability[2];//两个数组保存每一个总数出现的个数
	probability[0] = new int[num * g_maxValue + 1];
	probability[1] = new int[num * g_maxValue + 1];
	for (int i = 0; i < g_maxValue * num + 1; ++i){
		probability[0][i] = 0; probability[1][i] = 0;
	}
	size_t flag = 0;
	for (size_t i = 1; i <= g_maxValue; ++i){
		probability[flag][i] = 1;//只有一个骰子时 骰子和为1~6的次数为1
	}
	for (size_t k = 2; k <= num; ++k)//k用来做不断增长的骰子总数
	{
		for (size_t i = 0; i < k; ++i){
			probability[1 - flag][i] = 0;
		}//作为要记录加一个骰子时的总数可能性数量 先置零 骰子数超过六之后点数之和不可以小于六
		
		for (size_t i = k; i <= g_maxValue * k; ++i){
			probability[1 - flag][i] = 0;//此时probabity[1-flag][i]是基于骰子总数是k-1个的时候 所以置零
			for (size_t j = 1; j <= i && j <= g_maxValue; ++j){
				probability[1 - flag][i] += probability[flag][i - j];
				//另一个数组第n个数字为前一个数组对应的第 n-1 n-2 .。。。。n-6 之和
			}
		}
		flag = 1 - flag;//交换这两个数组
	}
	double total = pow((double)g_maxValue, num);
	for (size_t i = num; i <= g_maxValue * num; ++i){
		double ratio = (double)probability[flag][i] / total;
		printf("%d : %e\n", i, ratio);
	}
	delete[] probability[0];
	delete[] probability[1];
}

//扑克牌顺子
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
			numOfZero++;//求有多少个零
		}
	}
	int smal = numOfZero;
	int big = smal + 1;
	while (big < length){//求空缺数
		if (arr[smal] == arr[big]){//顺子
			return false;
		}
		numOfGap += arr[big] - arr[smal] - 1;
		++big;
		++smal;
	}
	return numOfGap <= numOfZero;
}

//圆圈中最后剩下的数字

//1.单链表求解约瑟夫环解法 //使用库函数和迭代器
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
		list<int>::iterator next = ++current;//用 next保存被删除结点的下一个结点
		if (next == number.end())
			next = number.begin();
		--current;
		number.erase(current);
		current = next;
	}
	return *current;
}

//创新解法 运用数学知识
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