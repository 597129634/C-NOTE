#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cout << s[0] << endl;
	//预期为不合法 不要对空串做s[0]
	//实际可以运行，无任何输出结果

	return 0;
}