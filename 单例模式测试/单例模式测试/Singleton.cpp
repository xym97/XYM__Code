#include<iostream>
#include<thread>
#include<mutex>
#include<windows.h>

using namespace std;
//����ʽ
class Singleton1
{
public:
	static Singleton1* GetInstance()
		//��ȡָ���������ָ��,
		//��Ϊ�����ⲻ�ܴ�����������Ҫ���ú�������Ϊstatic��,
		//ʹ�����������ʹ������������޶�������ȡ

	{
		if (NULL == _Instance)//�;�̬��Ա����һ��ֻ֤����һ��ʵ��
			_Instance = new Singleton1();
		return _Instance;
	}
private:
	Singleton1(){};
	static Singleton1* _Instance;
	//��̬���Ա��� �����ж��ٸ������ʵ�� ��̬��Ա����ֻ���ھ�̬ȫ������һ��
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
	static Singleton* _Instance;//��̬���Ա��� �����ж��ٸ������ʵ�� ��̬��Ա����ֻ���ھ�̬ȫ������һ��
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