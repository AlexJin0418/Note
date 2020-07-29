<details>
  <summary>下列语句是否合法？ ival = v1 + v2; ; </summary>
  
  ``` 
  该语句是合法的。ival = v1 + v2; 表示一个赋值语句，而后面的分号 ; 表示一条空语句。
  ```
</details>

<details>
  <summary> 下列语句是否合法？ while (iter != svec.end()) ; ++iter; </summary>
  
  ``` 
  该语句不合法，while循环后额外的分号导致while循环空转，所以iter无法自增，则代码将无休止循环下去。
  ```
</details>

<details>
  <summary>什么是块？ 是什么时候会用上块？</summary>
  
  ``` 
  块是复合语句，又花括号括起来的语句和声明的序列。一个块就是一个作用域。
  当语法上需要一条语句，但是逻辑上需要多条语句时应该使用复合语句。
  ```
</details>

<details>
  <summary> 什么是悬垂else？</summary>
  
  ``` 
 悬垂else指的是在那些既有if语句又有if else语句中存在的程序二义性的问题。
 C++规定 else 与离它最近的尚未匹配的 if 匹配。
  ```
</details>

<details>
  <summary> break语句的作用？</summary>
  
  ``` 
  break语句负责终止离它最近的 while, do while, for 或 switch 语句，
  并从这些语句之后的第一条语句开始继续执行。
  ```
</details>

<details>
  <summary> 为什么case标签必须是整型常量表达式？</summary>
  
  ``` 
  使用整形常量表达式为了保证在编译时就知道case标签的内容。
  ```
</details>

<details>
  <summary> for循环能否省略掉 init-statement, condition, expression 中的任何一个？</summary>
  
  ``` 
  for循环可以省略掉 init-statment, condition, expression中的任何一个，或者所有。
  我们可以使用空语句作为 init-statement。
  如果省略了condition，我们默认condition = true。
  当省略掉expression，我们要保证for循环主体内有迭代或者结束循环的语句。
  ```
</details>

<details>
  <summary> do while 和 while 的区别</summary>
  
  ``` 
  do while 定义为先循环，再判断，所以无论如何都会执行一次循环体。
  而 while 是先判断，再执行循环，如果条件不满足则不会进行循环。
  ```
</details>

<details>
  <summary> continue语句的作用？</summary>
  
  ``` 
 continue语句终止最近的循环中的当前迭代并且立即开始下一次迭代。
 continue只是终止当前迭代，但是仍然继续执行循环。
  ```
</details>

<details>
  <summary> C++中，异常处理包括什么？ </summary>
  
  ``` 
  throw表达式，异常检测部分使用throw表达式来表示它遇到了无法处理的问题。引发了异常。
  try 语句块，异常处理部分使用try语句块处理异常。try语句块从关键字 try开始，并包含一个或多个catch子句。try语句块中的代码抛出的异常通常会被某个catch子句处理。
  一套异常类，用于在throw表达式和相关的catch子句之间传递异常的具体信息。
  ```
</details>

<details>
  <summary> 抛出异常后会发生什么？</summary>
  
  ``` 
  抛出异常将终止当前的函数，并把控制权转移给能够处理该异常的代码。
  ```
</details>
