# C++ 类&对象

## 声明与定义

定义和声明成员函数的方式与普通函数差不多。成员函数的声明必须在类的内部，它的定义则既可以在类的内部也可以在类的外部。

**定义在类内部的函数是隐式的`inline`函数**。



## 类访问修饰符

数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。

类成员的访问限制是通过在类主体内部对各个区域标记 **public、private、protected** 来指定的。

```C++
class Base
{
    public;		// 公有成员
    private;	// 私有成员
    protected;	// 受保护成员
};
```

### public 公有成员

`public`成员在程序中类的外部是可访问的。可以不使用任何成员函数来设置和获取公有变量的值。

### private 私有成员

`private`成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。派生类无法查看私有成员变量和函数。

**默认情况下，类的所有成员都是私有的。**

```C++
class Box
{
    public:
    	double length;
    	double height;
    	double getWidth( void );
    private:
    	double width;
}

double Box::getWidth( void )
{
    return width;
}

int main()
{
    Box box1;
    double boxWidth = box1.getWidth();	// width是私有成员，只能通过对象调用成员函数来访问
}
```

### protected 受保护成员

`protected`成员变量和函数与私有成员十分相似，但是有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。

### 继承中的特点

有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

- **public 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private
- **protected 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private
- **private 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

但无论哪种继承方式，上面两点都没有改变：

- private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；
- protected 成员可以被派生类访问。

| 继承方式  | 基类的 public 成员 | 基类的 protected 成员 | 基类的 private 成员 | 继承引起的访问控制关系变化             |
| :-------- | ------------------ | --------------------- | ------------------- | :------------------------------------- |
| public    | 仍为 public        | 仍为 protected        | 不可见              | 基类的非私有成员在子类的访问属性不变   |
| protected | 变为 protected     | 仍为 protected        | 不可见              | 基类的非私有成员都变成子类的受保护成员 |
| private   | 变为 private       | 变为 private          | 不可见              | 基类的非私有成员都变成子类的私有成员   |



## 构造函数 & 析构函数

类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。

### 使用初始化列表来初始化字段

```C++
Line::Line( double len ): length(len)
{
    cout << "Object is being created" << len << endl;
}

// 等同于
Line::Line( double len )
{
 	length = len;
    cout << "Object is being created" << len << endl;
}

// 假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化
C::C( double a, double b, double c): X(a), Y(b), Z(c)
{
    // ....
}
```

使用列表初始化时，是按照**声明**的顺序初始化的，而不是按照初始化列表的顺序。所以如果声明的顺序和初始化列表的顺序不一样，那么声明顺序靠前的变量不会被正常初始化。

### 类的析构函数

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

一个类可以有多个构造函数，相当于构造函数重载。但是一个类只能有一个析构函数。

```C++
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // 这是构造函数声明
      ~Line();  // 这是析构函数声明
 
   private:
      double length;
};

// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}
```

当对象被释放掉时会调用析构函数。



## *拷贝构造函数

**拷贝构造函数**是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：

- 通过使用另一个同类型的对象来初始化新创建的对象。
- 复制对象把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。

```C++
classname (const classname &obj) {
   // 构造函数的主体
}
```

如果一个构造函数的第一个参数是自身类型类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数。

```C++
string dots(10, '.');				// 直接初始化
string s(dots);						// 直接初始化
string s2 = dots;					// 拷贝初始化
string nines = string(100, '9')		// 拷贝初始化
```

使用直接初始化时，我们实际上是要求编译器使用普通的函数匹配来选择与我们提供的参数最匹配的构造函数。

使用拷贝初始化时，我们要求编译器将右侧运算对象拷贝到正在创建的对象中，如果需要的话还要进行类型转换。

拷贝初始化不仅在我们用=定义变量时会发生，在下列情况也会发生（发生拷贝时）：

+ 将一个对象作为实参传递给一个非引用类型的形参
+ 从一个返回类型为非引用类型的函数返回一个对象
+ 用花括号列表初始化一个数组中的元素或一个聚合类中的成员



## 友元函数

类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的**友元 (friend)**。如果类想把一个函数作为它的友元，只需要增加一条以friend关键字开始的函数声明语句即可。

```C++
friend std::istream &read(std::istream&, Sales_data&);
```

友元声明只能出现在类定义的内部。

友元的声明仅仅指定了访问的权限，而非一个通常意义上的函数声明。

```C++
class Box
{
    double width;
public:
    friend void printWidth(Box box);	// 定义友元函数
    void setWidth(double wid);
}

// 定义成员函数
void Box::setWidth(double wid)
{
    width = wid;
}

// printWidth()不是任何类的成员函数
// 因为要访问非static成员，所以需要对象做参数
void printWidth(Box box)
{
   	std::cout << "width of box: " << box.width << std::endl;
}

```

因为友元函数没有`this`指针，则参数要有三种情况：

+ 访问非`static`成员时，需要对象做参数
+ 访问`static`成员或全局变量时，则不需要对象做参数
+ 如果做参数的对象是全局对象，则不需要对象做参数



## this指针

在 C++ 中，每一个对象都能通过 **this** 指针来访问自己的地址。**this** 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。

友元函数没有 **this** 指针，因为友元不是类的成员。只有成员函数才有 **this** 指针。

当我们调用成员函数时，实际上是替某个对象调用它。

成员函数通过一个名为`this`的额外隐式参数来访问调用它的那个对象。当我们调用成员函数时，用请求该函数的对象地址初始化`this`。相当于告知该成员函数哪个对象调用了这个函数。

`this`隐式地指向调用的成员，在成员函数的内部可以直接使用调用该函数的对象的成员，而无须通过成员访问运算符来做到这一点。

因为`this`总是指向调用成员函数的对象，所以`this`是一个常量指针，不允许改变`this`中保存的的地址。



## 指向类的指针

```C+
Box *ptrbox = &box1;	// 定义指向类的指针，并保存第一个对象的地址
ptrbox->width;			// 访问类内的成员变量
```



## 类的静态成员

可以使用 **static** 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。

```C++
Class Box
{
    public: 
    	static int objectCount;
    private:
    	double length;
    	double height;
    	double width;
};
```

静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。**我们不能把静态成员的初始化放置在类的定义中**，但是可以在类的外部通过使用范围解析运算符 **::** 来重新声明静态变量从而对它进行初始化

```C++

Class Box
{
    public: 
    	static int objectCount;
    private:
    	double length;
    	double height;
    	double width;
};

// 不能在类的内部定义初始化静态类成员
// 要在类外进行定义，可以不初始化
int Box::objectCount = 0;
```

#### 静态成员函数

如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，**静态函数**只要使用类名加范围解析运算符 **::** 就可以访问。

静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。

静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。

**静态成员函数与普通成员函数的区别：**

- 静态成员函数没有 `this `指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
- 普通成员函数有 `this` 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。

```C++
Class Box
{
    public:
    	static int objectCount;
    	
    	// 声明定义静态成员函数
    	static int getCount()
        {
            return obejctCount;
        }
    
    private:
    	double length;
    	double height;
    	double width;
};

// 使用范围解析运算符访问
int main()
{
    std::cout << "调用静态成员函数" << Box::getCount() <<< std::endl;
}
```

