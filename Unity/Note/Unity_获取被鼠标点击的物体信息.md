# 获取被鼠标点击的物体信息

当需要鼠标点击物体进行反馈时，通常使用 `Ray` 和 `RaycastHit` 来完成



```C#
Ray ray;
RaycastHit hit;

void Update
{
    if (Input.GetMouseButtonDown())
    {
        // 获取鼠标在屏幕点击点的位置
     	ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray, out hit))
        {
        	GameObject obj = hit.collider.gameObject;	// 获取被点击到的游戏物体
            if (obj.tag == "target")
            {
            	// ...
            }
        }
    }
    
}
```



`Input.GetMouseButtonDown()` 当鼠标左键按下时被调用

`Camera.main.ScreenPointToRay(Input.mousePoistion)` 返回一个从相机到鼠标在屏幕点击点的射线

`Physics.Raycast(ray, out hit)` 此时 `hit` 得到了场景内与射线进行碰撞的物体的信息

`hit.collider.gameObject` 由此可以获得与射线进行碰撞的游戏物体