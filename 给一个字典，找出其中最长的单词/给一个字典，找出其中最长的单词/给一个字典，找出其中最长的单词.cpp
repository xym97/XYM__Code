//样例
//在词典
//{
//	“dog”,
//	“google”,
//	“facebook”,
//	“internationalization”,
//	“blabla”
//}
//中, 最长的单词集合为[“internationalization”]
//在词典
//{
//	“like”,
//	“love”,
//	“hate”,
//	“yes”
//}
//中，最长的单词集合为[“like”, “love”, “hate”]

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

//class Solution{
	vector<string> FindMaxWords(vector<string>& dic)
	{
		vector<string> v;
		string max;
		if (dic.empty()){
			return v;
		}
		for (size_t i = 0; i < dic.size(); ++i){
			if (dic[i].size() > max.size()){
				v.clear();
				max = dic[i];
				v.push_back(dic[i]);
			}
			else if(dic[i].size() == max.size()){
				v.push_back(dic[i]);
				max = dic[i];
			}
			else{
				continue;
			}
		}
		return v;
	}
//};


int main()
{
	vector<string> str = { "asdfg", "sssssss", "asd", "as", "enciuziastic" };
	//Solution a;
	vector<string> str1 = FindMaxWords(str);
	for (size_t i = 0; i < str1.size(); ++i){
		cout << str1[i].c_str() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}