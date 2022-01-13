# C++ 结构体与类

## 结构体 struct

结构体是 C++ 中另一种用户自定义的可用的数据类型，允许存储不同类型的数据项。

### 定义结构

使用 **struct** 语句。struct 语句定义了一个包含多个成员的新的数据类型。最后的分号之前，可以指定一个或多个结构变量，这是可选的。下面是声明一个结构体类型 **Books**，变量为 **book**：

```C++
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

### 访问结构成员

为了访问结构的成员，我们使用**成员访问运算符（.）**。

```C++
book.title = "new title";
```

### 结构作为函数参数

可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。

```C++
void printBook (struct Books book)
{
	std::cout << "Book title: " << book.title << std::endl;
}
```

### 指向结构的指针

可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似。

```C++
struct Books *struct_pointer = &book;

void printBook (struct Books *book)
{
	std::cout << "Book title: " << book->title << std::endl;
}
```

### typedef 关键字

可以使用`typedef`为创建的类型取一个"别名"

```C++
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}Books;

Books Book1, Book2;
```

这样可以直接使用 `Books` 来定义 `Books` 类型的变量，而不需要使用 `struct` 关键字。(作为函数参数时省略？)

*****C++ 中的 `struct` 是一个新类型的定义声明, 所以可以省略 `typedef`, 定义变量的时候也可以省略 `struct`, 而不用像C语言那样没用 `typedef` 取新名字, 就需要用 **struct 结构体名** 这种形式定义变量。

+ 使用`typedef`：在分号前的`object_name`会被定义为是结构体类型的名字。在使用结构体前必须要定义结构体变量。
+ 不使用`typedef`: 在分号前的`object_name`被定义为是结构体变量，可以直接使用这个变量访问结构体的内容。



## 类 Class

C++ 在 C 语言的基础上增加了面向对象编程，C++ 支持面向对象程序设计。

类中的变量被被称为类的成员变量，类中的函数被称为类的成员函数。

### 类定义

类定义是以关键字 **class** 开头，后跟类的名称。类的主体是包含在一对花括号中。类定义后必须跟着一个分号或一个声明列表。

```C++
class Box
{
   public:
      double length; 
      double breadth;  
      double height;   
};
```

关键字 **public** 确定了类成员的访问属性。在类对象作用域内，公共成员在类的外部是可访问的。也可以指定类的成员为 **private** 或 **protected**。

### 类定义实例

下面的例子定义了一个`Box`类:

```C++
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;   
      double breadth;  
      double height;   
    
      // 成员函数声明
      double get(void);
      void set( double len, double bre, double hei );
};

// 成员函数定义
double Box::get(void)
{
    return length * breadth * height;
}
 
void Box::set( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}
```

### 类成员函数声明与定义

类成员函数的声明与定义分开写是一种良好的书写习惯。

其次，定义在类内的函数会被默认为是内联函数，对于体积小的函数来说，内联函数能够减小栈空间的使用，但是会造成大量复制的代码，所以一般还是将定义写在类之外。

在外部定义成员函数时需要**范围解析运算符::**

```C++
void Box::set( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}
```

如果想要在类外定义内联函数的话，可以在函数的定义前加上`inline`关键字。

```C++
inline void Box::set( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}
```



## 类与结构体的区别

C++对`struct`进行了扩充，使得`struct`既可以包含成员变量，也可以包含成员函数。

类与结构体最本质的区别在于默认的访问控制，体现在两个方面：

+ 默认的继承访问权限。`struct`是public的，`class`是private。
+ `struct`作为数据结构的实现体，它默认的数据访问控制是public的，而`class`作为对象的实现体，它默认的成员变量访问控制是private的。
+ `class`关键字还可以定义模板参数，但是`struct`关键字不能定义模板参数。



