# C++ void* 与 null 和 nullptr

在 C 语言中

```C
#define NULL ((void*)0)
```

`void*` 可以转换成任何类型的指针



C++11 中 `nullptr` 替代 `(void*)0`，NULL 则只表示 0



```C++
void func(void* i)
{
    cout << "func(void* i)" << endl;
}

void func(int i)
{
    cout << "func(int i )" << endl;
}


int main()
{
    int* pi = NULL;
    int* pi2 = nullptr;
    char* c1 = NULL;
    char* c2 = nullptr;

    func(NULL);         // 0
    func(nullptr);      // void*
    func(pi);           // void*
    func(pi2);          // void*
    func(c1);           // void*
    func(c2);           // void*

}
```

