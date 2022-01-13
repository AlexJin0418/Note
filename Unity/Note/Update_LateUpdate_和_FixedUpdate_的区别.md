# Update, LateUpdate 和 FixedUpdate 的区别



## MonoBehaviour.Update()

> Update is called every frame, if the MonoBehaviour is enabled. 
>
> `Update` is the most commonly used function to implement any kind of game script. Not every `MonoBehaviour` scripts needs `Update`.



`Update()` 与当前帧数相关，每一帧会调用一次

不同性能的机器表现出来的游戏帧数会不同，所以 `Update()` 调用的次数也不同

`Update()` 的刷新次序与脚本添加到场景中的顺序有关，相同物品中后添加的脚本将会首先执行 `Update()`



## MonoBehaviour.FixedUpdate()

> Frame-rate independent MonoBehaviour.FixedUpdate message for physics calculations.
>
> Use FixedUpdate when using Rigidbody. Set a force to a Rigidbody and it applies each fixed frame.
>
> FixedUpdate occurs at a measured time step that typically does not coincide with MonoBehaviour.Update



`FixedUpdate` 与当前帧数无关，是真实时间频率进行更新

所以处理物理逻辑例如 **Force**, **Collider**, **Rigidbody **时要把代码放在 `FixedUpdate()` 中而不是 `Update()`

对外设的操作也应该使用 `FixedUpdate()`

`FixedUpdate` 的时间间隔默认为50FPS（0.02s）

可以在 **Edit - Project Setting - Time** 找到 **Fixed timestep** 即可修改



## MonoBehaviour.LateUpdate()

> LateUpdate is called every frame, if the Behaviour is enabled.
>
> LateUpdate is called after all Update functions have been called. This is useful to order script execution. For example a follow camera should always be implemented in LateUpdate because it tracks objects that might have moved inside Update.



`LateUpdate` 是在所有 `Update` 函数调用后被调用，可用于调整脚本执行顺序

对于所有脚本，`LateUpdate` 会等所有的 `Update` 被调用后再调用

所以 `LateUpdate` 一般来对摄像机进行操作

而多个 `LateUpdate` 的调用顺序与脚本在 **Component** 中被挂载的顺序有关

当执行完所有的 `Update` 后，后挂在的脚本的 `LateUpdate` 会优先执行



## 参考资料

[Unity之Update与FixedUpdate区别](https://www.cnblogs.com/shirln/p/8471909.html)

[Unity中Update，FixedUpdate，LateUpdate的区别](https://www.cnblogs.com/dlyedu/p/7648463.html)

[Unity场景中各物体之间的Update刷新方法的刷新次序](https://blog.csdn.net/terrell21/article/details/97486559)

[FixedUpdate真的是固定的时间间隔执行吗？聊聊游戏定时器](https://blog.csdn.net/woliuqiangdong/article/details/120259345)

