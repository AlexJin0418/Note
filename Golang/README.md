# Golang

## Go 语言结构
Go 语言的基础组成有以下几个部分：
+ 包声明

+ 引入包

+ 函数

+ 变量

+ 语句 & 表达式

+ 注释

```Go
package main // 定义了包名。必须在源文件中非注释的第一行指明这个文件属于哪个包

import "fmt" // 告诉 Go 编译器这个程序需要使用 fmt 包（的函数，或其他元素），fmt 包实现了格式化 IO（输入/输出）的函数

// main 函数是每一个可执行程序所必须包含的，一般来说都是在启动后第一个执行的函数。如果有init()函数先启动init()
func main() { 
	fmt.Println("Hello, World!"); // 输出到控制台的函数
}

// 当标识符（包括常量、变量、类型、函数名、结构字段等等）以一个大写字母开头
// 就可以被外部包的代码所使用
// 这被称为导出（像面向对象语言中的 public）
// 标识符如果以小写字母开头，则对包外是不可见的
// 但是他们在整个包的内部是可见并且可用的
```

可运行文件必须定义其包名为`main`；同一个文件不能定义两个包名。

### 行分隔符
在 Go 程序中，一行代表一个语句结束。每个语句不需要像 C 家族中的其它语言一样以分号 ; 结尾，因为这些工作都将由 Go 编译器自动完成。

### 标识符
一个标识符是一个或是多个字母(A~Z和a~z)数字(0~9)、下划线_组成的序列，但是第一个字符必须是字母或下划线而不能是数字。


## Go 语言数据类型
Go 语言包含以下类型：
+ **布尔型**：值是常量 true 或者 false

+ **数字类型**：整型 int 和浮点型 float32、float64。Go支持复数

+ **字符串类型**：Go 的字符串是由单个字节连接起来的。

+ **派生类型**：指针类型，数组类型，结构化类型，Channel类型，函数类型，切片类型，接口类型，Map类型

### 数字类型
数字类型分为有符号和无符号类型。

## Go 语言变量
定义变量时一般使用 `var` 来定义
```Go
var identifier type 

// 一次可以声明多个变量
var identifier1, identifier2 type
```

变量没有初始化时赋予零值。
+ 数值类型为 0
+ 布尔型为 false
+ 字符串类型为 ""
+ 其他类型为 nil

变量也可以使用`:=`来声明
```GO
v_name := v_value
// 其中 v_name 必须是新声明的变量
// 而不能是对 v_name 的赋值
```

如果声明了一个局部变量但是不使用，编译器会报错。

### iota
iota，特殊常量，可以认为是一个可以被编译器修改的常量。

iota 在 const关键字出现时将被重置为 0(const 内部的第一行之前)，const 中每新增一行常量声明将使 iota 计数一次(iota 可理解为 const 语句块中的行索引)。

```Go
const (
    a = iota
    b = iota
    c = iota
)

// 结果是 0, 1, 2
```

```Go
package main

import "fmt"

func main() {
    const (
            a = iota   //0
            b          //1
            c          //2
            d = "ha"   //独立值，iota += 1
            e          //"ha"   iota += 1
            f = 100    //iota +=1
            g          //100  iota +=1
            h = iota   //7,恢复计数
            i          //8
    )
    fmt.Println(a,b,c,d,e,f,g,h,i)
}

// 输出结果为 0, 1, 2, "ha", "ha", 100, 100, 7, 8
```
`const`中常量可以赋其他值，同时iota会继续自增

## 函数
Go语言中函数定义格式
```Go
func function_name(parameter list) [return type] {}
```

函数中使用引用作为参数可以将参数的地址值传到函数中，这样可以对实际的参数值进行改变

### Go 语言函数闭包
Go 语言支持匿名函数，可作为闭包。匿名函数是一个"内联"语句或表达式。匿名函数的优越性在于可以直接使用函数内的变量，不必申明。

```
package main

import "fmt"

func getSequence() func() int {
   i:=0
   return func() int {
      i+=1
     return i  
   }
}

func main(){
   /* nextNumber 为一个函数，函数 i 为 0 */
   nextNumber := getSequence()  

   /* 调用 nextNumber 函数，i 变量自增 1 并返回 */
   fmt.Println(nextNumber())
   fmt.Println(nextNumber())
   fmt.Println(nextNumber())
   
   /* 创建新的函数 nextNumber1，并查看结果 */
   nextNumber1 := getSequence()  
   fmt.Println(nextNumber1())
   fmt.Println(nextNumber1())
}
```

函数`getSequence()`的返回值是一个函数

## Go语言数组
Go 语言数组声明需要指定元素类型及元素个数，语法格式如下：
```var variable_name [SIZE] variable_type```

以上为一维数组的定义方式。例如以下定义了数组 balance 长度为 10 类型为 float32：
```var balance [10] float32```


