#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s("hello world");
	cout << s << endl;

	for (char &c : s)
		c = 'x';
	cout << s << endl;

	return 0;
}