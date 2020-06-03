<details>
  <summary></summary>
  
  ```
  ```
</details>

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
