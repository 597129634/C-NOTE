#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int main(void)
{
	freopen("l3.21.txt", "r", stdin);
	vector<string>s;

	string temps;
	while (getline(cin, temps))
	{
		s.push_back(temps);
	}

	for (int i = 0; i<s[0].size(); i++)
		s[0][i] = s[0][i] - 32;


	for (auto it = s.cbegin(); it != s.cend(); it++)
		cout << *it << endl;

	return 0;
}