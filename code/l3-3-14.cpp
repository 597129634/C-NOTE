#include<iostream>
//#include<string>
#include<vector> //使用 vector 需要包含的头文件
using namespace std;

int main(void)
{
	//freopen("l3.14.txt", "r", stdin);
	int integer;
	vector<int> array;
	while (cin >> integer)
	{
		array.push_back(integer);
	}

	//cout << array << endl;  //不能直接输出vector对象

	cout << array.size() << endl; //计算出 array 的大小

	//借助下标输出，后面会介绍借助迭代器输出
	for (int i = 0; i< array.size(); i++)
		cout << array[i] << endl;

	return 0;
}