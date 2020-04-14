# 第7章 类
类的基本思想是**数据抽象(data abstraction)**和**封装(encapsulation)**。

数据抽象是一种依赖于**接口(interface)** 和**实现(implementation)** 分离的编程技术。类的接口包括用户所能执行的操作；类的实现则包括类的数据成员，负责接口实现的函数体以及定义类所需的各种私有函数。

封装实现了类的接口和实现的分离。封装后的类隐藏了它的实现细节，也就是说，类的用户只能使用接口而无法访问实现部分。

## 定义抽象数据类型
示例程序定义了一个Sales_data类和组成接口的非成员函数
```C++
struct Sales_data {

    // 声明内部成员函数
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    
    // 声明内部成员变量
    std::string bookNo;
    unsigned units_sold = 0;
    double revene = 0.0;
};

// 声明在Sales_data类外部的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

#### 定义成员函数
虽然成员函数和成员变量都需要在类的内部声明，但是成员函数体可以定义在类内也可以定义在类外。使用.h和.cpp文件分离声明和定义成员函数是一种比较好的方式。isbn()函数被定义在了类内。
```C++
std::string isbn() const { return bookNo; } // 被声明且定义在类内部的函数
```

#### 引入this
对于isbn成员函数的调用
```C++
Sales_data total;
total.isbn();
```
当我们调用成员函数时，实际上是在替某个对象调用它。如果`isbn`指向`Sales_data`的成员，比如`bookNo`，则`isbn`隐式地指向**调用该函数的对象的成员**。在上面的调用中，当 `isbn`返回`bookNo`时，实际上它隐式地返回`total.bookNo`。

成员函数通过一个名为**this**的额外的隐式参数来访问调用它的那个对象。当我们调用一个成员函数时，用请求该函数的对象地址初始化**this**。如果调用
```C++
total.isbn();
```
则编译器负责把`total`的地址传递给`isbn`的隐式形参`this`，可以等价地认为编译器将该调用重写成了如下地形式：
```C++
// 伪代码
Sales_data::isbn(&total)
```
因为成员函数有了`this`的隐式参数来访问调用它的对象，那么我们可以直接使用**调用该函数的对象的成员**。任何对类成员的直接访问都被看作`this`的隐式引用，也就是说，当`isbn`使用`bookNo`时，它隐式地使用`this`指向的成员，就像我们书写了`this->bookNo`一样。
所以我们可以把`isbn`的定义写成如下形式：
```C++
std::string isbn() const { return this->bookNo; }
```

#### 引入const成员函数
`isbn`函数的另一个关键之处是紧随参数列表之后的`const`关键字，这里`const`的作用是修改隐式`this`指针的类型。
默认情况下，`this`的类型是一个指向非常量的常量指针。因为`this`在成员函数中总是指向调用成员函数的对象，所以`this`是一个常量指针，`this`中保存的地址。所以在上例中，`this`的类型是
```C++
Sales_data *const
```
这就意味着我们不能将`this`绑定在一个**常量对象**上，因为`this`是一个指向非常量的常量指针。这一情况使得我们不能在一个**常量对象**上调用普通的成员函数。

那么我们可以将`this`声明成一个**指向常量的常量指针**：
```C++
const Sales_data *const
```
因为指向常量的指针即可以指向一个常量，也可以指向一个非常量。那么调用该成员函数的对象可以即是**常量对象**也可以是**普通对象**。这样有助于提高函数的灵活性。

因为`this`是**隐式的且不会出现在参数列表中**，所以我们将`const`关键字放在成员函数的参数列表之后。此时，紧跟在参数列表后面的`const`表示`this`是一个指向常量的指针。像这样的成员函数被称作**常量成员函数(const member function)**。

> 常量对象，以及常量对象的引用或指针都只能调用常量成员函数。

#### 类作用域和成员函数
类本身是一个作用域。类的成员函数的定义嵌套在类的作用域之内。

即使成员变量`bookNo`定义在成员函数`isbn`之后，`isbn`还是能够使用`bookNo`。编译器分两步处理类：首先编译**成员的声明**，然后才轮到**成员函数体**。因此，成员函数体可以随意使用类中的成员而无须在意这些成员出现的次序。

#### 在类的外部定义成员函数
当我们在类外部定义成员函数时，成员函数的定义与它的声明匹配。
```C++
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    else {
        return 0;
    }
}
```
函数名`Sales_data::avg_price`使用作用域运算符来说明：我们定义了一个名为`avg_price`的函数，并且该函数被声明在类`Sales_data`的作用域内。

#### 定义一个返回this对象的函数
成员函数`combine`表示调用该函数的对象和传入参数的对象进行复合赋值运算。
```C++
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold; // 把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}
```
当我们使用对象调用该函数时
```C++
total.combine(trans);
```
`total`的地址被绑定到隐式的**this参数上**，而`rhs`绑定到了`trans`上。
因为我们将左值隐式的绑定在了`this`参数，所以我们需要返回一个相同类型的对象。因为`this`指针指向了调用该成员函数的对象，那么返回值就是**解引this指针**。
```C++
return *this;
```

### 定义类相关的非成员函数
类经常需要定义一些辅助函数。这些函数不属于类本身，不是成员函数，而是作为类的接口组成部分。
> 一般来说，如果非成员函数是类接口的组成部分，则这些函数的声明应该与类在同一个头文件内。

### 构造函数
构造函数的任务是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数。构造函数没有返回类型。

如果类没有显示地定义构造函数，那么编译器会为我们隐式地定义一个默认构造函数。一旦我们定义了一些其他的构造函数，那么除非我们再定义一个默认的构造函数，否则类将没有默认构造函数。

> 只有当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数

#### 定义Sales_data类构造函数
```C++
Struct Sales_data {
    Sales_data() = default; // 默认构造函数
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, usigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
    // ...
}
```
默认构造函数不接受任何形参。在C++11新标准中，如果我们需要默认的行为，那么可以通过在参数列表后面写上 **= default** 来要求编译器生成构造函数。

#### 构造函数初始值列表
在构造函数后面冒号后是一个成员变量初始值的列表，每个名字后面括号内的值就是初始值。

通常情况下，构造函数使用类内初始值不失为一种好的选择，因为只要这样的初始值存在我们就能确保为成员赋予了一个正确的值。如果不能使用类内初始值，则所有构造函数都应该显式地初始化每个内置类型地成员。

***
## 访问控制与封装
在C++语言中，我们使用**访问说明符(access specifiers)** 加强类的封装性：
+ 定义在 public 说明符之后的成员在整个程序内可被访问，public成员定义类的接口。
+ 定义在 private 说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private部分封装了类的隐藏细节。

#### 使用 class 和 struct 关键字
`struct`和`class`都能定义类。如果使用`struct`关键字，则定义在第一个访问说明符之前的成员是**public**的；相反，如果我们使用`class`关键字，则这些成员是**private**的。
> 使用class和struct定义类唯一的区别就是默认的访问权限。

### 友元



