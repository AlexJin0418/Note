
<details>
  <summary></summary>
  
  ```
  ```
</details>

## 标准库类型 string

<details>
  <summary>作用域操作符 ( :: ) 的含义是什么？</summary>
  
  ```
  编译器应该从左侧命名空间所示的作用域中寻找右侧那个名字。
  ```
</details>

<details>
  <summary>using声明的作用？</summary>
  
  ```
  使用using声明后就无须专门的前缀也能使用所需要的名字。
  ```
</details>

<details>
  <summary>为什么头文件中不应该使用using声明？</summary>
  
  ```
  using声明引入了命名空间内的一个成员。头文件的内容会拷贝到所有引用它的文件中去。
  
  如果头文件中有某个using声明，那么每个使用该头文件的文件都会有这个声明。如果有两个不同命名空间中的成员名是相同的，就会造成命名冲突。
  ```
</details>

<details>
  <summary>C++ 标准库中 string类型表示的是什么</summary>
  
  ```
  标准库类型 string 表示可变长的字符序列
  ```
</details>

<details>
  <summary>如何理解 string s(5, 'c')？</summary>
  
  ```
  string s(5, 'c') 的意思是初始化一为由连续5个字符'c'组成的字符串。
  ```
</details>

<details>
  <summary>什么是直接初始化？什么是拷贝初始化？</summary>
  
  ```
  拷贝初始化是使用等号(=)来初始化一个变量，编译器把右侧的初始值拷贝到新创建的对象中去。
  
  直接初始化是不使用等号的初始化。
  ```
</details>

<details>
  <summary>string.size()的返回类型是什么？</summary>
  
  ```
  string.size() 的返回类型是 size_type (size_t)。
  
  size_t 是 unsigned int 类型的别名。
  ```
</details>

<details>
  <summary>说明 string 类的输入运算符和 getline 函数分别是如何处理空白字符的？</summary>
  
  ```
  标准库 string 的输入运算符自动忽略字符串开头的空白 (包括空格符、换行符、制表符等)，从第一个真正的字符开始读起，直到于剑下一处空白为止。
  
  getline从给定的输入流中读取数据，直到遇到换行符为止，此时换行符也被读取进来，但是并不存储在最后的字符串中。而空白符也会被保留。
  ```
</details>

<details>
  <summary>为什么使用 for 循环改变字符串中的字符需要使用引用？</summary>
  
  ```
  引用相当于绑定到元素上，所以对引用的改变就是对元素的改变。
  
  而赋值只是将值拷贝给了一个新的变量，但并不能改变原来字符串中的值。
  ```
</details>

## 标准库类型 vector

<details>
  <summary>什么是vector类型</summary>
  
  ```
  标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引。vector也被称作容器。
  ```
</details>

<details>
  <summary>如何理解vector是一个类模板</summary>
  
  ```
  编译器根据模板创建类或函数的过程称为实例化，当使用模板时，需要指出编译器应把类或函数实例化成何种类型。
  
  当使用vector时，需要提供额外信息来确定vector内存放对象的类型。
  
  vector<int> ivec;       // ivec保存int类型的对象
  ```
</details>

<details>
  <summary>vector可以包含引用吗</summary>
  
  ```
  vector可以容纳大部分类型的对象作为其元素，但是因为引用不是对象，所以不存在包含引用的vector。
  ```
</details>

<details>
  <summary>使用圆括号和花括号初始vector的区别</summary>
  
  ```
  vector<int> v1(10);       // v1有10个元素，每个的值都是0
  vector<int> v2{10};       // v2有1个元素，该元素的值是10
  
  vector<int> v3(10, 1);    // v3有10个元素，每个的值都是1
  vector<int> v4{10, 1};    // v4有2个元素，分别为10和1
  
  当使用圆括号初始化时，可以说提供的值是用来构造vector对象的
  
  如果使用花括号初始化，可以表述为值是用来组成vector对象的
  ```
</details>

<details>
  <summary>如果列表初始化的值与vector中对象的值不一致会怎么样</summary>
  
  ```
  当确认无法执行列表初始化后，编译器会尝试用默认值初始化vector对象
  ```
</details>

<details>
  <summary>如何向vector中添加元素</summary>
  
  ```
  使用成员函数 push_back 将新元素添加到vector的尾部
  ```
</details>

<details>
  <summary>当什么情况下两个vector是相等的？</summary>
  
  ```
  两个vector对象相等当且仅当它们所含的元素个数相同，而且对应位置的元素值也相同。
  
  只有当元素的值可比较时，vector对象才能被比较。
  ```
</details>

<details>
  <summary>vector可以使用下标添加元素吗</summary>
  
  ```
  vector对象的下标运算符可用于访问已存在的元素，而不能用于添加元素。
  ```
</details>

<details>
  <summary></summary>
  
  ```
  ```
</details>

<details>
  <summary></summary>
  
  ```
  ```
</details>

<details>
  <summary></summary>
  
  ```
  ```
</details>

<details>
  <summary></summary>
  
  ```
  ```
</details>

<details>
  <summary></summary>
  
  ```
  ```
</details>
