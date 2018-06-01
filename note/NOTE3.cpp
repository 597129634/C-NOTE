第三章 字符串，向量和数组
3.1 命名空间的 using 声明
使用 using 声明就无须专门的前缀（形如命名空间::）也能使用所需的名字，格式如下
using namespace ::name;
一旦使用了上述语句，就可以直接访问命名空间中的名字
#include<stdio.h>
//using 声明，使用名字 cin 时，从命名空间 std 中获取
using std::cin;
int main(void)
{
	int i;
	cin >> i;
	cout << i; //error 没有对应的using声明
	std::cout << i;
	return 0;
}
NOTE 每个名字都需要独立的 using 声明
每个using声明引入命名空间中的一个成员，如可以把用到的标准库的名字都以using声明表示
#include<iostream>
//使用 using 声明，可以直接使用标准库名字
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << "and" << v2 << "is" << v1 + v2 << endl;
	return 0;
}
NOTE 头文件不应包含 using 声明 防止发生名字冲突

3.2 标准库类型 string
标准库类型 string 表示可变长的字符序列，使用 string 必须包含 string 头文件
string 定义在命名空间 std 中 ，以下均包含下述代码
#include<string>
using std::string;

3.2.1 定义和初始化 string 对象
如和初始化类的对象由类本身决定, 一个类可以定义很多种初始化对象的方式
只不过这些方式之间必须有所区别：初始值数量不同，初始值类型不同...
常见string初始化方式
string s1; //默认初始化，s1 是一个空字符串
string s2 = s1; //s2 是 s1 的副本
string s3 = "hiya"; // s3 是该字符串字面值的副本
string s4(10, 'c'); //s4 的内容是 cccccccccc

string s1;   //默认初始化，s1 是一个空串 
string s2(s1); //s2 是 s1 的副本
string s2 = s1; //等价于 s2(s1) 
string s3("value"); //s3 是字面值 "value" 的副本，处理字面值最后的那个空字符
string s3 = "value"; //等价于上一条
string s4(n, 'c'); //初始化 s4 为连续 n 个 'c'组成的字符串

直接初始化和拷贝初始化
如果使用 = 初始化一个变量，实际执行的是拷贝初始化
编译器把等号右侧的初始值拷贝到新建对象中
不使用等号，执行直接初始化
当初始值只有一个时，上述两种方式均可。
向上面 s4 初始化要用到的值有多个，一般只能用直接初始化
string s5 = "hiya"; //拷贝初始化
string s6("hiya"); //直接初始化
string s7(10, 'c'); //直接初始化
对于用多个值进行初始化的情况，如果要有拷贝初始化，需要显示地创建一个临时对象用于拷贝
string s8 = string(10, 'c'); //拷贝初始化 
s8 的初始化等价于 string temp(10, 'c'); +string s8 = temp;

3.2.2 string 对象上的操作
os << s //将 s 写到输出流 os 中，返回 os
is >> s //从 is 中读取字符串赋给 s，字符串以空白分隔，返回 is
getline(is,s) //从 is 中读取一行赋给 s，返回 is
s.empty() //s 为空返回 true 否则返回 false
s.size() //返回 s 中字符的个数
s[n] //返回 s 中第 n 个字符的引用，位置 n 从 0 记起
s1+s2 //返回 s1 和 s2 连接的后果
s1 = s2 //用 s2 的副本替代 s1 中原来的字符
s1 == s2 //如果 s1 和 s2 所含字符完全一样，则相等（对大小写敏感）
s1 != s2 //判不等
<, <=, > ,>= //利用字符在字典中的顺序进行比较，且对字母的大小写敏感

读写 string 对象
使用 IO 操作符读写 string 对象
//下面代码需要 #include 语句和 using 声明
int main(void)
{
	string s; //定义空串
	cin >> s; //将 string 对象读入 s，遇到空白停止
	cout << s << endl;
	return 0;
}
执行读取操作时，string 对象会自动忽略开头的空白（空格，换行，制表）并
从第一个真正的字符开始读取，直到遇到下一处空白
//eg 输入 "hello world" 输出 "hello"
string 对象的此类操作也是返回运算符左侧的运算对象作其结果，因此，多个
输入或输出可以连写在一起
string s1, s2;
cin >> s1 >> s2;
cout << s1 << s2 << endl;
//eg 输入 "hello world" 输出 "helloworld"

读取未知数量的 string 对象
int main(void)
{
	string word;
	while (cin << word) //反复读取直到文件末尾/违法输入
		cout << word << endl;
	return 0;
}

使用 getline 读取一整行
使用 getline 可以得到字符串中输入时的空白符
getline 函数的参数是一个输入流和一个 string 对象
函数从给的输入流中读取内容，直到遇到换行符（换行符也被读入）
NOTE 如果输入的一开头就是换行符，getline 也会停止，得到一个空串
getline 会返回流参数，因此可以用 getline 的结果作为条件，如下（一次输出一整行）
int main(void)
{
	string line;
	//每次读取一整行，直达文件末尾
	while (getline(cin, line))
		cout << line << endl;
	return 0;
}
NOTE 虽然换行符被读取，但是并未存进字符串

string 的 empty 和 size 操作
empty() 函数根据 string 对象是否为空返回一个对应的布尔值
//改写上一个程序，只输出非空行
//每次读一整行，遇到空行直接跳过
while (getline(cin, line))
{
	if (!line.empty())  //使用点操作符指明是哪个对象要执行此操作
		cout << line << endl;
}

size() 函数返回 string 对象的长度
使用 size 函数输出只超过 80 个字符的行
string line;
//每次读一整行，输出超过 80 个字符的行
while (getline(cin, line))
{
	if (line.size() > 80)
		cout << line << endl;
	return 0;
}

string::size_type 类型
size 函数返回一个 string::size_type 类型的值
size_type 是一个无符号类型的值，且能存放任何 string 对象的大小
所有用于存放string类的size函数返回值的变量都应该是 string::size_type类型的
NOTE 允许编译器通过 auto / decltype 类推断变量类型
NOTE auto len = line.size(); //len 的类型是 string::size_type
NOTE 如果一个表达式中已经有了 size 函数就不要再使用 int，防止有符号数和无符号数混用带来的问题

比较 string 对象
相等（ == ）  不等 （ != ) 检验两个 string 对象是否相等
string 对象相等一维着长度相同，对应字符也相同
<, <= , >, >= 则是依靠字典顺序比较两个 string 对象的大小
1 如果两个 string 对象的长度不同，较短 string 对象的每个字符都与较长的对应位置上
字符相等，称较短的小于较长的
2 如果两个string对象在某些位置上不一致，则string 对象比较的结果是第一对相异字符的比较结果
eg
string str = "Hello";
string phrase = "Hello,World";
string slang = "Hiya";
//str 小于 phrase，slang 大于 str 和 phrase

为 string 对象赋值
允许一个string对象赋给另一个对象
string s1(10, 'c'), s2;
s1 = s2; //用 s2 的副本替换 s1 ，现在 s1，s2 都是空串

两个 string 对象相加
两个string对象相加实际是把左侧运算对象与右侧运算对象串接，得到一个新的string对象
新对象，原左侧在前，右侧在后
string s1 = "HELLO", s2 = "world\n";
string s3 = s1 + s2; //s3 为 "HELLOworld\n"
s1 += s2; //等价于 s1 = s1 + s2;

字面值和 string 对象相加
