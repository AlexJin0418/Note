### 1. 什么是协同程序 coroutine
在主线程运行的同时开启另一段逻辑处理，来协助当前程序的执行。协程很像多线程，但不是多线程，Unity的协程是在每帧结束之后去检测yield的条件是否满足。

### 2. Unity3d中的碰撞器和触发器的区别？
碰撞器：collider; 触发器：isTrigger。碰撞器是一个部件 component，而触发器是碰撞器上的一个属性。碰撞器会根据物理引擎产生碰撞效果，通过 OnCollisionEnter() 触发；触发器并不会产生物理碰撞效果，通过 isTriggerEnter()检测物体是否通过被检测的区域。

### 3. 物体发生碰撞的必要条件？
两个物体都必须带有碰撞器（Collider），其中一个物体还必须带有Rigidbody刚体，而且必须是运动的物体带有Rigidbody脚本才能检测到碰撞。



## Reference:

[Unity面试题(包含答案)](https://blog.csdn.net/qq_21407523/article/details/108814300?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control)

[史上最全的Unity面试题（含答案）](https://blog.csdn.net/qq_34937637/article/details/79653525)

[2020年Unity3D应届生面试题](https://linxinfa.blog.csdn.net/article/details/106822744)

[【Unity3D】笔试题、面试题](https://blog.csdn.net/q764424567/article/details/106079221?utm_medium=distribute.pc_relevant_download.none-task-blog-2~default~blogcommendfrombaidu~default-9.nonecase&dist_request_id=1330144.11704.16180708237764089&depth_1-utm_source=distribute.pc_relevant_download.none-task-blog-2~default~blogcommendfrombaidu~default-9.nonecas)

[unity常见面试题](https://blog.csdn.net/kouzhuanjing1849/article/details/100517610?utm_medium=distribute.pc_relevant_download.none-task-blog-2~default~blogcommendfrombaidu~default-14.nonecase&dist_request_id=1330144.11704.16180708237764089&depth_1-utm_source=distribute.pc_relevant_download.none-task-blog-2~default~blogcommendfrombaidu~default-14.nonecas)

[腾讯游戏unity客户端面试题](https://blog.csdn.net/qq_17347313/article/details/100879439?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control)

[[Unity面试] 2021年Unity面试题分享](https://blog.csdn.net/qq_21407523/article/details/108814300?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control)

[unity面试题最新](https://www.jianshu.com/p/0ceec43da8d0)

[Unity3D面试题整合](http://www.360doc.com/content/18/0423/09/54584204_747989382.shtml)

