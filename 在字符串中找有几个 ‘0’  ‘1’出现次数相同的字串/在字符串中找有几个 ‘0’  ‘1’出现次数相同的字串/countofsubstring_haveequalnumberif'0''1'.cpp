#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ע�����Ŀ��Ҫ���ַ���ֻ������1����0�������ַ� ����Ҫ��ġ�1����0��
//���ִ�����ͬ���ִ���1����0������������
//�����ִ���1100����0011������Ҫ��  ��1001��������Ҫ��
//Give a string s, count the number of non-empty (contiguous) substrings that 
//have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings 
//are grouped consecutively. 
//Substrings that occur multiple times are counted the number of times they occur.

class Solution {
public:
	int countBinarySubstrings(string s)
	{
		vector<int> _v;
		int count = 1;
		int ret = 0;
		for (size_t i = 1; i <= s.size(); ++i){//ע�������Ƿ����� i <= s.size() 
			if (s[i] == s[i - 1]){             //������ΪҪ�á�\0�������һ���ַ��Ƚϵó���=��
				count++;                       //����
			}
			else{
				_v.push_back(count);           //�Ӷ���ת��ע����һ�����������м�����ͬ���ַ�
				count = 1;                     //����vector��
			}
		}
		for (size_t i = 1; i < _v.size(); ++i){
			ret += min(_v[i], _v[i - 1]);
		}
		return ret;
	}
};

int main()
{
	string s("00110011");//�������Ĺ��캯��֧����ʽ����ת��
	Solution sol;
	int ret = sol.countBinarySubstrings(s);
	cout << ret << endl;
	system("pause");
	return 0;
}