# C++ 结构体内存布局

```C++
struct s1
{
    char x;
    int z;
    short y;
};

struct s1
{
    char x;
    short y;
    int z;
};
```



在 32 位 CPU 中内存布局为：

0	X	X	X	X

4	X	X	X	X

8	X	X	X	X

....

即一个字由 4 个字节组成



对于 `s1` 来说，其内存分布为

CHAR 				X						X					   X	

INT					 INT				    INT				   INT

SHORT  			 SHORT			  X					  X 

即虽然 `char` 只占用一个字节，但是由于 `int` 占用四个字节，所以 `char` 会占用掉整个字



对于 `s2` 来说，其内存分布为

CHAR 				X						SHORT				SHORT

INT 				    INT					INT					  INT

即 `char` 和 `short` 通过在其中加入一个空的字节可以同时存在与一个字中，所以占用整个字

这样的排列会减小内存的占用



````C++
struct s3
{
    char x;
    short y;
    double z;
};
````

对于 `s3` 来说，理论上的内存分布为

CHAR 			X					SHORT					SHORT

DOUBLE

DOUBLE

即 `double` 会占用八个字节，但是根据规定，内存分配时需要将内存分配为结构体内最大类型的整数倍

所以此时 `s3` 会分配 十六 字节的大小



## 结构体对齐原则

32位CPU

`char` 任何地址

`short` 偶数地址

`int` 4的整数倍地址

`double` 4的整数倍地址



