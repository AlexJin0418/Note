<details>
  <summary> </summary>
  
  ``` 
  
  ```
</details>

<details>
  <summary>什么是静态类型(statically typed)语言？什么是动态类型(dynamically typed)语言？C++属于哪一种类型？</summary>
  
  ``` 
  静态类型语言：在编译阶段检查类型。编译器负责检查数据类型是否支持要执行的运算，如果试图执行不支持的运算，编译器将报错。
  
  动态类型语言：在程序运行期间才去做数据类型的检查。对于动态数据类型语言，不用给任何变量指定数据类型，该语言会在第一次赋值给变量时，在内部将数据类型记录下来。
  
  C++属于静态类型语言。编译器在编译时会对程序中的变量类型进行检查。
  ```
</details>

<details>
  <summary>什么是分离式编译(separate compilation)？</summary>
  
  ```分离式编译允许程序分割成若干个文件，每个文件可以被独立编译。```
</details>

<details>
  <summary>声明和定义的区别？</summary>
  
  ```
  声明(declaration)：使得名字被程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。
  
  定义(definition)：负责创建与名字关联的实体。定义申请了存储空间，也可能为变量赋一个初始值。
  
  一个变量可以被声明多次，但只能被定义一次。
  ```
</details>

<details>
  <summary>如何声明但不定义一个变量？</summary>
  
  ```使用 extern 关键字。```
</details>

<details>
  <summary>什么是C++引用？</summary>
  
  ``` 
  引用 &，相当于为对象起了另一个名字。引用不是拷贝值，而是为一个已经存在的对象所起的另外一个名字。引用和其引用的对象共享相同的内存地址。
  ```
</details>

<details>
  <summary>
    下面的哪个对引用的定义是不合法的？为什么？
    
    (a) int &rval1 = 1.01;
    (b) int &rval2 = rval1;
    (c) int &rval3;
  </summary>
  
  ``` 
    (a) int &rval1 = 1.01; //错误，引用类型的初始值必须是一个对象
    (b) int &rval2 = rval1; //错误，引用并非对象，所以不能定义引用的引用
    (c) int &rval3; //错误，引用与其对象进行绑定，并且无法更改绑定的对象，所以引用必须初始化
  ```
</details>

<details>
  <summary>
    如何理解下面的代码，v1，v2，v3的值分别是什么？

    int main() {
      int v1 = 1;
      int &v2 = v1;
      int v3 = 3;
      v2 = v3;
    }
  </summary>
  
  ``` 
    v1 = v2 = v3
    v2 是对 v1 的引用，v2 绑定了 v1，所以 v2 和 v1 有相同的内存地址
    将 v2 赋值为 v3 的值，实际上是对 v1 的赋值
  ```
</details>

<details>
  <summary>说明指针和引用的主要区别</summary>
  
  ``` 
    指针“指向”内存中的某个对象，而引用“绑定到”内存中的某个对象。
    指针本身是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以指向几个不同的对象；引用不是对象，无法令其重新绑定到另外一个对象。
    指针无须在定义时赋值，在块作用域内定义的指针如果没有被初始化，将会拥有一个不确定的值；引用必须在定义时赋初始值。
  ```
</details>

<details>
  <summary>
    说明下列变量的类型和值
    
    (a)int* p, i, &r = i;
    (b)int i, *ip = 0;
    (c)int* ip, ip2;
    (d)int i = 42, *p, *&r = p; r = &i; *r = 0;
  </summary>
  
  ``` 
    (a)int* p, i, &r = i; // 定义一个整型指针p，一个整型变量i，和一个i的引用r
    (b)int i, *ip = 0;  // 定义了一个整型变量i，一个整型空指针ip
    (c)int* ip, ip2;  // 定义了一个整型指针ip，一个整型变量ip2
    (d)int i = 42, *p, *&r = p; r = &i; *r = 0; // 定义了一个整型变量i，一个整型指针，一个对指针的引用；对r赋值就是令p指向i的地址；对r解引就是对p的解引，令i的值为0
  ```
</details>

<details>
  <summary>const对象必须初始化吗？</summary>
  
  ``` 
  因为const对象一旦创建后其值就不能再改变，所以const对象必须初始化。
  ```
</details>

<details>
  <summary>什么是对常量的引用？</summary>
  
  ``` 
  对常量的引用是将引用绑定在常量对象上。对常量的引用不能被用作修改它所绑定的对象，所以常量引用必须被const所限定。
  如果使用一个非常量引用来引用一个常量，那么这个引用就可以改变它引用对象的值，这显然违反了常量对象不可赋值的规定。
  
  const int v1 = 10;
  const int &val1 = v1;
  ```
</details>

<details>
  <summary>初始化常量引用与非常量引用的区别</summary>
  
  ``` 
  初始化常量引用时允许绑定非常量对象，字面值，甚至是个一般表达式；而非常量引用初始化只能绑定一个对象。
  ```
</details>

<details>
  <summary>如何理解对常量的引用引用了一个非常量对象</summary>
  
  ``` 
  对常量的引用可以引用一个非常量对象。对于常量引用来说，无论引用的对象是是常量还是非常量，常量引用都将其看作是一个常量。
  所以常量引用不会对所引用的对象进行更改。
  但是对于被引用的非常量对象，可以通过其他方式进行赋值。
  ```
</details>

<details>
  <summary>什么是指向常量的指针？</summary>
  
  ``` 
  指向常量的指针就是一个指针指向了一个常量。对于这个指针来说，因为其指向的对象是一个常量，所以无法通过解引操作来更改指向对象的值。
  所以想要存放常量对象的地址，必须使用指向常量的指针。
  
  const double pi = 3.14;
  const double* ptr = &pi;
  *ptr = 1; // 错误，无法通过解引操作对常量对象进行赋值
  
  指向常量的指针也可以指向一个非常量。与常量引用相同，指向常量的指针无论指向的对象是常量还是非常量，都不会去更改其指向对象的值。
  
  简单讲，就是指向常量的指针无法使用解引操作对指向对象进行赋值。
  ```
</details>

<details>
  <summary>什么是常量指针？</summary>
  
  ``` 
  常量指针是指指针本身是一个常量。常量指针必须初始化，而且一旦初始化完成，则它的值，也就是存放在指针中的那个地址，就不能再改变了。
  
  int errNumb = 10;
  int *const curErr = &errNumb // curErr 将一直指向 errNumb
  ```
</details>

<details>
  <summary>
    下面哪些初始化是合法的？请说明原因
    
    (a)int i = -1, &r = 0;
    (b)int *const p2 = &i2;
    (c)const int i = -1, &r = 0;
    (d)const int *const p3 = &i2;
    (e)const int *p1 = &i2;
    (f)const int &const r2;
    (g)const int i2 = i, &r = i;
  </summary>
  
  ``` 
    (a)int i = -1, &r = 0; // 不合法。引用不可以初始化为数值，只能初始化为对象。
    (b)int *const p2 = &i2; // 合法
    (c)const int i = -1, &r = 0;  // 合法
    (d)const int *const p3 = &i2; // 合法
    (e)const int *p1 = &i2; // 合法
    (f)const int &const r2; // 不合法。引用不是对象，所以不能使引用恒定不变
    (g)const int i2 = i, &r = i;  // 合法
  ```
</details>

<details>
  <summary>
    说明下面这些定义是什么意思，挑出其中不合法的。
    
    (a) int i, *const cp;
    (b) int *p1, *const p2;
    (c) const int ic, &r = ic;
    (d) const int *const p3;
    (e) const int *p;
  </summary>
  
  ``` 
    (a) int i, *const cp; // 声明一个整型变量i；声明一个常量指针，不合法，常量指针必须被初始化
    (b) int *p1, *const p2; // 声明一个指针p1；声明一个常量指针p2，不合法，常量指针必须被初始化
    (c) const int ic, &r = ic;  // 声明一个常量整型变量ic，不合法，因为常量必须被初始化；声明并定义一个ic的常量引用
    (d) const int *const p3;  // 声明一个指向常量的常量指针，不合法，常量指针必须被初始化
    (e) const int *p; // 声明一个指向常量的指针p
  ```
</details>

<details>
  <summary>
    假设已有上面的那些变量，下面哪个语句是合法的？
    
    (a) i = ic;
    (b) p1 = p3;
    (c) p1 = &ic;
    (d) p3 = &ic;
    (e) p2 = p1;
    (f) ic = *p3;
  </summary>
  
  ``` 
    (a) i = ic; // i不是常量，可以被赋值为ic的值
    (b) p1 = p3;  // p1指向了一个常量，而p1可以通过解引符号对指向的常量赋值，不合法
    (c) p1 = &ic; // p1不可以指向ic，因为ic是一个常量，而p1可以通过解引符号对ic进行赋值，不合法
    (d) p3 = &ic; // p3是一个指向常量的常量指针，所以不能够进行赋值，不合法
    (e) p2 = p1;  // p2是一个常量指针，不能进行赋值，不合法
    (f) ic = *p3; // ic是一个常量，不能进行赋值，不合法
  ```
</details>