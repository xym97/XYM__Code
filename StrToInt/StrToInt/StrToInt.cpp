#include<stdio.h>
#include<stdlib.h>

//enum Status{ KValid = 0, KInvalid };
//int g_nStatus = KValid;
//
//long long StrToInCode(const char* str, bool minus)
//{
//	long long num = 0;
//	while (*str != '\0'){
//		if (*str <= '9' && *str >= '0'){
//			int flag = minus ? 1 : -1;
//			num = num * 10 + flag *(*str - '0');
//			if ((num > 0x7FFFFFFF && minus) || (num < (signed int)0x80000000 && !minus))
//			{
//				num = 0;
//				break;
//			}
//			str++;
//		}
//		else{
//			num = 0;
//			break;
//		}
//		if (*str == '\0'){
//			g_nStatus = KValid;
//		}
//	}
//	return num;
//}
//
//int StrToInt(const char* str)
//{
//	g_nStatus = KInvalid;
//	long long num = 0;
//
//	if (*str != NULL && *str != '\0'){
//		bool minus = true;
//		if (*str == '+'){
//			str++;
//		}
//		else if(*str == '-'){
//			minus = false;
//			str++;
//		}
//		if (*str != '\0'){
//			num = StrToInCode(str, minus);
//		}
//	}
//	return (int)num;
//}


//定义一个类不能被继承
class SealedClass1
{
public:
	static SealedClass1*  GetInstance()
	{
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance)
	{
		delete pInstance;
	}
private:
	SealedClass1()
	{}
	~SealedClass1()
	{}
	//该类只能得到在堆上的实例
};

template <class T>
class MakeSealed
{
	friend T;
private:
	MakeSealed()
	{}
	~MakeSealed()
	{}
};

class Sealed : virtual public MakeSealed<Sealed>
{
public:
	Sealed()
	{}
	~Sealed()
	{}

};

class test : public SealedClass1
{
private:
	int a;
public:
	test()
		:a(1)
	{}

	~test()
	{}
};

//////////////////////////////


int main()
{
	//char *str = "1234q567";
	int ret = 0;
	test ac;
	/*ret = StrToInt("-1234567");
	printf("%d\n", ret);
	printf("%d\n", g_nStatus);*/
    		
	system("pause");
	return 0;
}