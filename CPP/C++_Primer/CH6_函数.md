<details>
  <summary> 形参和实参的区别是什么？ </summary>
  
  ``` 
  形参出现在函数定义的地方，形参列表可以包含0个，1个或多个形参。形参规定了一个函数所接受数据的类型和数量。
  实参出现在函数调用的地方，实参的数量和形参一样多。实参的主要作用是初始化形参，并且这种初始化过程是一一对应的。
  ```
</details>

<details>
  <summary> 如何理解局部静态对象 </summary>
  
  ``` 
  局部静态对象(local static object)在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁。
  局部静态对象使用static修饰。
  当函数在第二次或多次访问时，局部静态对象并不会被重新定义，而是保留了上一次函数被调用时的值。
  只有在程序结束后，局部静态对象才会被销毁。
  ```
</details>

<details>
  <summary> 如何理解形参的引用和拷贝？</summary>
  
  ``` 
  当形参是引用类型时，我们说它对应的实参被引用传递，形参将绑定实参。
  当形参不是引用类型时，我们说实参的值被拷贝给形参，形参和实参是两个独立的对象。改变形参并不会改变实参的值。
  ```
</details>

<details>
  <summary> 如何使函数返回多个值？ </summary>
  
  ``` 
  通过给函数传入一个额外的引用实参，这样就可以在函数体内改变这个引用实参来得到获取多个返回值的效果。
  ```
</details>

<details>
  <summary> 下面两个定义是否相同？ void func(const int i) {} ; void func(int i) {}; </summary>
  
  ``` 
  这两个定义是相同的。对于const形参来说，会自动忽略掉顶层const。
  也就是说如果形参是一个const，那么向函数中传入const或者不是const类型的实参都是可以的。
  因为形参定义了传入的参数是const，也就是说函数体内并不会对该参数做出修改，所以传入const或者非const的实参都是可以的。
  ```
</details>

<details>
  <summary>如果函数的一个形参不会发生改变，那么应该如何定义指针和引用形参？</summary>
  
  ``` 
  如果一个函数的形参不会发生改变，那么应该定义成常量引用。
  ```
</details>

<details>
  <summary> 如何向函数中传递一个数组？</summary>
  
  ``` 
  数组有两个特性：1.不允许拷贝数组；2.使用数组时会将其转换成指针。
  所以当为函数传递一个数组时，实际上传递的是指向数组首元素的指针。
  ```
</details>

<details>
  <summary> 当函数形参传入一个数组时，函数直到这个数组的长度吗？</summary>
  
  ``` 
  因为数组是以指针的形式传给函数的，所以函数只直到指针表示的是数组的首个元素。
  函数需要其他信息来直到数组的大小。
  ```
</details>

<details>
  <summary> 如何管理指针形参？</summary>
  
  ``` 
  1. 使用标记指定数组长度：当数组最后一位是一个空字符时，函数会遇到空字符停止。
  2. 使用标准库规范：传递指向数组首元素和尾后元素的指针。
  3. 显式传递一个表示数组大小的形参：将数组的大小以形参的方式传递到函数中。
  ```
</details>

<details>
  <summary> 什么是 initializer_list 形参</summary>
  
  ``` 
  如果函数的实参数量未知但是全部实参的类型都相同，我们可以使用 initializer_list 类型的形参。
  initializer_list是模板类型，定义initializer_list对象时必须说明列表中所含元素的类型。
  initializer_list中的值是常量值，我们无法改变initializer_list对象中元素的值。
  
  ```
</details>

<details>
  <summary> 函数的返回值是如何被返回的？</summary>
  
  ``` 
  函数返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。
  如果函数返回引用，则该引用仅是它所引用对象的一个别名。
  ```
</details>

<details>
  <summary> 为什么不要返回局部对象的引用或指针？</summary>
  
  ``` 
  因为在函数内定义的局部对象会在函数结束后被销毁。
  所以函数终止意味着局部变量的引用将指向不再有效的内存区域。
  ```
</details>

<details>
  <summary> </summary>
  
  ``` 

  ```
</details>

<details>
  <summary> </summary>
  
  ``` 

  ```
</details>

<details>
  <summary> </summary>
  
  ``` 

  ```
</details>
