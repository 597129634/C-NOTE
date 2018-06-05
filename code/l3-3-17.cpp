#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int main(void)
{
	//freopen("l3.17.txt", "r", stdin);
	string word;
	vector<string> sWord;
	while (getline(cin, word)) //一次读一行 
	{
		sWord.push_back(word);
	}

	for (auto &i : sWord)  //注意是引用 
	{
		for (int j = 0; j < i.size(); j++)
		{
			if (islower(i[j]))  //如果是小写字母，为真 在头文件 cctype 下 
				i[j] = i[j] - 32;  //对应小写字母的 ASCII - 32 得到大写字母 
		}
	}

	for (auto &i : sWord)
	{
		cout << i << endl;
	}

	return 0;
}

/*
输入
hi nice to meet you
You are my friend
AAAAxxxx
*/

/*
输出
HI NICE TO MEET YOU
YOU ARE MY FRIEND
AAAAXXXX
*/