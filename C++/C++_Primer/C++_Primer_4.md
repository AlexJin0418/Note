# 第四章 表达式





## 类型转换

C 语言类型转换：

```C
double f = 1.0 / 2;						// 隐式类型转换
double f = double(1) / double(2);		// 显式类型转换 (类型说明符)(表达式)
```



C 语言类型转换问题：

+ 任意类型之间都可以转换，编译器无法判断其正确性
+ 难于定位：在源码中无法快速定位



### C++ 类型转换

#### `const_cast`

用于转换指针或引用，去掉类型的 `const` 属性

```C++
// C++ 类型转换
const int a = 10;
int* pA = const_cast<int*>(&a);     // 将 const 属性去掉
*pA = 100;

cout << a << endl;  	// 10
cout << *pA << endl;	// 100
```

由于编译器会对 `const` 变量进行检查，所以打印 `cout << a << endl` 仍然会是 0

 

#### `reinterpret_cast`

重新解释类型，即不检查指向的内容，也不检查指针类型本身；但要求转换前后的类型所占用内存大小一致，否则将引发编译时错误

编译器不会对修改进行检查，所以程序员需要保证不会出错

```C++
int Test()
{
    return 0;
}

typedef void(*Funcptr)();		// 定义一个函数指针
Funcptr funcPtr;
funcPtr = reinterpret_cast<Funcptr>(&Test); // 将 Test() 转换成 Funcptr
```



### `static_cast` 和 `dynamic_cast`

`static_cast` 用与基本类型转换，有继承关系类对象和类指针之间转换，由程序员来确保转换是安全的，它不会产生动态转换的类型安全检查的开销

`dynamic_cast` 只能用于含有虚函数的类，必须用在多态体系中，用于类层次间的向上和向下转化；向下转化时，如果是非法的对于指针返回NULL



```C++
int i = 5;
double d = static_cast<double>(i);  // 5.0

double d1 = 5.6;
int i2 = static_cast<int>(d1);      // 5
```



```C++
class Base
{
public:
    Base() : _i(0) { ; }
    virtual void T() { cout << "Base: " << _i << endl; }
private:
    int _i;
};

class Derived : public Base
{
public:
    Derived() : _j(0) { ; }
    virtual void T() { cout << "Derived: " << _j << endl; }

private:
    int _j;

};

// dynamic_cast
Base cb;
Derived cd;
Base* pcb;
Derived* pcd;

// 派生类到基类
pcb = static_cast<Base*>(&cd);
pcb = dynamic_cast<Base*>(&cd);     // dynamic_cast 会进行检查

if (pcb == NULL)
{
    cout << "unsafe dynamic_cast from Derived to Base" << endl;
}

// 基类到派生类
pcd = static_cast<Derived*>(&cb);
pcd = dynamic_cast<Derived*>(&cb);

if (pcd == NULL)
{
    cout << "unsafe dynamic_cast from Base to Derived" << endl;
}
```

由于 `Base` 转换到 `Derived` 会有部分成员变量不存在，所以 `dynamic_cast` 会进行报错

# 


<details>
  <summary> 如何理解C++中的左值和右值 </summary>




  ``` 
当一个对象被用作右值的时候，用的是对象的值(内容)；当对象被用作左值的时候，用的是对象的身份(在内存中的位置)。
在需要右值的地方可以用左值来替代，但是不能把右值当左值使用。
  ```

</details>

<details>
  <summary> 什么是左结合律？</summary>

  ``` 
  左结合律意味着当优先级相同时，按照从左向右的顺序进行组合。
  ```
</details>

<details>
  <summary> 如果没有指定求值顺序，会发生什么？ </summary>

  ``` 
  对于没有指定执行顺序的运算来说，如果表达式指向并修改了同一个对象，将会引发错误并产生未定义的行为。
  ```
</details>

<details>
  <summary> m%(-n) 和 (-m)%n 分别等价于什么？ </summary>

  ``` 
  m % (-n) = m %n;
  (-m) % n = -(m % n);
  ```
</details>

<details>
  <summary> 什么是溢出？ </summary>

  ``` 
  当计算的结果超出该类型所能表示的范围时就会产生溢出。
  ```
</details>

<details>
  <summary> 什么是短路求值(short-circuit evaluation)？ </summary>

  ``` 
  逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值，这种策略叫做短路求值。
  对于逻辑与运算符来说，当且仅当左侧运算对象为真时才对右侧运算对象求值。
  对于逻辑或运算符来说，当且仅当左侧运算对象为假时才对右侧运算对象求值。
  ```
</details>

<details>
  <summary> 赋值运算符和关系运算符的优先级？ </summary>

  ``` 
  赋值运算符的优先级低于关系运算符的优先级
  ```
</details>

<details>
  <summary> 递增递减运算符的前置后置有什么不同？ </summary>

  ``` 
  j = i++ 表示先将i的值赋值给 j，然后 i = i+1
  j = ++i 表示先 i = i + 1，之后再让 j = i
  
  ```
</details>

<details>
  <summary> 如何理解解引运算符和后置递增运算符同时出现的情况？ *pbeg++ </summary>

  ``` 
  后置递增运算符的优先级高于解引运算符，因此*pbeg++等价于*(pbeg++)。
  pbeg++将pbeg的值加1，然后返回pbeg的初始值的副本作为其求解的结果，此时解引用运算符的运算对象是pbeg未增加之前的值。
  输出为pbeg开始时指向的那个元素，并将指针向前移动一个位置。
  ```
</details>

<details>
  <summary> 为什么该表达式是错误的？ *p.size() </summary>

  ``` 
  因为p是一个指针，而指针没有size()成员函数。
  解引用运算符的优先级低于点运算符，所以执行解引用运算的子表达式两端必须加上括号。
  表示为：(*P).size()，即对p进行解引后调用其成员函数size()。
  ```
</details>

<details>
  <summary> 什么是隐式转换？ </summary>

  ``` 
  当两个类型不同的值相加时，C++会先根据类型转换规则设法将运算对象的类型统一后再求值。上述的类型转换是自动执行的，无需程序员的介入。。
  因此被称为隐式转换。
  ```
</details>

<details>
  <summary> 何时发生隐式类型转换？ </summary>

  ``` 
  比int类型小的整型值首先提升为较大的整数类型。
  在条件中，非布尔值转换成布尔值类型。
  初始化过程中，初始值转换成变量的类型；在赋值语句中，右侧运算对象转换成左侧运算对象的类型。
  如果算术运算或关系运算的运算对象有多种类型，需要转换成同一种类型。
  ```
</details>

<details>
  <summary>显式转换的cast-name有哪些 </summary>

  ``` 
  static_cast, dynamic_cast, const_cast 和 reinterpret_cast
  ```
</details>

<details>
  <summary> static_cast的作用？ </summary>

  ``` 
  任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast。
  
  ```
</details>

<details>
  <summary> const_cast的作用？ </summary>

  ``` 
  const_cast只能改变对象的底层const。
  const_cast将常量对象转换成非常量对象，取消对象的const性质。
  ```
</details>

<details>
  <summary> reinterpret_cast的作用？</summary>

  ``` 
  reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释。
  reinterpret_cast本质上依赖于机器，应该避免使用。
  ```
</details>
