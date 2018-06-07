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
标志库允许把字面值和字符串字面值转换成string对象，所以在需要string对象的地方就可以使用这两种字面值替代
string s1 = "hello", s2 = "world";
string s3 = s1 + ", " + s2 + '\n';
当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个 + 两侧对象至少有一个string
string s4 = s1 + ","; //正确:把一个string对象和一个字面值相加
string s5 = "hello" + ","; //错误：两个运算对象都不是string
//正确：每个加法运算符都有一个运算对象是string
string s6 = s1 + "," + "world";
string s7 = "hello" + "," + s2; //错误：不能把字面值直接相加


3.2.3 处理string对象中的字符
cctype 头文件中的函数
isalnum(c) //当 c 是字母或数字时为真
isalpha(c) //当 c 是字母时为真
iscntrl(c) //当 c 是控制字符时为真
isdigit(c) //当 c 是数字时为真
isgraph(c) //当 c 不是空格但可以打印时为真
islower(c) //当 c 是小写字母时为真
isprint(c) //当 c 是可打印字符时为真（即 c 是空格或 c 具有可视形式）
ispunct(c) //当 c 是标点符号时为真（即 c 不是控制字符，数字，字母，可打印空白中的一种）
isspace(c) //当 c 是空白时为真（即 c 是空格，横向制表符，纵向制表符，回车符，换行符，进纸符的一种）
isupper(c) //当 c 是大写字母时为真
isxdigit(c) //当 c 是十六进制数字时为真
tolower(c) //如果 c 是大写字母，输出对应的小写字母，否则原样输出 c 
toupper(c) //如果 c 是小写字母，输出对应大写字母，否则原样输出 c 
如何处理每个字符？
----使用基于范围的 for 语句
语法形式如下
for (declaration : expression)
statement
其中 expression 部分是一个对象，用于表示一个序列
declaration 部分负责定义一个变量，该变量将被用于访问序列中的基础元素
每次迭代，declaration 部分的变量会被初始化为 expression 部分的下一个元素值
例如使用for语句把string对象中的每一个字符每行输出一个出来
string str("some string");
//每行输出 str 中的一个字符
for(auto c : str) //对于str中的每个字符
    cout << c << endl; //输出当前字符，后面紧跟一个换行符
for循环把变量c和 str 联系起来，其中定义循环控制变量的方式与定义任意一个普通变量是一样的
上例中通过使用 auto 关键字，让编译器来决定变量 c 的类型，这里 c 的类型是 char
例：使用范围for语句和ispunct来统计string对象中标点符号的个数
string s("Hello,world!!!");
//punct_cnt 的类型和 s.size() 的返回类型一样
decltype(s.size()) punct_cnt = 0;
for (auto c : s)
if (ispunct(c))
    ++punct_cnt;
cout << punct_cnt << " punctuation characters in " << s << endl;
//输出 3 punctuation characters in Hello world!!!

使用范围for语句改变字符串中的字符
如果想要改变string对象中字符的值，必须把循环变量定义成引用类型
例：假设把字符串改成大写字母的形式（使用标准库函数 toupper ）
toupper 函数接受一个字符，然后输出对应的大写形式
string s("Hello world!!!");
//转换成大写形式
for (auto &c : s) //对于 s 中的每个字符（主意 c 是引用）
    c = toupper(c); //c 是一个引用，赋值语句将改变 s 中的值
cout << s << endl;
//输出 HELLO WORLD!!!

只处理一部分字符？
要想访问string对象中的单个字符有两种方式
一 使用下标
二 使用迭代器
下标运算符([]) 接收的输入参数是 string::size_type 类型的值，该参数表示要访问的字符的位置；返回值是该位置上字符的引用
string 对象的下标从 0 计起。如果string对象 s 至少包含两个字符，则 s[0]是第一个字符, s[1]是第二个字符....s[s.size - 1]是最后一个
NOTE string 对象的下标必须大于等于 0 小于 s.size(), 超过此范围会引发不可预知的结果
NOTE 不能用下标访问空 string
//使用下标运算符输出 string 对象中的第一个字符
if (!s.empty())
    cout << s[0] << endl;
在访问 string 对象之前，先检查其是否为空
只要字符串不是常量，就能为下标运算符返回的字符赋新值
//将字符串的首字符改成大写形式
string s("some string");
if (!s.empty()) //确保 s[0] 有字符
    s[0] = toupper(s[0]);
//输出 Some string

使用下标进行迭代
//把s的第一个词改成大写形式
for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    s[index] = toupper(a[index]);
//输出 SOME string
//上面循环使用index作为 s 的下标，index 类型由 decltype 决定
//&& 逻辑运算符 且

使用下标执行随机访问
例 把 0 - 15 之间的十进制数字转换成对应的十六进制数
//只需初始化一个字符串令其存放十六个十六进制"数字"
const string hexdigits = "0123456789ABCDEF"; //可能的十六进制数字
cout << "Enter a series of numbers between 0 and 15"
     << " separated by space.Hit ENTER when finished: " << endl;
string result;
string::size_type n;
while (cin >> n)
    if (n < hexgigits.size())
	    result += hexdigits[n];
cout << "Your hex number is : " << result << endl;
//输入 12 0 5 15 8 15
//输出 Your hex number is ： C05F8F

NOTE 关于3.2.3节练习3.10使用到了 erase 函数--删除字符
//erase 的原型
//string erase(int start, int len); 
//start为要删除字符的起始位置（从0数起），len为要删除字符的个数。


3.3 标准库类型 vector
vector 表示对象的集合，其中所有对象的类型都相同
vector可以作为不定长数组来使用
vector可以容纳其他对象，故又常被称为 "容器"
C++语言有类模板，vector就是一个类模板
使用 vector 包含头文件 #include<vector>
模板本身并非是类或函数，可以将其看出是编译器生成类或函数的一份说明
(有关模板的使用在acm文件夹下的NOTE2 中有简单提到如何使用)
以vector为例，提供的额外信息是vector内所存放对象的类型
vector<int> ivec; //ivec 保存 int 类型的对象
vector<Sales_item> Sales_vec; //Sales_vec 保存 Sales_item 类型的对象
NOTE vector 是模板，由vector生成的类型必须包含vector中元素的类型，由尖括号括起来
NOTE vector声明后，相当于一个不定长数组
NOTE vector 不能包含引用--因为引用不是对象

3.3.1定义和初始化 vector 对象
初始化 vector 对象的方法
vector<T> v1; //v1 是一个空 vector，潜在元素为 T 类型，执行默认初始化
vector<T> v2(v1); //用 v1 初始化 v2 ，注意两个vector对象的元素必须相同
vector<T> v2 = v1; //同上
vector<T> v3(n, val); //用 n 个 val 初始化 v3
vector<T> v4(n); //v4 包含n个重复执行了值初始化的对象
vector<T> v5{ a,b,c... }; //包含了初始值个数的元素，每个元素被赋予相应的初始值
vector<T> v5 = { a,b,c... }; //同上

列表初始化 vector 对象
vector<string>articles = { "a","an","xxx" };
//使用花括号来初始化
上面 articles 包含三个 string 对象
//注意，使用这种提供初始元素值得列表，只能使用花括号
vector<string>articles = ("a", "an", "xxx"); //error

创建指定数量的元素
vector<int>ivec(10, -1);//10 个 int 类型的元素，每个都被初始化为 -1

值初始化
一般，可以只提供vector对象容纳的元素数量而不用略去初始值，此时库会创建一个值初始化的元素初值
并赋给容器中的所有元素，这个值由vector对象中的元素类型决定
eg：
vector<int>ivec(10);//10 个元素，每个值都是 0
vector<string>svec(10);//10个元素，每个都是空串
NOTE 只提供元素数量，不设定初始值，只能用直接初始化，如下error
vector<int>vec = 10; //error

如何确定初始化时的数是列表初始值还是元素数量？
vector<int>v1(10); //10个元素，每个都是 0
vector<int>v2{ 10 }; //一个元素，值为 10
vector<int>v3(10, 1); //10个元素，每个都是 1
vector<int>v4{ 10,1 }; //两个元素，值为 10，1
NOTE 关键是看是花括号还是圆括号
NOTE 如果使用花括号，但是提供的值又不是列表初始化，需要借助特殊类型的vector对象，eg
vector<string>v5("h1"); //error,不能使用字符串字面值构建vector对象
vector<string>v6{ "hi" }; //列表初始化
vector<string>v7{ 10 }; //v7 有 10 个默认初始化元素，
vector<string>v8{ 10,"hi" }; //v8 有 10 和元素，值均为 hi

3.3.2 向 vector 对象中添加元素
较好的方法是创建一个空 vector ，然后向里面添加对象
该操作使用到了 vector 的成员函数 push_back
push_back 负责把一个值当成 vector 对象的尾元素（即把一个值存到vector对象的尾端） 如下
vector<int> v2;//空 vector 对象
for (int i = 0; i != 100; ++i)
    v2.push_back(i); //依次把整数值放到 v2 尾端
//循环结束后 v2 有 100 个元素，值从 0--99
例2 直到运行时才能知道 vector 对象中元素的确切个数
//从标准输入中读取单词，将其作为 vector 对象的元素储存
string word;
vector<string>text; //空 vector 对象
while (cin >> word)
{
	text.push_back(word); //把 word 添加到 text后面
}
NOTE 如果循环体内部包含有向vector对象添加元素的语句，则不能使用范围for循环
//范围for循环语句体内不应该改变其所遍历的大小
输出 vector 对象可以借助下标和迭代器

3.3.3 其他 vector 操作
v.empty()  //如果 v 中不含任何元素，返回真，否则返回假
v.size()   //返回 v 中元素的个数
v.push_back(t) //向 v 的尾端添加一个值为 t 的元素
v[n]  //返回 v 中 第 n 个位置上元素的引用
v1 = v2 //v2 替换 v1 中元素
v1 = { a,b,c... } //用列表中的元素拷贝替换 v1 中的元素
v1 == v2  //v1 v2 相等当且仅当他们元素数量相同且对应位置元素值都相同
v1 != v2
<, <= , >, >=  //按字典顺序比较大小
访问 vector 对象中的元素类似于访问 string 对象中的字符
通过元素在 vector 对象中的位置来访问，如下
//使用 范围for 处理 vector 对象中的所有元素
vector<int> v{ 1,2,3,4,5,6,7,8,9 };
for (auto &i : v)  //对 v 中的每个元素（注意 i 是一个引用）
	i *= i;  

for (auto i : v)   
    cout << i << ", ";

cout << endl;
NOTE 对于 v.size() 返回值是一个 size_type 类型的值
NOTE 要使用 size_type 首先需要指定它是由哪种类型定义的，如下
vector<int>::size_type; //right
vector::size_type; //error

计算vector内对象的索引
此处的操作类似数组
//以 10 分为一个分数段统计成绩的数量 0-9, ..... ,100
vector<unsigned>scores(10, 0); //将 11 个分数段全部置 0
unsigned grade;
while (cin >> grade)
{
	if (grade <= 100)  //只处理有效成绩
		++scores[grade / 10]; //等价于 auto ind = grade/10;  +  scores[ind] = scores[ind] + 1;
}

不能用下标形式添加元素
vector<int>ivec; //空 vector 对象
for (decltype(ivec.size())ix = 0; ix != 10; ++ix)
    ivec[ix] = ix;  //严重错误，ivec 不包含任何元素
正确的方法是使用 push_back()
for (decltype(ivec.size())ix = 0; ix != 10; ++ix)
    ivec.push_back(ix);
//vector 对象（及string）的下标运算符只能用于访问已经存在的元素，不能用于添加元素
//确保合法下标的一种有效手段----使用范围for语句

3.4 迭代器简介
在前面有提到，访问vector对象除了使用下标，还可以使用迭代器
事实上，对与C++定义的容器，只有极少数可以使用下标访问，但是他们都可以使用迭代器
类似于指针类型，迭代器也提供了对对象的间接访问

3.4.1 使用迭代器
获取迭代器不是使用取地址符，有迭代器的类型同时拥有返回迭代器的成员
eg：这些类型都拥有名为 begin 和 end 成员，其中 begin 返回指向的第一个元素的迭代器，如下
//由编译器决定 b和e 的类型
//b 表示 v 的第一个元素，e 表示 v 尾元素的下一个位置
auto b = v.begin(), e = v.end(); //b 和 e 的类型相同
end 成员则负责返回指向容器（或string对象）尾元素的下一个位置的迭代器
即，该迭代器指示的是容器的一个本不存在的"尾后"元素
esp 如果容器为空，begin 和 end 返回的是同一个迭代器（都是尾后迭代器）
NOTE 一般是不清楚迭代器的具体类型

迭代器运算符
*iter  //返回迭代器iter所指元素的引用
iter->mem //解引用iter并获取该元素名为mem的成员，等价于 (*iter).mem
++iter //令 iter 指示容器的下一个元素
--iter //令 iter 指示容器的上一个元素
iter1 == iter2
iter1 != iter2
//判断两个迭代器是否相等（不相等），如果指示的是同一个元素或者他们是同一个容器的尾后迭代器则相等，反之不相等
NOTE 类似于指针，能通过解引用迭代器来获取它指示的元素
例 把 string 对象的第一个字符改成大写形式
string s("some");
if (s.begin() != s.end()) //确保 s 非空
{
	auto it = s.begin(); //it表示 s 的第一个字符
	*it = toupper(*it); //将当前字符改成大写形式
}
通过检测 begin 和 end 返回结果是否一致就能检测 s 是否为空
如果返回值一样，s 为空，否则不为空

将迭代器从一个元素移到另一个元素
迭代器使用++来从一个元素移动到另一个元素
从逻辑上来说，迭代器的递增和整数的递增类似，迭代器通过 ++ 向前移动一个位置
NOTE end 返回的迭代器并不实际指示某个元素，所以不能对其进行递增或解引用的操作
比较前面的一个程序
//依次处理 s 的字符直至处理完或者遇到空白
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it);  //将当前字符改成大写形式
//利用上述代码可以把 s 中的第一个单词改成 大写形式
上述代码首先用 s.begin() 来初始化 it ，然后 it++ 到末尾或遇到空白为止
//isspace() 检查是否遇到空白

迭代器类型
一般不用确切知道迭代器类型
实际上，拥有迭代器的标准库类型使用 iterator 和 const_iterator 来表示迭代器类型
vector<int>::iterator it; //it 能读写vector<int>的元素
string::iterator it2;  //it2 能读写string对象中的字符
vector<int>::const_iterator it3; //it3只能读元素，不能写元素
string::const_iterator it4; //it4只能读字符，不能写字符
const_iterator 和常量指针差不多，只能读，不能写
iterator 可读可写
如果 vector 对象或 string 对象是一个常量，只能使用 const_iterator
如果 vector 对象或 string 对象不是常量，两者都能使用
NOTE 对迭代器的理解
迭代器可能指迭代器本身，也可能是指容器定义的迭代器类型，还可能指某个迭代器对象

begin 和 end 运算符
begin 和 end 返回的具体类型由对象是否是常量决定
如果对象是常量，begin 和 end 返回 const_iterator, 否则返回 iterator
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); //it1 的类型是 vector<int>::iterator
auto it2 = cv.begin(); //it2 的类型是 vector<int>::const_iterator
为了便于专门得到 const_iterator 类型的返回值，C++11 引入了两个新函数：cbegin 和 cend
（一般对象只需读不需写最好使用常量类型, 如 const_iterator)
auto it3 = v.cbegin(); //it3 的类型是 vector<int>::const_iterator
类似于begin 和 end ，上面两个新函数也返回容器的第一个元素或尾元素
不同的是无论是 vector 对象还是 string 对象本身是否是常量，返回的都是 const_iterator

结合解引用和成员访问操作
解引用迭代器可获得迭代器所指的对象，如果该对象的类型恰好是类，就可能进一步访问它的成员
如：由字符串组成的 vector 对象，要想检查是否为空，令 it 是该 vector 对象的迭代器，
只需检查 it 所指字符串是否为空就可，如下
(*it).empty();
注意(*it).empty 中的圆括号必不可少
NOTE it->mem 和(*it).mem 的意思一样
如：用一个 text 的字符串向量存放文本文件中的数据，其中的元素是一句话或一个用于表示段落分隔得空字符串。
如果要输出text中第一段的内容，可以利用迭代器写一个循环遍历text，知道遇到空字符串的元素为止，如下
//依次输出text的每一行直到遇到第一个空白行为止
for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
    cout << *it << endl;
auto it = text.cbegin() //令 it 指向 text 的第一个元素
it != text.cend() //未到末尾之前，循环
NOTE 只需读，使用的是 cbegin 和 cend

某些 vector 对象的操作会使迭代器失效
1 不能在范围for循环中向 vector 对象添加元素
2 任何一种可能改变 vector 对象容量的操作，比如push_back，都会使vector对象的迭代器失效



