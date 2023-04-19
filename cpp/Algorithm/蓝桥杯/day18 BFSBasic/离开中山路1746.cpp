/*
题目背景

《爱与愁的故事第三弹·shopping》最终章。

题目描述

爱与愁大神买完东西后，打算坐车离开中山路。现在爱与愁大神在 
x
1
,
y
1
x 
1
​	
 ,y 
1
​	
  处，车站在 
x
2
,
y
2
x 
2
​	
 ,y 
2
​	
  处。现在给出一个 
n
×
n
(
n
≤
1000
)
n×n(n≤1000) 的地图，
0
0 表示马路，
1
1 表示店铺（不能从店铺穿过），爱与愁大神只能垂直或水平着在马路上行进。爱与愁大神为了节省时间，他要求最短到达目的地距离（每两个相邻坐标间距离为 
1
1）。你能帮他解决吗？

输入格式

第 
1
1 行包含一个数 
n
n。

第 
2
2 行到第 
n
+
1
n+1 行：整个地图描述（
0
0 表示马路，
1
1 表示店铺，注意两个数之间没有空格）。

第 
n
+
2
n+2 行：四个数 
x
1
,
y
1
,
x
2
,
y
2
x 
1
​	
 ,y 
1
​	
 ,x 
2
​	
 ,y 
2
​	
 。

输出格式

只有 
1
1 行，即最短到达目的地距离。
*/

#include <iostream>
#include <cstring>
#include <queue>

/*
3
001
101
100
1 1 3 3
*/
int n;
int x1,y1,x2,y2;
char map[1005][1005];
int distance[1005][1005];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= n;
}

int bfs(int x, int y){

    memset(distance, -1, sizeof(distance));

    distance[x][y] = 0;

    std::pair<int, int> p(x, y);
    q.push(p);

    while (!q.empty())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(map[xx][yy] == '0' && in(xx,yy) && distance[xx][yy] < 0){

                std::pair<int, int> p1(xx, yy);
                q.push(p1);

                distance[xx][yy] = distance[temp.first][temp.second] + 1;

                if(xx == x2 && yy == y2){

                    return distance[x2][y2];
                }
            }
        }
    }
    return distance[x2][y2];
}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            std::cin >> map[i][j];
        }
    }
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << bfs(x1,y1) << std::endl;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}