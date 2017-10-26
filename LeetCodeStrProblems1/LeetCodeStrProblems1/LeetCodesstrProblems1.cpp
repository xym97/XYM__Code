#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<sstream>
using namespace std;
//Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
//There is no limit on how many times a digit can be reused.
//You may assume the given input string is always valid.
//For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
//Example 1:
//Input : "19:34"
//Output : "19:39"
//Explanation : The next closest time choosing from digits 1, 9, 3, 4, is 19 : 39,
//which occurs 5 minutes later.It is not 19 : 33, because this occurs 23 hours and 59 minutes later.
// Example 2 :
// Input : "23:59"
//Output : "22:22"
//Explanation : The next closest time choosing from digits 2, 3, 5, 9, is 22 : 22.
//It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

string NextCloseTime(const string& time)
{
	int mins[] = { 600, 60, 10, 1 };
	string newtime = time;
	unsigned int colon = newtime.find(':');
	string next = "0000";//��ʾ�ҵ�����һ��ʱ���string
	//������ʱ�������ʾ�Ƕ���
	int cur = stoi(newtime.substr(0, colon)) * 60 + stoi(newtime.substr(colon + 1));
	for (size_t i = 1, d = 0; i < 1440 && d < 4; ++i){//һ����1440��
		int m = (cur + i) % 1440;
		for (d = 0; d < 4; ++d){
			next[d] = '0'+ m / mins[d];
			m %= mins[d];
			if (newtime.find(next[d]) == string::npos)
				break;
			//������ѭ���Ǻ��� d �� i ���������� �������ѭ������Ϊd==4���Ƴ��Ļ�
			//next string�д�ŵ�ʱ�����Ҫ�� ��ѭ��Ҳd==4���Ƴ���
		}
	}
	return next.substr(0, 2) + ':' + next.substr(2, 2);
}

//Given a string containing only three types of characters: '(', ')' 
//and '*', write a function to check whether this string is valid. 
//We define the validity of a string by these rules: 
//1.Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//2.Any right parenthesis ')' must have a corresponding left parenthesis '('.
//3.Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//4.'*' could be treated as a single right parenthesis ')' or a single left parenthesis '
//(' or an empty string.
//5.An empty string is also valid.

//Example 1:
//Input : "()"
//Output : True

// Example 2 :
//input : "(*)"
//Output : True

// Example 3 :
//Input : "(*))"
// Output : True

bool Is_corresponding(const string& corresponding)
{
	string test = corresponding;
	int StarIsleft = 0;  //��������*���ǣ�
	int StarIsright = 0;//��������*����  ��
	for (size_t i = 0; i < test.length(); ++i){
		if (test[i] == '('){
			StarIsleft++;
			StarIsright++;
		}
		else if (test[i] == ')'){
			StarIsleft--;
			StarIsright--;
		}
		else{
			StarIsleft++;
			StarIsright--;
		}
		StarIsright = max(StarIsright, 0);//�� + *�������ڣ� StarIsrightС��0 û�й�ϵ
		                                  //��Ϊ������*�ǿ��Ե����ĸ��ݹ��� 4. 5.
		if (StarIsleft < 0)//��һ����ѭ������ ����ڱ����ַ��������У� + * ���������� ��
							//���ݹ���3. ��һ�����У��ò���ƥ�� ����ֱ�ӷ���false
							//�����ұ�������������ʱ�� �� + * ���� ���ڵ��� ��
			return false;
	}
	return StarIsright == 0;
}


bool judgeCircle(string moves) 
{
	string test = moves;
	int coordi1 = 0;
	int coordi2 = 0;
	for (size_t i = 0; i < test.length(); ++i){
		if (test[i] != 'U' && test[i] != 'D' && test[i] != 'L'\
			&& test[i] != 'R')
		++i;
		else if (test[i] == 'U') coordi1 -= 1;
		else if (test[i] == 'D') coordi1 += 1;
		else if (test[i] == 'L') coordi2 -= 1;
		else coordi2 += 1;
	}
	return coordi1 == 0 && coordi2 == 0;
			
}

int countSubstrings(string s) {
	int ret = 0; int n = s.length();
	for (int i = 0; i < n; ++i){
		for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
			ret++;//���ҡ�abcecba�������������ַ���Palindromic�ַ�������
		for (int j = 0; i - 1 - j >= 0 && i + j < n && s[i - 1 - j] == s[i + j]; j++)
			ret++;//���ҡ�abccba������ż�����ַ���Palindromic�ַ��ĸ���
	}
	return ret;
}

bool IsValidIPv4Block(string& block)
{
	int num = 0;
	if (block.size() < 0 || block.size() > 3)
		return false;//�ж�ÿһС��IPv4��ַ�����Ƿ�Ϸ�
	for (size_t i = 0; i < block.size(); ++i){//������ĳһ�鲻ֹһλ�ҵ�һλΪ��0��
		if (i == 0 && block[i] == '0' && block.size() > 1 || !isalnum(block[i]))
			return false;
		else{//���ַ���ת��Ϊ����
			num *= 10;
			num += block[i] - '0';
		}
	}
	return num <= 255;//ÿһ���С�����Դ���255
}
const string vaildIPv6chars("1234567890ABCDEFabcdef");//��һ��ȫ�ֱ���

bool IsValidIPv6Block(string& block)
{
	if (block.size() < 0 || block.size() > 4)
		return false;//�ж�ÿһС��IPv6��ַ�����Ƿ�Ϸ�
	for (size_t i = 0; i < block.size(); ++i){//ÿһ����ַ�����Ϸ�
		if (vaildIPv6chars.find(block[i]) == string::npos)
			return false;
	}
	return true;
}

string validIPAddress(string IP)
{
	string block;
	string rets[3] = { "IPv4", "IPv6", "Neither" };
	stringstream ss(IP);//����һ��ss��
	if (IP.substr(0, 4).find('.') != string::npos){//IPv4
		for (size_t i = 0; i < 4; ++i){
			if (!getline(ss, block, '.') || !IsValidIPv4Block(block))
				return rets[2];
		}
		return ss.eof() ? rets[0] : rets[2];
	}
	else if (IP.substr(0, 5).find(':') != string::npos){//IPv6
		for (size_t i = 0; i < 8; ++i){//���getline����ʧ�ܻ���һ���ж�Ϊ�Ƿ�����Neither
			if (!getline(ss, block, ':') || !IsValidIPv6Block(block))
				return rets[2];
		}
		return ss.eof() ? rets[1] : rets[2];//getline���������Ѿ��ɹ�����ss����β ����IPv6
	}
	return false;
}




void Test1()
{
	string time("19:34");
	cout << NextCloseTime(time) << endl;
	string corresponding("()()*");
	cout << Is_corresponding(corresponding) << endl;
	string moves("ULLDRR");
	cout << judgeCircle(moves) << endl;
	string s("abcbaeft");
	cout << countSubstrings(s) << endl;
	string ip("2001:0db8:85a3::8a2e:0370:7334");
	cout << validIPAddress(ip) << endl;
}

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(NULL), right(NULL){}
};

class Solution {
public:
	string tree2str(TreeNode* t) {
		return !t ? "" : to_string(t->val) + (t->left ? "(" + tree2str(t->left) + ")" : t->right ? "()" : "")
			+ (t->right ? "(" + tree2str(t->right) + ")" : "");
	}
};


int main()
{
	Test1();
	system("pause");
	return 0;
}



