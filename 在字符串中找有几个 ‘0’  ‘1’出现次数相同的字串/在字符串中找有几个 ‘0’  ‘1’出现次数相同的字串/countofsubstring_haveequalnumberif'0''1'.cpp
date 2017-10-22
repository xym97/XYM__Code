#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//注意次题目中要求字符串只包含‘1’‘0’两个字符 符合要求的‘1’‘0’
//出现次数相同的字串‘1’‘0’必须成组出线
//比如字串‘1100’‘0011’符合要求  ‘1001’不符合要求
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
		for (size_t i = 1; i <= s.size(); ++i){//注意这里是反常的 i <= s.size() 
			if (s[i] == s[i - 1]){             //这是因为要用‘\0’和最后一个字符比较得出！=的
				count++;                       //结论
			}
			else{
				_v.push_back(count);           //从而跳转到注释这一行求出把最后有几个相同的字符
				count = 1;                     //插入vector中
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
	string s("00110011");//单参数的构造函数支持隐式类型转换
	Solution sol;
	int ret = sol.countBinarySubstrings(s);
	cout << ret << endl;
	system("pause");
	return 0;
}