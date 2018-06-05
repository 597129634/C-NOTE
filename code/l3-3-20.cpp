#include<iostream>
#include<vector>
using namespace std;

vector<int>num;

void sum1();  //输出相邻和
void sum2();  //输出首尾加和，奇数单独输出中间值

int main(void)
{
	//freopen("l3.20.txt", "r", stdin);
	int integer;
	while (cin >> integer)
		num.push_back(integer);

	cout << "sum1 output" << endl;
	sum1();
	cout << endl;
	cout << "sum2 output" << endl;
	sum2();
	cout << endl;

	return 0;
}

void sum1()
{
	/*
	*for (auto i : num) //每个 i 即 为一个 num 中的一个元素--问题：如何取到当前值的下一个？
	*{
	*	cout << i << " ";
	*}
	*/

	for (int i = 0; i<num.size() - 1; i++)
		cout << num[i] + num[i + 1] << " ";

}

void sum2()
{
	
	for (int p = 0, q = num.size() - 1; p < num.size() / 2; p++, q--)
	{
		cout << num[p] + num[q] << " ";
	}

	if (num.size() % 2 != 0)   //检查是否是奇数长度
		cout << num[num.size() / 2];

	
}

/*
输入
2 4 5 1 2 3 8 8
*/

/*
输出
sum1
6 9 6 3 5 11 16
sum2
10 12 8 3
*/


/*
输入
1 3 6 9 2 0 3
*/

/*
输出
sum1
4 9 15 11 2 3
sum2
4 3 8 9
*/