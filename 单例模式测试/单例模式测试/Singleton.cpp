#include<iostream>
#include<thread>
#include<mutex>
#include<windows.h>

using namespace std;
//懒汉式
class Singleton1
{
public:
	static Singleton1* GetInstance()
		//获取指向该类对象的指针,
		//因为在类外不能创建对象，所以要将该函数声明为static的,
		//使得在类外可以使用类的作用域限定符来获取

	{
		if (NULL == _Instance)//和静态成员变量一起保证只产生一份实例
			_Instance = new Singleton1();
		return _Instance;
	}
private:
	Singleton1(){};
	static Singleton1* _Instance;
	//静态成言变量 不管有多少个对象的实例 静态成员变量只有在静态全局区的一份
};
Singleton1* Singleton1::_Instance = NULL;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_Instance == NULL){
			std::lock_guard<mutex> lk(mutex);
			if (_Instance == NULL)
				_Instance = new Singleton();
		}
		return _Instance;
	}
	static void DelInstance()
	{
		std::lock_guard<mutex> lk(mutex);
		if (_Instance)
		{
			delete _Instance;
			_Instance = NULL;
		}
	}
private:
	Singleton():_data(0){}
	//class Dele
	//{
	//public:
	//	~Dele()
	//	{
	//		std::lock_guard<mutex> lk(mutex);
	//		if (Singleton::_Instance)
	//			delete Singleton::_Instance;
	//	}
	//};
	int _data;
	static mutex _mutex;
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	//static Dele _Dele;
	static Singleton* _Instance;//静态成言变量 不管有多少个对象的实例 静态成员变量只有在静态全局区的一份
};

Singleton* Singleton::_Instance = NULL;
mutex Singleton::_mutex;


class Singleton
{
public:
	static Singleton* GetInstance()
	{
		static Singleton _Instance;
		return &_Instance;
	}
private:
	int _data;
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	Singleton():_data(0){};
};

int main()
{
	
	system("pause");
	return 0;
}