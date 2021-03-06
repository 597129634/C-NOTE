﻿第二章 变量和基本类型
最基本特征
{
	整型 字符型等内置类型
	变量
	表达式和语句
	if  while等控制结构
	函数 
}

C++ 是一种静态数据类型语言 其类型检查发生在编译时


2.1 基本内置类型
2.11 算术类型
{
	整型 浮点型等 p30
	带符号类型和无符号类型 
 } 
2.1.2 类型转换
{
	把非 bool 类型的算术值赋给 bool 类型时 除 0 外均为真（1）
	把 bool 赋给非 bool 类型时 false 为 0  true 为 1
	把浮点数赋给整数类型时 仅保留小数点之前的部分
	把整数值给浮点类型 小数部分记为 0   若整型数所占空间超过浮点类型容量 精度可能损失
	赋给无符号类型一个超过其范围的值时 结果是初始值对无符号类型表示数值总数取模后的余数 
	
	注意：
	含有无符号类型的表达式
	无符号类型不能赋给负值，但是可能写代码时会发生类似的错误如下
	{
		unsigned u = 10;
		int i = -42;
		std::cout << u + i << std::endl; 
	}
	这段代码在计算 u + i 时 会将 i 代表的 -42 转化成无符号数，其结果等于这个负数加上无符号数的模
	esp 在使用无符号数的时候要特别注意其他类型的转换产生的错误（无符号数和有符号数最好不要混用) 
} 
2.1.3 字面值常量
一个形如 42 的值被称为 字面值常量 每个字面值常量都对应一种数据类型，其形式和值决定了它的数据类型
整型和浮点型字面值
{
	以 0 开头表示八进制数
	0x 或 0X 开头表示十六进制数
	如 20（十进制）== 024（八进制）== 0x14（十六进制）
	整型字面值具体数据类型由其值和符号决定，默认十进制带符号，八进制和十六进制可能带也可能不带
	十进制字面值类型为int ，long ，long long 中尺寸最小的（能容下的前提下）
	八和十六进制则是 int ， unsigned int ，long ， unsigned long ， long long ， unsigned long long 中最小的
	类型 short 没有对应字面值
	
	浮点字面值表现为一个小数或以科学记数法表示的指数 指数部分用 E 或 e 标识
	默认浮点型字面值为 double 
}
字符和字符串字面值
{
	由单引号括起来的一个字符称 char 型字面量 双引号括起来的则是字符串字面量
	'a' //字符字面量 
	"aaa" // 字符串字面量
	字符串字面量实际是字符数组 
} 
转义序列
{
	有两类字符不能直接使用
	{
		1 不可打印字符
		2 转义序列 转义序列均以反斜线作为开始
		具体包括 p36
		特别的 如果反斜线 \ 后面跟的八进制数字超过 3 个 只有前三个数字与 \ 构成转义序列 
	} 
} 
指定字面值的类型
{
	
 } 
 

2.2 变量
2.2.1 变量定义
定义的基本形式  ： 类型说明符  一个或多个变量名组成的列表，变量名以逗号分隔，最后以分号结束
int a1,a2,a2;
定义时可为变量初始化赋值
std::string book("0-201-78345-x");  // book 的定义用到了库类型 std::string string 也是在命名空间 std 中定义的
string 是一种表示可变长字符序列的数据类型
NOTE 初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值是把对象的当前值擦除，而以一个新值来替代
列表初始化
{
	C++ 中初始化有好几种形式，如下
	{
		int units_sold = 0;
		int units_sold = {0};
		int units_sold{0};
		int units_sold(0);
	}//以上 4 中均表示定义了一个 units_sold 的变量并初始化 0 
} 
默认初始化
{
	定义变量时没有指定初始值，则变量被默认初始化
	NOTE 定义与函数体内的内置类型的对象若没有初始化，则其值是未定义的
	NOTE 类的对象若没有显示的初始化，则其值有类确定 
}
2.2.2 变量声明与定义的关系
为了允许把程序拆分成多个逻辑部分来写，C++语言支持分离式编译机制 
该机制允许将程序分割为若干文件，每个文件可被独立编译
如何在程序分为多个文件后在文件间共享代码？ 
为了支持分离式编译，C++将声明与定义分开
声明使名字为程序所知
定义负责创建与名字关联的实体
变量声明规定了变量的类型和名字，此处与定义相同，除此之外，定义还申请储存空间，也可能为变量赋一个初值
如果想声明一个变量而非定义它，在变量名前添加 extern 且不要显示地初始化变量
{
	extern int i;   //声明 i 而非定义 
	int j;          //声明并定义 j 
	extern int i = 3   //定义 i 
} 
在函数体内，如果试图初始化一个由 extern 标记的变量，程序将报错
NOTE 变量仅能被定义一次，但可被声明多次 （C语言中 extern 就表面的是在此处引用变量 而该变量是定义在别处）
NOTE 静态类型
{
	C++ 是一种静态类型语言  在编译阶段检查类型（类型检查）
	要求 每个变量使用前必须声明其类型 
} 

2.2.3 标识符
C++ 的标识符由 字母，数字和下划线组成 且只能以字母或下划线开头
标识符同 C 一样对字母大小写敏感
命名规范
{
	变量一般小写 
	自定义类名一般以大写字母开头 Sales_item
	多个单词组成的标识符要有明显区分 
} 

2.2.4 名字作用域
作用域
{
	程序的一部分，C++大多数作用域以{}分割
	同一个名字在不同作用域中可能指向不同的实体。
	名字有效区域始于声明语句，以声明语句所在的作用域末端结束
	同时内层的声明会掩盖外层声明 
	典例
	#include<iostream>
	int main(void)
	{
		int sum = 0;
		for(int val = 1;val <= 10;val++)
		    sum += val;
		
		std::cout << "Sum of 1 to 10 inclusive is" << sum << std::endl;
	    
	    return 0;
	} 
	//该程序定义了 3 个名字 main sum val  同时使用命名空间 std（该空间提供 cout 和 cin 供程序使用) 
	
	全局作用域 ：所有花括号外定义 
	块作用域 ：某个花括号内定义，作用于该括号
	NOTE ：建议 第一次使用变量时再定义它  
	嵌套作用域：
	{
		内层作用域：被包含的作用域 
		外层作用域 ：包含别的作用域的作用域
		NOTE 作用域中一旦声明了某个名字，它嵌套的所有作用域都能访问该名字
		     同时允许在内存作用域中重新定义外层作用域已有的名字
			 （但是这么做内层作用域会掩盖外层作用域直到内层结束）//最好不要这么做 
		
		/*
		* #include<iostream>
		* int reused = 42;   //reused 拥有全局作用域 
		* int main()
		* {
		*      int unique = 0;   //unique拥有块作用域
		*	   //输出 #1 ：使用全局变量 reused ; 输出 42 0
		*	   std::cout << reused << " " << unique << std::endl ;
		*	   int reused = 0; // 新建局部变量 reused 覆盖全局变量 reused
		*	   //输出 #2 使用局部变量 reused 输出 42 0
		*	   std::cout << :: reused << " " << unique << std::endl;
		*	   return 0; 
		* }	  
		*/	
		NOTE 不同变量最好用不同的名字，不要用同一个名字代表多个变量    
	}
}

2.3 复合类型
复合类型是基于其他类型定义的数据类型
在前面提到 一条简单的声明语句由一个数据类型后紧跟一个变量名组成的列表
更通用描述 ：一条声明语句由一个基本数据类型和紧随其后的一个声明符列表组成
每个声明符命名了一个变量并指定该变量为与基本数据类型有关的某种类型

2.3.1 引用
C++ 11 新增引用 ：右值引用 
严格说 ：当我们使用术语“引用”指的是左值引用
引用 ：为对象起了另外一个名字
引用类型引用 ：另外一种类型
通过将声明符写成 &d 的形式来定义引用类型，其中 d 是声明的变量名
int ival = 1024;
int &refVal = ival;   //refVal 指向 ival （是 ival 的另一个名字） 
int &refVal2;         //报错：引用必须被初始化
一般在初始化变量时，初始值会被拷贝到新建的对象中，然后定义引用时，程序把引用和它的初始值绑定
而不是将初始值拷贝给引用。一旦初始化完成，引用将和它的初始值对象一直绑定在一起。
因为无法令引用重新绑定到另外一个对象，因此引用必须被初始化

引用即别名
NOTE ：引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字
定义一个引用之后，对其所进行的所有操作都是在与之绑定的对象上进行的 
refVal = 2; // 把 2 赋给 refVal 指向的对象 此处即是赋给了 ival 见前（int &refVal = ival）
int ii = refVal; //与 ii = ival 执行结果一样
为引用赋值，实际是把值赋给了与引用绑定的对象，获取引用的值，实际是获取了与引用绑定的对象的值。
以引用作初始值，实际是以与引用绑定的对象作初始值，如下
int &refVal3 = refVal; //refVal3 绑定到了与 refVal 绑定的对象上，即绑定到 ival 上
int i = refVal; // i 被初始化为 ival 的值
因为引用本身不是一个对象，所以不能定义引用的引用

引用的定义
允许在一条语句中定义多个引用，其中每个引用标识符都必须以 & 开头
int i = 1024, i2 = 2048; // i 和 i2 都是 int 
int &r = i,r2 = i2; //r 是一个引用 与 i 绑定  r2 是 int  
int i3 = 1024,&ri = i3; // i3 是 int  ri是一个引用，与 i3 绑定 
int &r3 = i3,&r4 = i2;  // r3 r4 都是引用
NOTE ：引用要与绑定的对象严格匹配
       引用只能绑定在对象上，而不能绑定在字面值或某个表达式上
	   int &refVal = 10;  //NOTE2 
	   double dval = 1.0;
	   int &refVal5 = dval;  //NOTE3
NOTE
{
	int i,&r1 = i;
	i = 5;
	r1 = 10;
	cout << i << " " << r1 << endl;
	// 该段代码输出 10 10 
}

2.3.2 指针
指针 ：指向另外一种类型的复合变量（与引用类似，实现对其他对象的间接访问）
不同于引用的是指针本身就是一个对象，可以赋值拷贝，无须在定义时赋初始值（若为初始化，指向一个不确定的值）
指针指向的是这个对象的地址（参考C）

定义
int *ip1,*ip2;  //变量名前加 *

获取对象地址
使用 & 取地址运算符
int ival = 42;
int *p = &ival; //p 存放变量 ival 的地址 
NOTE 指针的使用同样要与其指向的对象严格匹配

指针值（即地址）应处于下面 4 种之一 
1 指向一个对象
2 指向紧邻对象所占空间的下一个位置
3 空指针，指针没有指向任何对象
4 无效指针，即上述情况之外的其他值
NOTE 试图访问 2 3 4 种情况的指针，其结果是未定义的

利用指针访问对象
使用 * 解引用符
int ival = 2;
int *p = &ival;   //注意理解这里是把 ival 的地址赋给 指针 p 而非赋值给 *p 
cout << *p; // *p 解引用指针，*p 的值即为其指向的对象的值  p 是对象的地址 输出 42 
*p = 0; // 给 *p 赋值 即为给 *p 指向的对象赋值 
cout << *p << ival <<endl; //输出 0 0 
NOTE 解引用指针仅适用于那些指向了某个对象的有效指针
 
空指针(NULL)
NULL 不指向任何对象，在试图使用一个指针之前务必检查是否为 NULL
如 在单链表中往往要对 lastPtr->nextPtr = NULL 操作，而在执行此操作前加一个 if(lastPtr)
几个生成空指针的方法
int *p1 = NULL;
int *p2 = 0;
int *p3 = nullptr; 
NOTE  NULL 在头文件 cstdlib 中定义，值为 0
NOTE nullptr 是 C++11 新引入的一种方法 nullptr 为一种特殊类型的字面值，可以被转换成任意其他的指针类型
NOTE 把 int 变量直接赋给指针是错误的操作，即使是 0 也不行 指针指向的只能是地址 
     eg int zero = 0;
	    p1 = zero;  	    
NOTE 建议初始化所有指针 即 定义时初始化 nullptr

赋值和指针
指针和引用都是简介引用其他对象 但是有很大的不同，其中最重要的是
引用本身并非对象，一旦绑定就不能在绑定到其他对象上
指针本身是对象，可以重复使用
int i = 42;
int *p1 = nullptr; //p1 被初始化 
int *p2 = &i; // p2 被初始化 存放 i 的地址 
int *p3; // p3 没有被初始化 
p3 = p2; // p3 和 p2 指向同一个对象 i 
p2 = 0; // p2 重新被赋值空 不指向任何对象
NOTE 有时要弄清一条赋值语句是改变指针的值还是改变了指针所指向对象的值不太容易，
     最好的办法是记住赋值永远改变的是等号左侧的对象
	 pi = &ival; // pi 的值被改变，现在 pi 指向 ival
	 *pi = 0; // ival 的值被改变，指针 pi 并没改变 （*pi指向的对象发生改变）

其他指针操作
指针值为 0 条件取 false   任何非 0 指针对应的条件是 true 
int ival = 1024;
int *p1 = 0;        // p1 合法，一个空指针 
int *p2 = &ival;    // p2 合法 存放 ival 地址 
if(p1)              //条件取 false 
    //
if(p2)              //条件取 ture 
    // 
对于两个类型相同的合法指针，可以用相等操作符 （==） 或不相等操作符（!=）来比较
比较结果为 bool 
地址值相同，则它们相等，反之不相等
地址值相同（两个指针相等） 有三种可能
1 他们为空
2 指向同一个对象
3 指向用一个对象的下一个地址
需要注意的是，一个指针指向某对象，同时另一个指针指向另外对象的下一个地址
此时也有可能出现这两个指针值相等的情况，即指针相等 

void* 指针
void* 是一种特殊的指针类型,可用于存放任意对象的地址
一个 void* 指针存放着一个地址，但是对其中是什么类型的对象不了解
double obj = 3.14, *pd = &obj;  // void* 能存放任意类型对象的地址 
void *pv = & obj;  // obj 可以是任意类型的对象 
pv = pd;   // pv 可以存放任意类型的指针
void * 指针不能直接操作但是可以与其他指针比较，作为函数的输入输出或者赋给另一个 void *
以 void * 的视角来看，内层空间也仅是内层空间，没办法访问内存空间中所存对象


2.3.3 理解复合类型的声明
变量的定义 ： 基本数据类型 + 一组声明符
在同一条语句中，虽然基本数据类型只有一个，但是声明符的形式却可以不同
一条语句可以定义不同类型的变量
int i = 1024; *p = &i, &r = i;
// i 是一个 int 类型  p 是一个 int * 指针 ，r 是 int 型引用
NOTE 类型修饰符是声明符的一部分
定义多个变量
NOTE int* p1,p2;该声明并非定义了两个 int * 指针 只有 p1 是指针 p2 不是

指向指针的指针
指针是内层中的对象，具有自己的地址，可以把指针的地址在存放到另一个指针中（如链表）
通过 * 的个数可以区分指针的级别 ** 表示指向指针的指针
int ival = 1024;
int *pi = &ival;  //pi 指向一个 int  
int **ppi = &pi;  //ppi 指向 int *
见t1
解引用 int 型指针得到一个 int 型的数 解引用一个指向指针的指针得到一个指针
如得到 ppi 指向的数 pi == **ppi （值）

指向指针的引用
引用本身不是一个对象，不能定义指向引用的指针
指针是对象，存在对指针的引用
int i = 42;
int *p;  
it &r = p; // r 是一个对指针 p 的引用 
r = &i; //r 引用一个指针 给 r 赋值 &i 就是令 p 指向 i 
*r = 0; //解引用 r 得到 i ，将 i 值改为 0
NOTE 一条比较复杂的指针或引用的声明语句时，从右向左阅读有助于弄清它的真实含义

2.4 const 限定符
利用 const 可以防止程序不小心改变一个变量的值
const int bufSize = 512; // 输入缓冲区大小
把 bufSize 定义成一个常量，以后不可以更改 bufSize 的值
const 对象创建对象后不能再改变其值，所以 const 对象必须定义时初始化
const int i = 1024;
可以用另一个变量的值初始化 const 变量
int i = 42;
const int ci = i; //用变量 i 的值初始化 ci

默认状态下 const 对象仅在文件内有效
以编译时初始化的方式定义一个 const 对象时，编译器将在编译过程中把用到该变量的地方都替换成对应的值
如果程序包含多个文件，则每个用了 const 对象的文件都必须要能访问到它的初始值，因此需要在每个文件中都有对它的定义
出于上述原因，const对象默认被设定在仅在文件内有效
当多个文件中出现了同名的 const 变量时，相当于在不同文件中分别定义了独立的变量
当 const 变量的初始值不是一个常量表达式但又必须在文件中共享，可以在声明或定义的前面都添加 extern
// file1.cc 定义并初始化一个常量
extern const int bufSize = fcn();
// file1.h 头文件
extern const int bufSize; // 与 file1.cc 中定义的 bufSize 是同一个
file1.cc 定义并初始化 bufSize（存在初始值） bufSize 是常量 用 extern 加以限定以便被其他文件使用
file1.cc 头文件中声明做 extern 指明 bufSize 并非本文件独有，其定义将出现在别处
NOTE 想在多个文件之间共享 const 对象，必须用 extern

2.4.1 const 的引用
对const 的引用不能改变它的绑定对象
const int ci = 1024;
const int &r1 = ci; //正确 
r1 = 42; //错误 r1 是常量的引用 
int &r2 = ci;  //错误 试图让非常量引用指向一个常量对象

初始化和对 const 的引用
引用的类型必须与其所引用对象的类型一致（两个例外）
第一 初始化常量引用是允许用任意表达式做初始值，只要该表达式结果能转换成引用类型即可
第二 允许为一个常量引用绑定非常量对象，字面值，甚至是一个一般表达式
int i = 42;
const int &r1 = i; //允许将 const int & 绑定到一个普通 int 对象上 
const int &r2 = 42; // 正确 r1 是一个常量引用 
const int &r3 = r1 * 2; // 正确 r3 是一个常量引用 
int &r4 = r1 * 2; // 错误 r4 是一个普通的非常量引用

double dval = 3.14;
const int &ri = dval;
ri 引用了一个 int 型的数，对 ri 的操作应是整数运算，但 dval 却是一个双精度浮点数而非整数
编译器做了如下操作
const int temp = dval;
const int &ri = temp;
编译器临时生成一个变量让 ri 绑定
对 const 的引用可能并非一个 const 对象
const int &r2 = i; //r2 绑定 i 但不能通过 r2 改变 i 的值
但是可以通过其他途径改变 i 的值
int &r1 = i;
r1 = 0;
此时通过 r1 修改 i 为 0
见下
int i = 1;
const int &r1 = i;
printf("r1 = %d,i = %d\n",r1,i); //输出 1 1 
int &r2 = i;
r2 = 2;
printf("r1 = %d,r2 = %d,i = %d\n",r1,r2,i);  // 输出 2 2 2
//上面通过 r2 改变了 i 的值

2.4.2 指针和const
与引用一样，可以令指针指向常量或非常量。
指向常量的指针不能用于改变所指对象的值，要想存放常量对象的地址只能使用指向常量的指针
const double pi = 3.14; // pi 是个常量 
double *ptr = &pi; //错误 ：ptr 是一个普通指针 
const double *cptr = &pi; //正确 cptr 可以指向一个双精度常量 
*cptr = 42; //错误不能给 *cptr 赋值
指针的类型必须与其所指向对象的类型一致，两个例外
第一 允许令一个指向常量的指针指向一个非常量对象;
double dval = 3.14; // dval 是一个double类型的变量，可以改变值 
cptr = &dval; //正确：但是不能通过 cptr 改变 dval 的值 

 
const 指针
指针是对象而引用不是，因此想其他对象类型一样，允许把指针本身定为常量。
常量指针必须初始化，一旦初始化完成，则其值不能再改变
把 *放在const 关键字之前用以说明指针是一个常量，这样的书写形式隐含着一层含义
不变的是指针本身的值而非指向的那个值
int errNumb = 0;
int *const curErr = &errNymb; //curErr 将一直指向 errNumb 
const double pi = 3.1415;
const double *const pip = &pi; // pip 是一个指向常量对象的常量指针 
NOTE 要想弄清这些声明最好的办法是从右向左阅读
如 离curErr 最近的符号是 const 意味着 curErr 本身是一个常量对象，对象的类型又声明符的其余部分决定
声明符的下一个符号是 * 意思是 curErr 是一个常量指针
最后该声明的基本数据类型部分确定了常量指针指向一个 int 对象

指针本身是常量不意味着不能通过指针修改所指对象的值
这取决于所指对象的类型 如
*pip = 2.7 //错误 pip 是指向常量的指针 
if(*curErr) //如果curErr所指对象不为 0 
{
	errorHandler();
	*curErr = 0; //正确 把 curErr 所指对象重置 
}

2.4.4 顶层 const
指针本身是不是常量以及指针所指是不是常量是两个独立的问题
用名词顶层 const 表示指针本身是个常量
用名词底层 const 表示所指对象是个常量
更一般的说 顶层 const 可表示任意对象是常量，底层 const 则与指针和引用等复合基本类型有关
esp 指针既可是顶层const 又可是底层const
int i = 0;
int *const p1 = &i;  //不能改变 p1 的值  是顶层 const 
const int ci = 42;   //不能改变 ci 的值 是顶层 const 
const int *p2 = &ci; //允许改变 p2 的值 是底层 const 
const int *const p3 = p2; //靠右的 const 是顶层 const 靠左的是底层 const 
const int &r = ci; //用于声明引用的都是底层const 
具体实例  见 r2 
int i = 0;
int *const p1 = &i;
*p1 = 2;
printf("*p1 = %d  i = %d\n",*p1,i);  //可以编译 改变 i 的值 
//输出 2 2  
int p = 1;
p1 = &p; //报错  [Error] assignment of read-only variable 'p1' 
可见 顶层 const 可以改变指针指向的对象的值 但是指针本身的值（即地址，指向的对象）不能改变 
底层 const 可以改变指针本身的值（所指向的对象）但是当前指针指向对象的值不能改变 
当执行对象拷贝操作是 常量是顶层const还是底层const区别明显 其中顶层const不受什么影响
i = ci; //正确 拷贝 ci 的值 ci 是顶层const 对此操作无影响 
p2 = p3;  //正确 p2 和 p3 所指向对象类型相同 p3 顶层const 对象不受影响
int *p = p3;  //错误 p3 包含底层 const 的定义 而 p 没有 
p2 = p3;      //正确 p2 和 p3 都是底层 const 
p2 = &i;      // 正确 int* 能转换成 const int*  
int &r = ci;  //错误 普通的int &不能绑定到 int 常量上 
const int &r2 = i;  //正确 const int& 可以绑定到一个普通 int 上 
p3 既是顶层 const 也是底层 const 拷贝 p3 时可以不在乎它的一个顶层 const
但是必须清楚它指向的对象的是一个常量，因此不能用 p3 去初始化 p
因为 p 指向的是一个普通的整数另一方面 p3 的值可以赋给 p2 是因为这两个指针都是底层 const
尽管 p3 同时是一个常量指针仅这次赋值不会有什么影响

2.4.4 constexpr和常量表达式
常量表达式 指不会改变并且在编译过程就能得到计算结果的表达式
字面值属于常量表达式，用常量表达式初始化的const对象也是常量表达式。
一个对象是不是常量表达式由它的数据类型和初始值共同决定
例如
const int max_files = 20;   //max_files 是常量表达式
const int limit = max_files + 1; //limit 是常量表达式
int staff_size = 27; //staff_size 不是常量表达式
const int sz = get_size(); //sz 不是常量表达式
NOTE 尽管staff_size 的初始值是个字面值常量，但其数据类型是 int 故不是常量表达式
NOTE 尽管 sz 本身是常量，但其具体值直到运行时才能得到，也不是常量表达式

constexpr 变量
C++11 标准规定 允许将变量声明为 constexpr 类型以便由编译器来验证变量的值
是否是一个常量表达式
声明为 constexpr 的变量一定是一个常量，而且必须用常量表达式初始化
constexpr int mf = 20; //20 是常量表达式
constexpr int limit = mf + 1; //mf + 1 是常量表达式
constexpr int sz = size(); // 只有当 size 是一个 constexpr 函数时才正确
NOTE 一般，如果认为一个变量是常量表达式，就用 constexpr 来声明

字面值类型
NOTE 函数体内定义的变量一般并非存放在固定地址中， constexpr 指针不能指向这样的变量
NOTE 定义于所以函数体之外的对象其地址固定不变，能用来初始化 constexpr 指针
指针和 constexpr
在 constexpr 声明中如果定义了一个指针，限定符 constexpr 仅对指针有效，与指针所指对象无关
const int *p = nullptr;  //p 是一个指向整型常量的指针
constexpr int *q = nullptr; //q 是一个指向整数的常量指针
与其他常量指针类似, constexpr 指针既可以指向常量也可以指向一个非常量
constexpr int *np = nullptr;
int j = 0;
constexpr int i = 42;  // i 的类型是整型常量
//i j 必须定义在函数体之外
constexpr const int *p = &i; // p 是常量指针，指向整型常量 i
constexpr int *p1 = &j; //p1 是常量指针，指向整数 j

2.5 处理类型
2.5.1 类型别名
类型别名是一个名字，有两种定义方法
1 使用关键字 typedef
typedef double wages; //wages 是 double 的同义词
typedef wages base, *p; //base 是 double 的同义词，p 是 double * 的同义词
2 使用 别名声明
using SI = Sales_item; // SI 是 Sales_item 的同义词
这种使用关键字 using 作为别名声明的开始，其后紧跟别名和等号，作用是把等号左侧的名字规定成等号右侧类型的别名
类型别名和类型的名字等价，只要是类型的名字能出现的地方，就能使用类型别名
wages, hourly, weekly;//等价于 double ，hourly ， weekly
SI item; //等价于 Sales_item item

指针，常量和类型别名
typedef char *pstring; 
const pstring cstr = 0; //cstr 是指向 char 的常量指针
const pstring *ps; //ps 是指针，对象是指向 char 的常量指针
特别提示
const char *cstr = 0; //并不等同于 const pstring cstr = 0;
前一个基本数据类型是 const char, *是声明符的一部分即声明的是指向 const char 的指针
后一个基本数据类型是 const char *，声明的是指向 char 的常量指针

auto 类型说明符
auto 让编译器通过初始值来推算变量的类型。那么，auto 定义的变量必须有初始值
//由 vall 和 val2 相加的结果可以推断出 item 的类型
auto item = vall + val2; // item 初始化为 vall 和 val2 相加的结果
使用 auto 也能在一条语句中声明多个变量，但是这样变量的初始基本类型必须一样
auto i = 0, *p = &i; //正确：i 是整数，p 是整型指针
auto sz = 0, pi = 3.14; //错误：sz 和 pi 的类型不一致

复合类型，常量和 auto
编译器有时推断出来的 auto 类型和初始值不完全一样，编译器会适当改变其类型使符合轨规则
1 编译器以引用对象的类型作为 auto 的类型
int i = 0, &r = i;
auto a = r; //a 是一个整数（r 是 i 的别名，i 是一个整数）
2 auto 一般会忽略顶层 const 同时保留底层 const
const int ci = i, &cr = ci;
auto b = ci; //b 是一个整数（ci 的顶层const特性被忽略）
auto c = cr; //c 是一个整数（cr是ci的别名，ci 本身是一个顶层 const）
auto d = &i; //d 是一个整型指针
auto e = &ci; //e 是一个指向整数常量的指针（对常量对象取地址是一种底层 const）
如果希望推断出顶层 const，要明确指出
const auto f = ci; //ci 的推演类型是 int ，f 是 const int
也可以将引用类型设为 auto 原初始化规则仍适用
auto &g = ci; //g 是一个整型常量引用，绑定到 ci
auto &h = 42; //错误，不能为非常量引用绑定字面值
const auto &j = 42; //正确，可以为常量引用绑定字面值
设置一个类型为 auto 的引用使，初始值中的顶层常量仍保留
如果给初始值绑定一个引用，此时的常量并非顶层常量

要在一条语句定义多个变量，&和*只从属于某个声明符
auto k = ci, &i = i; // k 是整数，i是整型引用
auto &m = ci, *p = &ci; //m 是对整型常量的引用，p 是指向整型常量的指针
//错误，i 的类型是 int 而 &ci 的类型是 const int
auto &n = i, *p2 = &ci; 
NOTE 如何输出变量的数据类型
使用 typeid().name(); 如下
int a = 3;
cout << "a = " << typeid(a).name() << endl;
typeid().name() 包含在头文件 typeinfo 中
#include<typeinfo>

2.5.3 decltype 类型指示符
如何从表达式的类型推断出要定义的变量类型，但是不想用该表达式的值初始化变量？
使用 decltype，作用是选择并返回操作是的数据类型
操作过程中，编译器分析表达式得到其类型，却不实际计算表达式的值
decltype(f()) sum = x; //sum 的类型就是 函数f 的返回类型
编译器不实际调用函数 f ，而是使用当调用发生时 f 的返回值类型作为 sum 的类型
即编译器为 sum 指定的类型就是如果函数 f 被调用时要返回的类型

decltype 处理顶层 const 和引用方式与 auto 有些不同
如果 decltype 使用的表达式是一个变量，ze decltype 返回该变量类型（包括顶层const和引用在内）
const int ci = 0, &cj = ci;
decltype(ci) x = 0; //x 的类型是 const int
decltype(cj) y = x; //y 的类型是 const int &，y 绑定到变量 x 上
decltype(cj) z; //错误 ：z 是一个引用，必须初始化

decltype 和引用
如果 decltype 使用的表达式不是一个变量，则 decltype 返回表达式结果对应的类型
有些表达式向 decltype 会返回一个引用类型
一般这种意味着该表达式的结果对象能作为一条赋制语句的左值
//decltype 的结果可以是引用类型
int i = 42, *p = &i, &r = i;
decltype(r + 0)b;   //正确:加法的结果是 int ，因此 b 是一个（未初始化的）int 
decltype(*p)c; //错误:c 是 int &，必须初始化
因为 r 是一个引用，因此 decltype(r) 的结果是引用类型，如果想让结果类型是 r 所指的类型
如果想让结果类型是 r 所指的类型，可以把 r 作为表达式的一部分，如 r + 0，显然这个表达式
的结果将是一个具体值而非一个引用
另一方面，如果表达式的内容是解引用操作，则decltype将得到引用类型
解引用指针可以得到指针所指对象，还能给这个对象赋值
因此 decltype(*p) 的结果类型就是 int &，而非 int

decltype 和 auto 的另一处重要区别是，decltype 的结果类型与表达式形式密切相关
有一种情况需要特别注意：
对于decltype所用表达式，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同
如果decltype使用的是一个不加括号的变量，则得到的结果就是该变量的类型;
如果给变量加上了一层或多层括号，编译器就会把它当成是一个表达式。变量是一种可以作为赋值语句左值的特殊表达式
所以这样的decltype就会得到引用类型；
//decltype 的表达式如果是加上了括号的变量，结果将是引用
decltype((i))d; //错误：d 是 int &，必须初始化
decltype(i)e; //正确 ： e 是一个（未初始化的）int
NOTE decltype((variable))(注意是双层括号)的结果永远是引用，
而 decltype（variable)的结果只有当 variable 本身就是一个引用时才是引用

2.6 自定义数据类型
2.6.1 定义 Sales_data 类型
定义
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
我们的类以关键字 struct 开始，紧跟着类名和类体（其中类体部分可以为空）
类内部定义为名字必须唯一，但是可以与类外部定义的名字重复
类体右侧的表示结束的花括号后必须写一个分号，
因为类体后面可以紧跟变量名以示对该类型对象的定义，分号必不可少
struct Sales_data {
	/*
	*
	*/
}accum,trans,*salesptr;
//与下面的等价
struct Sales_data {
	/*
	*
	*/
};
Sales_data accum, trans, *salesptr;
//后续会学到 class 定义的数据结构

2.6.2 使用 Sales_data 类
和 Sales_item 类不同的是,自定义的 Sales_data 类没有提供任何操作
因为 Sales_data 类没有提供任何操作，所以我们必须自己编码实现输入，输出和相加的功能
添加两个Sales_data对象
假设已知Sales_data类定义于Sales_data.h文件
#include<iostream>
#include<string>
#include"Sales_data.h"
int main()
{
	Sales_data datal, data2;
	//读入 data1 和 data2 的代码
	//检查data1 和 data2 的ISBN 是否相同
	//如果相同，求 data1 和 data2 的总和
}
Sales_data 对象读入数据
string 类型是字符序列，操作有 >> （读入字符串） << （写出字符串） == （比较字符串）等
double price = 0;
std::cin >> data1.bookNo >> data1.units_sold >> price;


