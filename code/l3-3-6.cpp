#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s("hello world");
	cout << s << endl;
	//使用范围 for 语句 
	for (auto &c : s) // 注意 c 是引用 
		c = 'x';
	cout << s << endl;
	return 0;
}