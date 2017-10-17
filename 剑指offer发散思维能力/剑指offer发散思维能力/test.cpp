#include<iostream>
using namespace std;

//���������������ʵ�ּӷ�����
int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

//��1+2+������+n
//���캯��
//��ľ�̬��Ա
class Temp
{
private:
	static unsigned int N;
	static unsigned int sum;
public:
	Temp(){ ++N, sum += N; }
	static void Reset(){ sum = 0; N = 0; }
	static unsigned int GetSum(){ return sum; }
};

unsigned int Temp::sum = 0;
unsigned int Temp::N = 0;

unsigned int Sum_Solution1(unsigned int n)
{
	Temp::Reset();
	Temp* a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

//�����麯�����
class A;
A* Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;//��n����ȡ���������Ϊtrue ���Ϊfalse
	}
};
//A a;
//B b;
//Array[0] = &a;
//Array[1] = &b;
//int value = Array[1]->Sum(9);

//���ú���ָ�����
unsigned int Sum3(unsigned int n)
{
	return 0;
}

unsigned int Sum3_(unsigned int n)
{
	typedef unsigned int(*fun) (unsigned int);
	static fun f[2] = { Sum3, Sum3_ };
	return n + f[!!n](n - 1);
}

//����ģ���������
template <unsigned int n>
struct Sum
{
	enum value { N = Sum<n - 1>::N + n; };
};
template<>
struct Sum<1>
{
	enum value{N = 1};
};

int main()
{
	cout << Add(4, 76) << endl;
	cout << Sum_Solution1(9) << endl;
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(9);
	cout << value << endl;
	cout << Sum3_(9) << endl;
	system("pause");
	return 0;
}

