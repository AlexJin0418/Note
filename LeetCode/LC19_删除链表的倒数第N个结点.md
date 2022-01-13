# LC19. 删除链表的倒数第 N 个结点

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

```
输入：head = [1], n = 1
输出：[]
```

```
输入：head = [1,2], n = 1
输出：[1]
```



## 记录总数

先遍历一次找到整个链表结构的总数

之后再次遍历到待删除的位置之前，并删除所需要的节点

需要注意只有一个节点 `count == 1`  以及头部节点的情况 `count - n == 0`

```C++
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    int count = 0;
    while (fast != nullptr)
    {
        fast = fast->next;
        count++;
    }

    if (count == 1)
    {
        return nullptr;
    }

    int pos = count - n;

    if (pos == 0)
    {
        return head->next;
    }

    while(pos > 1)
    {
        slow = slow->next;
        pos--;
    }

    if (n == 1)
    {
        slow->next = nullptr;
    }
    else
    {
        slow->next = slow->next->next;
    }
    
    return head;
}
```



## 快慢指针

使用一个快指针和慢指针

快指针和慢指针之间的差距为 `n`

这样当快指针到达末位时，慢指针到达需要被删除的节点的前面

需要注意只有一个节点的情况，这时候 `slow == fast == head`

同时要注意删除头部节点的情况，这时候 `diff != n` 因为 `diff` 是从0开始记录

```C++
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* slow = head;
    ListNode* fast = head;
    
    int diff = 0;
    while (fast->next != nullptr)
    {
        if (diff != n)
        {
            fast = fast->next;
            diff++;
        }
        else
        {
            // diff between fast and slow is n
            fast = fast->next;
            slow = slow->next;
        }
    }

    // There is only one node
    if (slow == head && fast == head)
    {
        return nullptr;
    }

    // 
    if (slow == head && diff != n)
    {
        return head->next;
    }

    slow->next = slow->next->next;

    return head;
}
    
```

