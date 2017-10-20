#include<iostream>

//这个类只能在堆上创建对象 不可以被继承
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

//这个类只可以在栈上创建对象
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

//Sealed1这个类不可以被继承



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
		:_c(3)//出现编译错误
	{}
private:
	int _c;
};
