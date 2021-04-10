# Monobehavior

通过 Unity 创建的脚本文件默认继承自 Monobehavior。

## Monobehavior 的九个生命周期

### Awake() 函数
在加载场景时运行，即在游戏开始之前初始化变量或者游戏状态。只执行一次。

### OnEnable() 函数
在激活当前脚本时调用，每激活一次就调用一次该方法。

### Start() 函数
在第一次启动时执行，用于游戏对象的初始化，在`Awake()`函数之后执行，只执行一次。

### FixUpdate() 函数
固定频率调用，与硬件无关，可以在 Edit -> Project Setting -> Time -> Fixed Time Step 修改。

### Update() 函数
几乎每一帧都在调用，取决于你的电脑硬件，不稳定。

### LateUpdate() 函数
在`Update()`后调用，一般用作与摄像机跟随。

### OnGUI() 函数
调用速度是`Update()`的两倍

### OnDisable() 函数
当从激活状态变成取消激活的状态就会被调用。和`OnEnable()`对立。

### OnDestroy() 函数
当前游戏对象或游戏组件被销毁时执行。

![Monobehavior](https://img-blog.csdn.net/20170327125028717?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGlob3pvbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## Monobehavior 常用方法
### 不可重写函数
+ `Invoke(function name, time)` 在`time`时间后调用`function name`。
+ `CancelInvoke()` 取消该Monobehavior上所有的`Invoke()`调用。
+ `IsInvoking(function)` 返回该`function`是否在等待调用。
+ `StartCoroutine(coroutine)` 启动该携程。

## 脚本与GameObejct的关系
被显式添加到 Hierarchy 中的 GameObject 会被最先实例化，GameObject 被实例化的顺序是从下往上。GameObject 被实例化的同时，加载其组件 component 并实例化，如果挂载了脚本组件，则实例化脚本组件时，将调用脚本的 Awake 方法，组件的实例化顺序是也是从下往上。在所有显式的 GameObject 及其组件被实例化完成之前，游戏不会开始播放帧。

当 GameObject 实例化工作完成之后，将开始播放游戏帧。每个脚本的第一帧都是调用 Start 方法，其后每一帧调用 Update，而且每个脚本在每一帧中的调用顺序是从下往上。

总结：被挂载到 GameObject 下面的脚本会被实例化成 GameObject 的一个成员。

## Reference: https://blog.csdn.net/hihozoo/article/details/66970467
