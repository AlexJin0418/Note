### 1. 什么是协同程序 coroutine
在主线程运行的同时开启另一段逻辑处理，来协助当前程序的执行。协程很像多线程，但不是多线程，Unity的协程是在每帧结束之后去检测yield的条件是否满足。

### 2. Unity3d中的碰撞器和触发器的区别？
碰撞器：collider; 触发器：isTrigger。碰撞器是一个部件 component，而触发器是碰撞器上的一个属性。碰撞器会根据物理引擎产生碰撞效果，通过 OnCollisionEnter() 触发；触发器并不会产生物理碰撞效果，通过 isTriggerEnter()检测物体是否通过被检测的区域。

### 3. 物体发生碰撞的必要条件？
两个物体都必须带有碰撞器（Collider），其中一个物体还必须带有Rigidbody刚体，而且必须是运动的物体带有Rigidbody脚本才能检测到碰撞。

### 4. 请简述 List 和 ArrayList 的区别 [X]
ArrayList存在不安全类型（ArrayList会把所有插入其中的数据都当做Object来处理，装箱拆箱的操作（费时，List是泛型类，功能跟ArrayList相似，但不存在ArrayList所说的问题。

### 5. 如何安全的在不同工程间安全地迁移asset数据？三种方法
1. 导出assets包。Export package
2. 将Assets目录和Library目录一起迁移
3. 用Unity自带的assets server功能

### 6. OnEnable、Awake、Start运行时的发生顺序？哪些可能在同一个对象周期中反复的发生
Awake()发生于Gameobject初始化时script component的初始化。

OnEnable()发生于该script被激活时。

Start()发生于该Gameobject首次运行时调用。

OnEnbale()可能会由于script反复激活而被重复调用。

### 7. MeshRender中material和sharedmaterial的区别？ [x]
修改sharedMaterial将改变所有物体使用这个材质的外观，并且也改变储存在工程里的材质设置。不推荐修改由sharedMaterial返回的材质。如果你想修改渲染器的材质，使用material替代。

### 8. Unity提供了几种光源，分别是什么
1. Point light 点光源
2. Directional light 平行光
3. Spot light 聚光灯
4. Area light 区域光源

### 9. 简述一下对象池，你觉得在FPS里哪些东西适合使用对象池 [xxx]
对象池就存放需要被反复调用资源的一个空间，当一个对象会大量生成的时候如果每次都销毁创建会很费时间，通过**对象池**把暂时不用的对象放到一个池中（也就是一个集合），当下次要重新生成这个对象的时候先去池中查找一下是否有可用的对象，如果有的话就直接拿出来使用，不需要再创建，如果池中没有可用的对象，才需要重新创建，利用空间换时间来达到游戏的高速运行效果，在FPS游戏中要常被大量复制的对象包括子弹，敌人，粒子等。用于减少内存开销。

通过一个List来保存prefab对象。使用时遍历整个list找到没有被在场景中激活的object并返回。如果没有可用的object则向list中添加新的object。
[对象池简单理解与应用](https://blog.csdn.net/l773575310/article/details/71601460?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-4.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-4.control)

### 10. CharacterController和Rigidbody的区别
Rigidbody具有完全真实物理的特性，Unity中物理系统最基本的一个组件，包含了常用的物理特性，而CharacterController可以说是受限的的Rigidbody，具有一定的物理效果但不是完全真实的，是Unity为了使开发者能方便的开发第一人称视角的游戏而封装的一个组件

### 11. 简述prefab的用处
在游戏运行时实例化，prefab相当于一个模板，对你已经有的素材、脚本、参数做一个默认的配置，以便于以后的修改，同时prefab打包的内容简化了导出的操作，便于团队的交流。

### 12. 请简述sealed关键字用在类声明时与函数声明时的作用
sealed修饰的类为密封类，类声明时可防止其他类继承此类，在方法中声明则可防止派生类重写此方法。

### 13. 请简述private，public，protected，internal的区别
public：对任何类和成员都公开，无限制访问

private：仅对该类公开

protected：对该类和其派生类公开

internal：只能在包含该类的程序集中访问该类

### 14. 使用Unity3d实现2d游戏，有几种方式？
1.使用本身的GUI，在Unity4.6以后出现的UGUI。使用Canvas。
2.把摄像机的Projection(投影)值调为Orthographic(正交投影)，不考虑z轴。
3.使用2d插件，如：2DToolKit，和NGUI

### 15. 在物体发生碰撞的整个过程中，有几个阶段，分别列出对应的函数
OnCollisionEnter(), OnCollisionStay(), OnCollisionExit()

### 16. Unity3d的物理引擎中，有几种施加力的方式，分别描述出来
rigidbody.AddForce(), rigitbody.AddForceAtPosition()

### 17. 什么叫做链条关节？[?]
Hinge Joint，可以模拟两个物体间用一根链条连接在一起的情况，能保持两个物体在一个固定距离内部相互移动而不产生作用力，但是达到固定距离后就会产生拉力。

### 18. 物体自身旋转使用的函数？
Transform.Rotate()

### 19. Unity3d提供了一个用于保存和读取数据的类(PlayerPrefs)，请列出保存和读取整形数据的函数
PlayerPrefs.SetInt(); PlayerPrefs.GetInt()

### 20. Unity3d脚本从唤醒到销毁有着一套比较完整的生命周期，请列出系统自带的几个重要的方法。
Awake() -> OnEnable() -> Start() -> Update() ->  FixedUpdate() -> LateUpdate() -> OnGUI() -> OnDisable() -> OnDestroy()

### 21. 物理更新一般放在哪个系统函数里？[x]
FixedUpdate，固定时间间隔执行 可以在edit->project setting->time设置 update 是在渲染帧执行，和Update不同的是FixedUpdate是渲染帧执行，如果你的渲染效率低下的时候FixedUpdate调用次数就会跟着下降。FixedUpdate比较适用于物理引擎的计算，因为是跟每帧渲染有关。Update就比较适合做控制。

### 22. 在场景中放置多个Camera并同时处于活动状态会发生什么？
游戏界面可以看到很多摄像机的混合。

### 23. 如何销毁一个UnityEngine.Object及其子类？
调用 GameObject.OnDestroy()

### 24. 请描述为什么Unity3d中会发生在组件上出现数据丢失的情况
绑定在组件上的物体对象被删除了或者是移动项目的时候丢失。Prefabs丢失的情况。

### 25. LOD是什么，优缺点是什么？[?]
LOD(Level of detail)多层次细节，是最常用的游戏优化技术。它按照模型的位置和重要程度决定物体渲染的资源分配，降低非重要物体的面数和细节度，从而获得高效率的渲染运算。缺点是增加了内存。

### 26. MipMap是什么，作用？
Mipmap用作与光栅化中，通过设置不同层级的mipmap，使得在不同分辨率下能够使用相应的mipmap。比如说一个纹理图片放大或者缩小的时候，如果使用相同的纹理图片，那么就会产生锯齿。但如果根据图片放大或缩小的程度来应用不同的mipmap的话，图像的效果就会好很多。

### 27. 请描述Interface与抽象类之间的不同 [xxxx]
抽象类表示该类中可能已经有一些方法的具体定义，但接口就是公公只能定义各个方法的界面 ，不能具体的实现代码在成员方法中。类是子类用来继承的，当父类已经有实际功能的方法时该方法在子类中可以不必实现，直接引用父类的方法，子类也可以重写该父类的方法。实现接口的时候必须要实现接口中所有的方法，不能遗漏任何一个。

### 28. .Net与Mono的关系？[xxxx]
mono是.net的一个开源跨平台工具，就类似java虚拟机，java本身不是跨平台语言，但运行在虚拟机上就能够实现了跨平台。.net只能在windows下运行，mono可以实现跨平台跑，可以运行于linux，Unix，Mac OS等。

### 29. 简述Unity3D支持的作为脚本的语言的名称
Unity的脚本语言基于Mono的.Net平台上运行，可以使用.NET库，这也为XML、数据库、正则表达式等问题提供了很好的解决方案。Unity里的脚本都会经过编译，他们的运行速度也很快。这三种语言实际上的功能和运行速度是一样的，区别主要体现在语言特性上。JavaScript、 C#、Boo

### 30. U3D中用于记录节点空间几何信息的组件名称，及其父类名称
Transform 父类是 Component

### 31. 向量的点乘、叉乘以及归一化的意义？
1.点乘表示两个向量的夹角余弦
2.叉乘得到垂直于两个向量的向量
3.归一化得到的是向量的方向，并不关心向量的大小

### 32. 为何大家都在移动设备上寻求U3D原生GUI的替代方案
不美观，OnGUI很耗费时间，效率不高，使用不方便

### 33. 请简述如何在不同分辨率下保持UI的一致性 [?]
NGUI很好的解决了这一点，屏幕分辨率的自适应性，原理就是计算出屏幕的宽高比跟原来的预设的屏幕分辨率求出一个对比值，然后修改摄像机的size。UGUI通过锚点和中心点和分辨率也解决这个问题

使用anchor?

### 34. 什么是LightMap？
LightMap:就是指在三维软件里实现打好光，然后渲染把场景各表面的光照输出到贴图上，最后又通过引擎贴到场景上，这样就使物体有了光照的感觉。

### 35. Unity和cocos2d的区别 [?]
Unity3D支持C#、javascript等，cocos2d-x 支持c++、Html5、Lua等。

cocos2d 开源 并且免费

Unity3D支持iOS、Android、Flash、Windows、Mac、Wii等平台的游戏开发，cocos2d-x支持iOS、Android、WP等。

### 36. C#和C++的区别？[?]
简单的说：C# 与C++ 比较的话，最重要的特性就是C# 是一种完全面向对象的语言，而C++ 不是，另外C# 是基于IL 中间语言和.NET Framework CLR 的，在可移植性，可维护性和强壮性都比C++ 有很大的改进。C# 的设计目标是用来开发快速稳定可扩展的应用程序，当然也可以通过Interop 和Pinvoke 完成一些底层操作。更详细的区别大家可以参考这里

### 37. 结构体和类有何区别？ struct 和 class
结构体是一种值类型，而类是引用类型。（值类型、引用类型是根据数据存储的角度来分的）就是值类型用于存储数据的值，引用类型用于存储对实际数据的引用。那么结构体就是当成值来使用的，类则通过引用来对实际数据操作

### 38. ref参数和out参数是什么？有什么区别？
ref和out参数的效果一样，都是通过关键字找到定义在主函数里面的变量的内存地址，并通过方法体内的语法改变它的大小。不同点就是输出参数必须对参数进行初始化。ref必须初始化，out 参数必须在函数里赋值。ref参数是引用，out参数为输出参数。

### 39. C#的委托是什么？有何用处？
委托类似于一种安全的指针引用，在使用它时是当做类来看待而不是一个方法，相当于对一组方法的列表的引用。用处：使用委托使程序员可以将方法引用封装在委托对象内。然后可以将该委托对象传递给可调用所引用方法的代码，而不必在编译时知道将调用哪个方法。与C或C++中的函数指针不同，委托是面向对象，而且是类型安全的。

### 40. C#中的排序方式有哪些？
选择排序，冒泡排序，快速排序，插入排序，希尔排序，归并排序

### 41. 射线检测碰撞物的原理是？
射线是3D世界中一个点向一个方向发射的一条无终点的线，在发射轨迹中与其他物体发生碰撞时，它将停止发射 。

### 42. Unity中，照相机的Clipping Planes的作用是什么？调整Near、Fare两个值时，应该注意什么？
剪裁平面 。从相机到开始渲染和停止渲染之间的距离。

### 43. 如何让已经存在的GameObject在LoadLevel后不被卸载掉？
void Awake() { DontDestroyOnLoad(transform.gameObject); }

### 44. 请简述GC（垃圾回收）产生的原因，并描述如何避免？
GC回收堆上的内存

避免：1.减少new产生对象的次数

2.使用公用的对象（静态成员）

3.将String换为StringBuilder

### 45. 反射的实现原理？[?]
审查元数据并收集关于它的类型信息的能力。实现原理：在运行时根据程序集及其中的类型得到元数据。下面是实现步骤：

导入using System.Reflection;

Assembly.Load(“程序集”)加载程序集,返回类型是一个Assembly

得到程序集中所有类的名称

foreach (Type type in assembly.GetTypes()) { string t = type.Name; }

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
