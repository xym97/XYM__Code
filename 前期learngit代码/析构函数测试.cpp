#include<iostream>
#include<stdlib.h>

using namespace std;

class A
{
public:
    ~A()//virtual;
	{
		cout<<'A'<<endl;
	}
	int _a;
};

class B:public A
{
public:
    ~B()
	{
		cout<<'B'<<endl;
	}
	int _b;
};

int main()
{
	B* p = new B;//A* p = new B;
	delete p;
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	//cout<<sizeof();
	system("pause");
	return 0;
}