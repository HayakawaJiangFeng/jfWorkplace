#BFS 35道题

### BFS 广度优先搜索 ( Breadth-First-Search )

广度优先搜索算法(Breadth First Search)，又称为"宽度优先搜索",  BFS是用于图的查找算法(要求能用图表示出问题的关联性)。

#### BFS可用于解决2类问题：

1.从A出发是否存在到达B的路径；DFS也可求

2.从A出发到达B的**最短**路径；数据小20以内的话, DFS也不是不可以 **题眼**

#### 整体思路

其思路为从图上一个节点出发，访问先访问其直接相连的子节点，若子节点不符合，再问其子节点的子节点，按级别顺序(一层一层)依次访问，直到访问到目标节点。



#### 步骤

- 起始：将起点（源点，树的根节点）放入队列中
- 扩散：从队列中取出**队头的结点**，将它的相邻结点放入队列，不断重复这一步
- 终止：当**队列为空**时，说明我们遍历了所有的能到的结点，整个图能到的点都被搜索了一遍









#### 时空复杂度

**时间复杂度** : 最差情形下，BFS必须寻找所有到可能节点的所有路径，因此其时间复杂度为O(|V| + |E|)，其中|V|是节点的数目，而|E|是图中边的数目。

**空间复杂度** : BFS的空间复杂度为 O(B^h)，其中B是最大分支系数，而h是树的最长路径长度(树的高度) 。由于对空间的大量需求，因此BFS并不适合解非常大的问题。



对于**所有边长度相同**的情况，比如地图的模型，bfs第一次遇到目标点，此时就一定是从根节点到目标节点**最短**的路径（因为每一次所有点都是向外扩张一步，你先遇到，那你就一定最短）。bfs**先**找到的一定是**最短**的。但是如果是**加权边**的话这样就会出问题了，bfs传回的是经过**边数**最少的解，但是因为加权了，这个解到根节点的距离不一定最短。比如1000+1000是只有两段，1+1+1+1有4段，由于**bfs返回的经过边数最少的解**，这里会返回总长度2000的那个解，显然不是距离最短的路径。此时我们就应该采用**Dijkstra**最短路算法解决**加权路径的最短路**了。

SPFA

### 例题

[acw844. 走迷宫](https://www.acwing.com/problem/content/846/)   , 若打不开这个题就看这个 [P1746 离开中山路](https://www.luogu.com.cn/problem/P1746) 

 

------

------



### 习题课

##### 热身 - 简单迷宫问题

[P1746 离开中山路](https://www.luogu.com.cn/problem/P1746)  1

[P1443 马的遍历](https://www.luogu.com.cn/problem/P1443)  1

--------------[P1747 好奇怪的游戏](https://www.luogu.com.cn/problem/P1747) (跑2次) 0

--------------[P2385 Bronze Lilypad Pond B](https://www.luogu.com.cn/problem/P2385) 可控马步

##### 多源BFS

[P1332 血色先锋队](https://www.luogu.com.cn/problem/P1332)  1

--------------------[acw173.矩阵距离](https://www.acwing.com/problem/content/175/)  0



##### 染色问题

[P1162 填涂颜色](https://www.luogu.com.cn/problem/P1162)9 1

-----------------------[P1506 拯救oibh总部](https://www.luogu.com.cn/problem/P1506) 

-----------------------[CF1059B Forgery](https://www.luogu.com.cn/problem/CF1059B) 



##### 有外界干扰的迷宫问题

[P2895 Meteor Shower S](https://www.luogu.com.cn/problem/P2895) 天降陨石 1

--------------------[P3395 路障](https://www.luogu.com.cn/problem/P3395) 天降路障 0.5



##### 看起来比较困难的BFS

[P2658 汽车拉力比赛](https://www.luogu.com.cn/problem/P2658) 1

--------------[P1126 机器人搬重物](https://www.luogu.com.cn/problem/P1126) 

[P2730 魔板 Magic Squares](https://www.luogu.com.cn/problem/P2730) 



##### 双端队列广搜 

[P4554 小明的游戏](https://www.luogu.com.cn/problem/P4554) 1

--------------------------[P3596 棋盘](https://www.luogu.com.cn/problem/P3956) 

--------------------------[P4667 Switch the Lamp On](https://www.luogu.com.cn/problem/P4667) 



##### 双向广搜

[P1746 离开中山路](https://www.luogu.com.cn/problem/P1746) 1

[P1379 八数码难题](https://www.luogu.com.cn/problem/P1379)  1

------------[acw1101.献给阿尔吉侬的花束](https://www.acwing.com/problem/content/description/1103/?utm_source=wechat_session&utm_medium=social&utm_oi=1237383479098585088) 

------------[UVA439 骑士的移动](https://www.luogu.com.cn/problem/UVA439) 

------------[P1135 奇怪的电梯](https://www.luogu.com.cn/problem/P1135) 

------------[P1032 字串变换](https://www.luogu.com.cn/problem/P1032) 

------------[P1825 Corn Maze S](https://www.luogu.com.cn/problem/P1825) 

------------more and more...知道起点和终点状态的都可以用双向BFS来优化时间



------





#### 作业 (上节课DFS过不去, 这节课可以用BFS试一试~)

[P1135 奇怪的电梯](https://www.luogu.com.cn/problem/P1135)  dfs暴力过不去

**Flood fill** --- **找连通块**

[P1596 Lake Counting S](https://www.luogu.com.cn/problem/P1596) 

[P1451求细胞数量](https://www.luogu.com.cn/problem/P1451) 

[P1331 海战](https://www.luogu.com.cn/problem/P1331) 

[P1767 家族](https://www.luogu.com.cn/problem/P1767) 

[SP15436 UCV2013H - Slick](https://www.luogu.com.cn/problem/SP15436) 

##### 迷宫问题

[P1683 入门](https://www.luogu.com.cn/problem/P1683) 

[P1605 迷宫](https://www.luogu.com.cn/problem/P1605) 

[P1443 马的遍历](https://www.luogu.com.cn/problem/P1443) 

[P1747 好奇怪的游戏](https://www.luogu.com.cn/problem/P1747) 

[P2298 Mzc和男家丁的游戏 ](https://www.luogu.com.cn/problem/P2298) 

















### 关于memset和0x3f

int a[100];

##### memset(a,0x3f,sizeof(a) );

0x3f=0011 1111=63
C++中**int**型变量所占的位数为**4个字节**，即32位
0x3f显然不是int型变量中单个字节的最大值，应该是0x7f=0111 1111 B
**那为什么要赋值0x3f ??**



int 



##### 1.作为无穷大使用

因为4个字节均为0x3f时，0x3f3f3f3f的十进制是1061109567，也就是10^ 9级别的（和0x7fffffff一个数量级），而一般场合下的数据都是小于10^9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。

##### 2.可以保证无穷大加无穷大仍然不会超限。

另一方面，由于一般的数据都不会大于10^9，所以当我们把无穷大加上一个数据时，它并不会溢出（这就满足了**“无穷大加一个有穷的数依然是无穷大”**），事实上0x3f3f3f3f+0x3f3f3f3f=2122219134，这非常大但却没有超过32-bit int_MAX的表示范围，所以0x3f3f3f3f**还满足了我们“无穷大加无穷大还是无穷大”的需求**。



首先要知道memset函数是**以字节为单位**进行赋值的；

**void *memset(void *s, int ch, size_t n);**

函数解释：将s中前n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
其实这里面的ch就是ascii为ch的字符；

将s所指向的某一块内存中的前n个 字节的内容全部设置为ch指定的ASCII值







