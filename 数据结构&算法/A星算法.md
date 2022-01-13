# A* 算法

A* 算法是一种静态路网中求解最短路径最有效的搜索方法



路径优劣评价公式：`f(n) = g(n) + h(n)`

`f(n)`：从初始状态经由状态 `n` 到目标状态的代价估计

`g(n)`：在状态空间中从初始状态到状态 `n` 的**实际代价**

`h(n)`：从状态 `n` 到目标状态的最佳路径的**估计代价**



使用两个状态表

`openList`：由待考察的节点组成

`closeList`：已经考察过的节点组成



## 1.预处理

+ 将地图栅格化：把每个正方形格子的中央称为节点

+ 确定栅格属性：即每一个格子有两种状态：可走和不可走

+ 定义两个列表集合：`openList` 表示由待考察的节点组成，`closeList` 表由已经考察过的节点组成

+ 确定起始节点和目标节点

![A星算法1](C:\Users\liang\Desktop\计算机面试\.assets\A星算法1.png)

+ 初始时，定义 `A` 为父节点，节点 `A` 离自身距离为 0，路径完全确定，移到 `closeList` 中

+ 父节点 `A` 周围共有 8 个节点，定义为子节点，将子节点放入 `openList` 中，成为待考察对象

+ 若某个节点即未在 `openList`，也没在 `closeList` 中，则表明还未搜索到该节点

+ 路径优劣判断依据是移动代价，单步移动代价采取**Manhattan 计算方式**，即把横向和纵向移动一个节点的代价定义为10；斜向移动代价参考等腰三角形计算斜边的方式，距离为14

![Astar2](C:\Users\liang\Desktop\计算机面试\.assets\Astar2.png)



## 2.搜索

![astar_search](C:\Users\liang\Desktop\计算机面试\.assets\astar_search.png)

+ 移动代价函数为 `f(n) = g(n) + h(n)`。`f(n)` 表示初始状态经由状态 `n` 到目标函数状态的代价估计，`g(n)` 是在状态空间中从初始状态到状态 `n` 的实际代价，`h(n)` 是从状态 `n` 到目标状态的最佳路径的估计代价
+ 对于节点 `I`，可以由计算得到，`g(n) = 14`，`h(n) = 40`，则总的代价为 `f(n) = 54`
+ 以此类推，通过计算得到总的最小的消耗的节点为 `F`，则将 `F` 移动到 `closeList` 中
+ 现在 `openList = {B,C,D,E,G,H,I}`, `clostList = {A,F}`
+ 此时以 `F` 节点作为父节点，此时可对 `F` 节点的周围进行搜索，节点 `A` 以及障碍物节点将会被忽略

![astar_search2](C:\Users\liang\Desktop\计算机面试\.assets\astar_search2.png)

+ 此时可搜索的节点为 `C, D, H, I`
+ 如果某个相邻的节点已经在 `openList` 中，则检查这条路径是否更优，也就是说经由当前节点到达那个节点是否具有更小的 `g` 值，实际代价值，如果没有，不做任何操作
+ 以此类推，不断重复。一旦搜索到目标节点，完成路径搜索



## Python 代码实现

```python
def a_star_search(graph, start, goal):
    frontier = PriorityQueue()		// 使用 PriorityQueue 会自动返回实际成本和期望成本值最小的一个节点
    frontier.put(start, 0)
    came_from = {}
    cost_so_far = {}
    came_from[start] = None
    cost_so_far[start] = 0
    
    while not frontier.empty():
        current = frontier.get()
        
        if current == goal:
            break
           
       	for next in graph.neighbors(current):
            new_cost = cost_so_far[current] + graph.cost(current, next) 	// 计算邻居节点的实际成本值，即 g(n)
            if next not in cost_so_far or new_cost < cost_so_far[next]:		// 如果为访问过，或者比现有的实际成本低，则进行判断
                cost_so_far[next] = new_cost
                priority = new_cost + heuristic(goal, next)
                frontier.put(next, priority)	// 计算其权重
                came_from[next] = current		// 将实际成本和期望值的和放入 PriorityQueue 中
                
   	return came_from, cost_so_far
```

