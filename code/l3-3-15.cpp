#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void)
{
	//freopen("l3.15.txt", "r", stdin);
	string word;
	vector<string> s;
	while (cin >> word)
	{
		s.push_back(word);  //把 word 输入到 s 末尾
	}

	//cout << array << endl;

	cout << s.size() << endl; //输出的大小为 s 中 vector 对象的个数

	for (string::size_type i = 0; i< s.size(); i++)
		cout << s[i] << endl;

	return 0;
}

/*
输入
xxxxxxxxxx
xxxx
eeeeee
qqqqqqqqq
aaaaaaaaaaaa
fffff
gggggggggggggggg
hhhhh
bbbbbbb
ccc
xxx
debug
*/

/*
输出
12  //vector 对象个数
xxxxxxxxxx
xxxx
eeeeee
qqqqqqqqq
aaaaaaaaaaaa
fffff
gggggggggggggggg
hhhhh
bbbbbbb
ccc
xxx
debug
*/