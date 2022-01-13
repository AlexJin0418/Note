# Project #1 - Buffer Pool

Implement a **Buffer Pool** in your storage manager.

The buffer pool is responsible for moving physical pages back and forth from main memory to disk.

It allows a DBMS to support databases that are larger than the amount of memory that is available to the system.

The buffer pool's operations are transparent to other parts in the system.



## 1. LRU Replacement Policy

`replacer_` 保存了一个含有 `frame_id` 的链表

可以将最近未使用过的 `frame_id` 返回给 `buffer pool manager`

`replacer_` 可由一个双向链表和一个 `map` 实现

双向链表保证了可以快速的将新元素插入到整个链表的首位

而 `map` 能够快速访问到 `frame_id` 对应在链表中的元素



## 2. Buffer Pool Manager Instance

`Buffer Pool Manager Instance` 由 4 部分组成：`Disk Manager`, `Page`, `Replacer_`, 以及 `Buffer Pool`



### Disk Manager

`Disk Manager` 用来访问和处理保存在磁盘上的文件

通过函数 `DiskManager::ReadPage` 和 `DiskManager::WritePage` 能够将磁盘中的数据写入对应的 `Page` 或者从 `Page`  中读取数据并写入磁盘



### Page

`Page` 可理解为磁盘存储区块在内存中的抽象，为一块在内存中开辟的空间用来保存对应磁盘空间的内容

`page_id_t` 表示该 `Page` 在磁盘中对应的位置，通过 `page_id_t` 和 `PAGE_SIZE` 可以定位对应的磁盘区域

```C++
// DiskManager.cpp
// static constexpr int PAGE_SIZE = 4096;
void DiskManager::ReadPage(page_id_t page_id, char *page_data) {
    int offset = page_id * PAGE_SIZE;
} 
```

该 `page_id_t` 与该 `Page` 在 `Buffer Pool` 中的位置无关

即便 `Page` 由于未被使用从 `Buffer Pool` 中被踢出，也可以通过 `page_id_t` 得到该 `Page` 对应的磁盘区域



### Replacer_

返回最近未使用的 `frame_id`



### Buffer Pool

`Buffer Pool` 是一块连续的内存地址，用来保存一系列 `Page`

通过 `Page` 所对应的磁盘数据，使得 `Buffer Pool Mananger` 能够读取并写入磁盘

在 `Buffer Pool` 中，每一个 `Page` 的下标即为 `frame_id`

`Buffer Pool Manager` 维护一个 `page_table` 用来映射 `page_id_t` 和 `frame_id` 的关系

即，如果一个 `Page` 在 `Buffer Pool` 中，则可以通过 `page_table` 得到对应的 `frame_id`

从而能够从 `Pages_` 数组中得到 `Page` 的实例



对于 `Page` 来说，是否存在与 `page_table` 中并不影响其对于磁盘的对应关系



**`Page *BufferPoolManagerInstance::NewPgImp(page_id_t *page_id)`**

建立一个新的映射关系，由 `AllocatePageId()` 可以得到一个新的 `page_id_t`，此 id 对应磁盘内一块没有被映射的区域

可从 `free_list_` 或 `replacer_` 中得到一个空闲的 `frame_id`

新创建的 `Page` 是 `pinned` 的，所以不会被添加到 `replacer_` 当中



**`Page *BufferPoolManagerInstance::FetchPgImp(page_id_t page_id)`**

获取一个指定的 `Page`

如果该 `Page` 在 `Buffer Pool` 中则返回

如果不在，则需要将该 `page_id` 对应的磁盘区块读取到一个有效的 `Page` 中

