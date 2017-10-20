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
//		string ret;//����һ�����ַ������������ؽ��
//		if (_str.empty() == true || arg.empty() == true)//�ַ�������Ϊ�գ�����arg����Ϊ��
//			return ret;
//		int i = 0;
//		while (_str.find("%s") != string::npos)
//		{
//			ret += _str.substr(0, _str.find("%s"));//�ѵ�һ�γ���"%s"֮ǰ���ַ������Ӵ��ó�������ret
//			ret += arg[i++];//��arg��Ҫ�����滻���ַ�����ret����
//			_str = _str.substr(_str.find("%s") + 2);//��%��û���滻�Ĳ��ָ�ֵ�����
//		}
//		ret += _str;//���������Ҫ�滻�Ĳ���  
//		while (i < m)//�Ѿ��滻�꣬��argʣ�µĲ��ּӸ�ret
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
	if (_str.empty() || arg.empty())//str arg ������Ϊ��
		return ret;
	int i = 0;
	while (_str.find("%s") != string::npos)
	{
		ret += _str.substr(0, _str.find("%s"));//�ѵ�һ�γ���"%s"֮ǰ���ַ������Ӵ��ó�������ret
		ret += arg[i++];//��arg��Ҫ�����滻���ַ�����ret����
		_str = _str.substr(_str.find("%s") + 2);//��%��û���滻�Ĳ��ָ�ֵ���
	}
	ret += _str;
	while (i < m){
		ret += arg[i++];   //�Ѷ����arg��Ԫ�ط���ret����
	}
	return ret;
}

string Formatstring2(const string& str, int n, vector<char>& arg, int m)
{
	string ret = "";
	size_t count = 0;
	size_t i = 0;
	if (str.empty() || arg.empty())//str arg ������Ϊ��
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