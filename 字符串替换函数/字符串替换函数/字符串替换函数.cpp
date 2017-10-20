#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;
//class StringFormat
//{
//public:
//	string formatstring(const string& str, int n, vector<char>& arg, int m)
//	{
//		string _str = str;
//		string ret;//定义一个空字符串，用来返回结果
//		if (_str.empty() == true || arg.empty() == true)//字符串不能为空，或者arg不能为空
//			return ret;
//		int i = 0;
//		while (_str.find("%s") != string::npos)
//		{
//			ret += _str.substr(0, _str.find("%s"));//把第一次出现"%s"之前的字符串（子串拿出来）给ret
//			ret += arg[i++];//把arg里要拿来替换的字符加在ret后面
//			_str = _str.substr(_str.find("%s") + 2);//把%后没有替换的部分赋值后继续
//		}
//		ret += _str;//加上最后不需要替换的部分  
//		while (i < m)//已经替换完，把arg剩下的部分加给ret
//		{
//			ret += arg[i++];
//		}
//		return ret;
//	}
//
//};

string Formatstring1(const string& str, int n, vector<char>& arg, int m)
{
	string ret;
	string _str = str;
	if (_str.empty() || arg.empty())//str arg 不可以为空
		return ret;
	int i = 0;
	while (_str.find("%s") != string::npos)
	{
		ret += _str.substr(0, _str.find("%s"));//把第一次出现"%s"之前的字符串（子串拿出来）给ret
		ret += arg[i++];//把arg里要拿来替换的字符加在ret后面
		_str = _str.substr(_str.find("%s") + 2);//把%后没有替换的部分赋值后继
	}
	ret += _str;
	while (i < m){
		ret += arg[i++];   //把多余的arg中元素放在ret后面
	}
	return ret;
}

string Formatstring2(const string& str, int n, vector<char>& arg, int m)
{
	string ret = "";
	size_t count = 0;
	size_t i = 0;
	if (str.empty() || arg.empty())//str arg 不可以为空
		return ret;
	for (; i < n; ++i){
		if (str[i] == '%' && i + 1 < n && str[i + 1] == 's'){
			ret.push_back(arg[count]);
			i++;
			count++;
		}
		else{
			ret.push_back(str[i]);
		}
		
	}
	while (count < m){
		ret += arg[count++];
	}
	return ret;
}



int main()
{
	/*StringFormat sf;
	const string str("A%sC%sE");
	char arr[] = { 'B', 'D', 'F' };
	vector<char> arg;
	int n = str.length();
	int m = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < m; i++)
	{
		arg.push_back(arr[i]);
	}
	string ret = sf.formatstring(str, n, arg, m);
	cout << ret.c_str() << endl;*/
	const string str("A%sC%sE");
	char arr[] = { 'B', 'D', 'F', 'G' };
	vector<char> arg;
	int n = str.length();
	int m = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < m; i++){
		arg.push_back(arr[i]);
	}
	string ret = Formatstring2(str, n, arg, m);
	cout << ret.c_str() << endl;
	system("pause");
	return 0;
}