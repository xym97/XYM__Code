#include<iostream>

//�����ֻ���ڶ��ϴ������� �����Ա��̳�
class Sealed
{
public:
	static Sealed* Getinst()
	{
		return new Sealed();
	}

	static void Destory(Sealed* p)
	{
		if (p){
			delete p;
			p = NULL;
		}
	}

private:
	Sealed()
	{}

	~Sealed()
	{}
};

//�����ֻ������ջ�ϴ�������
class A
{
public:
	A()
		:_a(0)
	{}

	~A()
	{}
private:
	void* operator new (size_t n)
	{
		return NULL;
	}

	void operator delete(void* p)
	{}

	int _a;
};

//Sealed1����಻���Ա��̳�



class sealedClass;

class Tmp
{
public:
	friend sealedClass;
private:
	Tmp()
		:_a(0)
	{}
	~Tmp()
	{}
	int _a;
};

class sealedClass : virtual public Tmp
{
public:
	sealedClass()
		:_b(1)
	{}

	~sealedClass()
	{}
private:
	int _b;
};

class C :public sealedClass
{
public:
	C()
		:_c(3)//���ֱ������
	{}
private:
	int _c;
};
