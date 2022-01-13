# C++ Primer 第十一章 关联容器

关联容器和顺序容器有着根本的不同：**关联容器中的元素是按关键字来保存和访问的**。与之相对，顺序容器中的元素是按照它们在容器中的位置类顺序保存和访问的



关联容器支持高效的关键字查找和访问

两个主要的关联容器：`map` 和 `set`

+ `map` 中的元素是 关键字 - 值对 key - value：关键字索引，值表示与索引相关联的数据
+ `set` 中每个元素只包含一个关键字：`set` 支持高效的关键字查询操作



标准库提供 8 个关联容器

+ 或者是一个 `set`，或者是一个 `map`
+ 或者要求不重复的关键字，或者要求重复关键字 `multi`
+ 或者要求按顺序保存，或者要求无序保存，无序保存使用 `unordered`，利用哈希值保存



## 11.1 使用关联容器

#### 使用 `map`

`map` 保存一个键值组合，通过 key 来查找 value

```C++
map<string, size_t> word_count;
string word;
while (cin >> word)
{
    ++word_count[word];
}
for (const auto &w : word_count)	// 对 map 中的每个元素
{
    cout << w.first << " occurs " << w.second << endl; 
}
```

关联容器也是模板，所以要定义一个 `map`，我们必须指定关键字和值的类型

我们使用一个 `string` 作为下标，获得与此 `string` 相关联的 `size_t` 类型的计数器

当从 `map` 中提取一个元素时，会得到一个 `pair` 类型的对象

`pair` 是一个模板类型，保存两个名为 `first` 和 `second` 的公有数据成员



#### 使用 `set`

```c++
set<string> exclude = {"The", "But", "And", "An", "Or"};
string word;
while (cin >> word)
if (exclude.find(word) == exclude.end())
{
    ++word_count[word];
}
```

`set` 也是模板。为了定义一个 `set`，必须指定其元素类型

`exclude.find()` 查找给定的关键字是否在 `set` 中，会返回一个迭代器，迭代器指向该关键字，否则迭代器指向尾后迭代器



### 11.2 关联容器的概述

关联容器不支持顺序容器的位置相关的操作，例如 `push_front` 和 `push_back`，因为关联容器中元素是根据关键字存储的



### 11.2.1 定义关联容器

关联容器定义了一个默认构造函数，它创建一个指定类型的空容器

初始化 `map` 时，提供关键字类型和值类型，并用大括号包围 `{ key, value }`



#### 初始化 `multimap` 或 `multiset`

一个 `map` 或 `set` 中的关键字必须是唯一的，即，对于一个给定的关键字，只能有一个元素的关键字等于它

容器 `multimap` 或 `multiset` 没有此限制，它们都允许多个元素具有相同的关键字



### 11.2.2 关键字类型的要求

对于有序容器 `map`，`multimap`，`set` ，`multiset` ，关键字类型必须定义元素的比较方法。默认情况下，标准库使用关键字类型的 `<` 运算符来比较两个关键字



### 11.2.3 `pair` 类型

`pair` 标准库类型，定义在 `utility` 中



一个 `pair` 保存两个数据成员。类似容器，`pair` 是一个用来生成特定类型的模板

当创建一个 `pair` 时，我们必须提供两个类型名，`pair` 的数据成员将具有对应的类型。两个类型不要求一样

```C++
pair<string, string> anon;
pair<string, size_t> word_count;
pair<string, vector<int>> line;
```

`pair` 的数据成员是 public 的。两个成员分别命名为 `first` 和 `second`。我们可以用普通的成员访问符号来访问



#### 创建 `pair` 对象函数

新标准下，我们可以对返回值进行列表初始化来初始化一个 `pair` 返回值



## 11.3 关联容器操作

关联容器定义了额外的类型别名

```C++
set<string>::value_type v1;			// v1 是一个 string
set<string>::key_type v2;			// v2 也是一个 string
map<string, int>::value_type v3;	// v3 是一个 pair<const string, int>
map<string, int>::key_type v4;		// v4 是一个 string
map<string, int>::mapped_type v5;	// v5 是一个 int
```



### 11.3.1 关联容器迭代器

当解引用一个关联容器迭代器时，我们会得到一个类型为容器 `value_type` 的值的引用

对 `map` 而言，`value_type` 是一个 `pair` 类型，其 `first` 成员保存 `const` 的关键字，`second` 成员保存值

**\*\*一个 `map` 的 `value_type` 是一个 `pair` 类型，我们可以改变 `pair` 的值，但是不能改变关键字的值\*\***



#### `set` 的迭代器是 `const` 的

`set` 的两种迭代器 `iterator` 和 `const_iterator` 都只能读访问 `set` 中的元素

`set` 的关键字也是只读的 `const`，可以用一个 `set` 迭代器来读取元素的值，但不能修改



#### 遍历关联容器

`map` 和 `set` 都支持使用范围迭代器 `begin` 和 `end` 操作

我们可以使用范围迭代器来遍历关联容器

当使用一个迭代器遍历一个 `map`，`multimap`，`set`，或 `multiset` 时，迭代器按关键字升序遍历元素



#### 关联容器和算法

 我们通常不对关联容器使用泛型算法，因为泛型算法大部分是要修改或重排容器元素的算法，而关联容器的关键字 `const` 特性导致无法将关联容器中的元素传递给修改或重排容器元素的算法



实际编程中，如果我们要对一个关联容器使用算法，要么是将它当作一个原序列，要么当作一个目的的位置

使用 `copy` 或者 `insterter` 来拷贝关联容器内的元素



## 习题

+ 关联容器和顺序容器有什么不同？
+ `unorderd_map` 和 `map` 的区别？`multimap` 和 `map` 的区别？
+ `set` 的关键字可以被修改吗？

