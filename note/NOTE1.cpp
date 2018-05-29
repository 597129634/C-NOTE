前言 
C++ 可看作 3 部分组成
低级语言 大部分继承 c 语言
现代高级语言特性 允许自己定义类型及组织大规模程序和系统
标准库，利用高级特性来提供有用的数据结构和算法
 
1.1
编写一个简单的 C++ 程序
书店保存所有销售记录 每条记录包含 3 个数据项（ISBN号 出售册数 单价）
需求{ 定义变量
      输入输出
	  用数据结构保存数据
	  检测两条记录是否有相同的 ISBN
	  包含一个循环来处理每条记录
	}

每个程序都必须包含一个 main() 函数
int main()
{
	return 0;  //返回 0 
}

一个函数定义包含四部分 
{
    返回类型
	函数名
	形参列表（允许为空） 
	函数体 
}
上述 main 函数形参列表为空 其返回值必须是 int 型
NOTE ：在大多数系统中 main 返回值通常用来指示状态，返回值为 0 表示成功  非 0 值由系统定义，通常用来指出错误类型
NOTE ：类型不仅包含数据元素，还有定义在上面的运算
       数据保存在变量中，每个变量都有自己的类型，包含（int float 等）

从命令行运行编译器
假定 main 程序保存在文件 prog1.cc 中 可使用以下命令来编译
$ CC prog1.cc
$ 是系统提示符   CC 是编译器程序的名字   生成可执行文件，windows系统将其命名为 prog1.exe 
在windows系统中运行可执行文件，需要提供可执行文件的文件名，可忽略其拓展名 .exe  如 $ prog1
在一些系统中 即使文件就在当前目录或文件夹中 也需显式指出文件的位置   如 $ .\prog1   "." 后跟一个反斜线指出该文件在当前目录中
在 UNIX 系统中运行可执行文件，需要使用全文件名，包含拓展名: $ a.out 
要指定文件位置，需要用一个 . 后跟一个斜线来指出可执行文件位于当前目录中  $ ./a.out 
访问 main 返回值的方法依赖于系统 UNIX 和 Windows 中 执行完一个程序后都可以通过 echo 命令获得返回值 
UNIX 系统:  $ echo $ ?
Windows 系统:  $ echo %ERRORLEVEL%

1.2 初识输入输出
iostream 库 表示输入输出流     istream（标准输入） ostream（标准输出） 
标准输入输出对象 
{
	标准库定义了 4 个IO对象
	cin 标准输入
	cout 标准输出
	cerr 输出警告和错误信息
	clog 输出程序运行时的一般性信息
} 

一个使用 IO 库的程序
#include<iostream>
int main(void)
{
	std::cout << "Enter two numbers:" << std::end1;
	int v1 = 0,v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 <<" and " << v2 << " is " << v1 + v2 << std::end1;
	return 0;
} 
程序第一行 #include<iostream> 告诉编译器要使用 iostream 库 <> 指出头文件
向流写入数据 
{
    main 函数体第一句执行一个表达式 C++中 一个表达式产生一个结果
	<< 输出运算符 ：接受两个运算对象 左侧必须是 ostream 对象  右侧对象是要打印的值 
    << 将给定值写到给定的 ostream 对象中 即 输出运算符的计算结果为左侧运算对象
	esp 连用 << 可以连接输出请求
	endl ： 操纵符  写入 endl 的效果是结束当前行，并将与设备关联的缓冲区中内容刷到设备中  （endl 还有换行的作用） 
	（缓冲刷新操作可以保证到目前为止程序所产生的所有输出都进入输出流，而非停在缓冲区）
}

使用标准库的名字
{
    std:: 指出名字 cout  endl 是定义在 std 的命名空间中（标准库定义的所有名字都在命名空间里）
	::  ：作用域运算符  显示的指出要使用定义在 命名空间 std 中的名字
	有时 若变量少的话，可以使用 using namespace std  省去 std::的使用; 
}

从流读取数据
{
    定义变量 v1 v2并初始化（即创建变量的同时为其赋值）
	>> 输入运算符  左侧为 istream 对象 右侧为运算对象
	std:: cin >> v1 >> v2; 从 istream 读入数据存入右侧对象 v1
	该句等价于 ( std::cin >> v1 )>> v2
	即是读入两个值 ，第一个存入 v1 第二个存入 v2
}
 
NOTE 
{
	std:: cout << "The sum of" << v1 << std::endl;
	std::cout << " and " << v2 << std::endl;
	std:: cout << " is " << v1 + v2 << std::endl;
	//上述输出语句被打印成了 3 行 
}

注释简介
注释对/* */不能嵌套 但是单行注释可以忽略嵌套注释中的内容
嵌套注释报错    [Error] expected primary-expression before '/' token
NOTE 在调试期间 选择注释语句时 最好使用单行注释


1.4 控制流
可以使用控制流语句来写出执行复杂执行路径的程序
1 while 语句
{
    while(判断条件) //条件为假时跳出循环 
	{
		//注意要有更新判断条件的语句，否则会进入死循环 
	}
	//实例
	#include<iostream>
    using namespace std;
    int main(void)
    {
	    int sum = 0,val = 1;
	    while( val <= 10)
	    {
		    sum += val;
		    val++;  //判断条件更新语句 
	    } 
	        cout << "Sum of 1 to 10 inclusive is " << sum << endl;
	        return 0;
    }
	 
}

NOTE : cout << val << ' ' ;     //注意在输出后加空格而不换行的形式 val 后跟 << ' ' 而非  val' '
       cout << endl; //换行

2 for语句
{
	#include<iostream>
    using namespace std;
    int main(void) 
    {
	    int sum = 0;
	    for(int val = 1; val <= 10 ; val++)
	        sum += val;
	
	    cout << "sum of 1 to 10 inclusive is " << sum << endl;
	    return 0;
    }
	以上代码完成与 while 语句相同的作用 
} 

1.4.3 读取数量不定的输入数据
{
	#include<iostream>
    using namespace std;
    int main(void)
    {
	    freopen("r4.txt","r",stdin); 
	    int sum = 0;
	    int val = 0;
	    //读取所有输入知道文件尾
	    //手动输入文件尾 Ctrl + z 
	    while(cin >> val )
	        sum += val;
	    cout << "sum is " << sum << endl;
	    return 0;
    }
    解说
	while 的循环条件的求职是执行表达式 cin >> val 即实际检测的是 cin
	当使用一个 istream 对象做条件时，其效果是检测流的状态，如果流有效（未遇到错误，如输入非整数）
	或未遇到文件结束符时 结果均为真，否则为假 
} 

3 if 语句
{
	//只能统计连续出现的同一个数的次数 
    #include<iostream>
    using namespace std;
    int main(void)
    {
	    int currVal = 0, val = 0;
	    // currVal 是正在统计的数 新的输入存入 val 
	    //读取第一个数 确保有数据可处理 
	    if( cin >> currVal)
	    {
		    int cnt = 1;  //保存当前处理值的个数
		    while(cin >> val)
		    {
			    if(val == currVal)
			        ++cnt;      
			    else
			    {
				    cout << currVal << " occurs " << cnt << " times "<< endl;
				    currVal = val;  //记住新值 
				    cnt = 1;  //重置计数器 
			    }
		    }
		    cout << currVal << " occurs " << cnt << " times " << endl;  
	    } 
	 
	    return 0;
    }
	 
} 
 
1.5 类简介
C++ 中我们通过定义一个类来定义自己的数据结构
一个类定义了一个类型以及相关的一组操作 
为了使用类，需要了解 3 件事
{
    类名是什么
	在哪里定义
	支持什么操作
}
为了使用标准库设施，必须包含相关的头文件，同时也需要使用头文件来访问自己应用程序所定义的类
习惯上，头文件根据其中定义的类的名字来命名。通常使用 .h 作为头文件的后缀
标准库的头文件通常不带后缀

1.5.1 Sales_item 类
Sales_item 类的作用是表示一本书的总销售额，售出册数和平均售价
每个类都定义了一个新类型，其类型名就是类名。Sales_item 类定义了一个名为 Sales_item 的类型，同时，可以定义类类型的变量 如下
Sales_item item;
上述语句是名 item 为一个 Sales_item 类型的对象
此外还可以有如下操作
{
	调用一个名为 isbn 的函数从一个 Salse_item 中提取书号
	用 >>  << 读写 Sales_item 对象
	用 = 将一个 Sales_item 对象的值赋给另一个 Sales_item 对象
	用 + 将两个 Sales_item 对象相加，两个对象必须表示同一本书（加法结果是一个新的Sales_item 对象
	    其 ISBN 与两个运算对象相同而销售总额和售出册数是两个对象的和）
	使用 += 将一个 Sales_item 加到另一个对象上 
}

读写Sales_item
{
	
} 
