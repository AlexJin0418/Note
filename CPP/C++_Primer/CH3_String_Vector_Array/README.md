# 第3章 字符串 向量和数组

## 3.1 命名空间的using声明
使用**using声明** 可以以更简单的途径来使用到命名空间中的成员。

**每个名字都需要独立的using声明**
> 按照规定，每个using声明引入命名空间中的一个成员。

**头文件不应包含using声明**
如果头文件中由某个using声明，那么每个使用了该头文件的文件就都会有这个声明。对于某些程序来说，由于不经意间包含了一些名字，反而可能产生始料未及的名字冲突。

## 3.2 标准库类型 string
标准库类型**string**表示可变长的字符序列，使用string类型必须包含string头文件
```C++
#include <string>
using std::string;
```

初始化：使用等号(=)执行的的是**拷贝初始化(copy initialization)**，编译器把等号右侧的初始值拷贝到新创建的对象中去。
相反，如果不适用等号，则为**直接初始化(direct initialization)**

**string::size_type类型**
string的size函数返回的类型是string::size_type。这是一个无符号类型的值，而且能足够存放下任何string对象的大小。所有用于存放string类的size函数返回值的变量，都应该是string::size_type。

> C++11新标准允许编译器通过auto或者decltype来推断变量的类型。

[string Reference](http://www.cplusplus.com/reference/string/string/size/)

因为返回值是一个无符号整型数，那么如果将string::size_type和一个int类型的负数比较时会出错，因为int类型的负数会自动地转换成一个比较大的无符号值。
**所以如果一条表达式中已经有了size()函数就不要再使用int了，这样可以避免混用int和unsigned可能带来的问题。**

**比较string对象**
string比较运算符依照字典顺序：
+ 如果两个string对象的长度不同，而且较短string对象的每个字符都与较长string对象对应位置上的字符相同，就说较短string对象小于较长string对象。
+ 如果两个string对象在某些对应的位置上不一致，则string对象比较的结果其实是string对象中第一对相异字符比较的结果。

字面值可以和string类型相加。
> 因为某些历史原因，也为了与C兼容，所以C++语言中的字符串字面值并不是标准库类型string对象。切记，字符串字面值与string是不同的类型。

### 3.2.3 处理string对象中的字符
cctype头文件中定义了一组标准库函数处理string对象中的字符。
> cctype是C++标准库头文件，由C语言标准库ctype.h转化而来。在命名上更符合标准。

[cctype Reference](http://www.cplusplus.com/reference/cctype/)

**使用范围for语句改变字符串中的字符**：
如果想要改变string对象中的字符，必须把循环变量定义成引用类型。引用类型是给定对象一个别名，因此当使用引用作为循环控制变量时，这个变量实际上被依次绑定到了序列的每个元素上。使用这个引用，我们就能改变它绑定的字符
```C++
#include <string>
using std::string;

string s = "hello world";
for (auto &c : s) {
    c = toupper(c);
}

cout << s << endl; // "HELLO WORLD"
```

**下标运算符 []：** 使用下标运算符能够指定string对象任意位置中的字符
> 使用超出范围的下标将引发不可预知的结果，所以string对象的下标必须大于等于0而小于s.size()

## 3.3 标准库类型vector
标准库类型**vector**表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引。vector是一个**类模板(class template)**

使用vector需要声明头文件
```C++
#incldue <vector>
using std::vector;
```

> vector是模板而非类型，由vector生成的类型必须包含vector中元素的类型，例如vector<int>

因为引用不是对象，所以不存在包含引用的vector

对于列表初始化，只能使用花括号进行列表初始化，而不能放在圆括号里初始化。

**值初始化：** 通常情况下，可以只提供vector对象容纳的元素数量而略去初始值。此时库会创建一个**值初始化的(value-initialized)** 元素初值。比如int，元素初始值自动设为0。如果元素是某种类类型，比如string，则元素由类默认初始化。

这种初始化有两种特殊限制：
+ 有些类要求必须明确地提供初始值
+ 如果只提供了元素的数量而没有设定初始值，只能使用直接初始化

**构造和列表初始化：**
+ 使用圆括号初始化：提供的值是用来构造vector对象的，大多提供容量值
+ 使用花括号初始化：花括号内的当作元素初始值的列表来处理

当花括号内的值和vector的类型不同时，在确认无法执行列表初始化后，编译器会尝试用默认初始化vector对象
```C++
vector<string> v1 {10, "hi"}; // 10是int类型无法初始化到string vector中，所以不是列表初始化
```

### 3.3.2 向vector对象中添加元素
使用成员函数**push_back()** 来向vector尾端添加新的元素。

> C++11标准要求vector能在运行时高效快速地添加元素。有效的办法是先定义一个空的vector对象，再在运行时向其中添加具体值。

`确保所写的循环正确无误，特别是在循环有可能改变vector对象容量的时候`

### 3.3.3 其他vector操作
vector的empty和size两个成员与string的同名成员功能完全一致：empty检查vector对象是否包含元素然后返回一个布尔值；size则返回vector对象中元素的个数，返回值的类型是由vector定义的size_type类型。
> 要使用size_type，需首先指定它是由哪种类型定义的。vector对象的类型总是包含着元素的类型

`vector可以使用下标[]符访问元素，但不能通过下标符来添加元素`

## 3.4 迭代器
