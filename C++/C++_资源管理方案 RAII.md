# C++ 资源管理方案 RAII

RAII (Resource Acquisition Is Initializtion)

+ C++ 所特有的资源管理方式
+ RAII 依托栈和析构函数，来对所有的资源 -- 包括堆内存在内进行管理。对 RAII 的使用，使得 C++ 不需要类似于 Java 那样的垃圾收集方法，也能有效地对内存进行管理。RAII 的存在，也是垃圾收集虽然理论上可以在 C++ 使用，但从来没有真正流行过的主要原因
+ RAII 有些比较成熟的智能指针代表，如 std::auto_ptr 和 boost:shared_ptr



