#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(void)
{
	string s("xxx!!!xxx!!! xxxxx!! xxxxxxxxxx!!!!!!! x");
	cout << s << endl;

	//for (auto &c : s)
	//{
		/*  仅仅是做到了输出时不带标点符号输出，实际 s 中标点符号仍旧存在
		*if (ispunct(c))
		*	;
		*else
		*	cout << c;
		*/
	//}


	/*没办法处理连续的标点符号和末尾的标点符号 
	*if (!s.empty())
	*{
	*	for (string::size_type i = 0; i < s.size(); i++)
	*	{
	*		if (ispunct(s[i]))
	*		{
	*			for (string::size_type j = i; j < s.size()-1; j++)
	*			{
	*				s[j] = s[j + 1];
	*			}
	*		}
	*	}
	*}
	*/

	if (!s.empty())
	{
		for (string::size_type i = 0; i < s.size(); i++)
		{
			for (string::size_type j = 0; j<s.size(); j++)
			{
				if (ispunct(s[j]))
					s.erase(j, 1);  //erase() 定义在 string 类中
			}
		}
	}
	cout << s << endl;

	return 0;
}
//erase 的原型
//string erase(int start, int len); 
//start为要删除字符的起始位置（从0数起），len为要删除字符的个数。

//思考：对于删除 string 的一些特定字符的操作不借助库函数如何编写？