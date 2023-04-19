/*
题目描述
贝茜听说一场特别的流星雨即将到来：这些流星会撞向地球，并摧毁它们所撞击的任何东西。她为自己的安全感到焦虑，发誓要找到一个安全的地方（一个永远不会被流星摧毁的地方）。

如果将牧场放入一个直角坐标系中，贝茜现在的位置是原点，并且，贝茜不能踏上一块被流星砸过的土地。

根据预报，一共有 
M
M 颗流星 
(
1
≤
M
≤
50
,
000
)
(1≤M≤50,000) 会坠落在农场上，其中第 
i
i 颗流星会在时刻 
T
i
T 
i
​	
  砸在坐标为 
(
X
i
,
Y
i
)
(
0
≤
X
i
≤
300
(X 
i
​	
 ,Y 
i
​	
 )(0≤X 
i
​	
 ≤300，
0
≤
Y
i
≤
300
)
0≤Y 
i
​	
 ≤300) 的格子里。流星的力量会将它所在的格子，以及周围 
4
4 个相邻的格子都化为焦土，当然贝茜也无法再在这些格子上行走。

贝茜在时刻 
0
0 开始行动，它只能在第一象限中，平行于坐标轴行动，每 
1
1 个时刻中，她能移动到相邻的（一般是 
4
4 个）格子中的任意一个，当然目标格子要没有被烧焦才行。如果一个格子在时刻 
t
t 被流星撞击或烧焦，那么贝茜只能在 
t
t 之前的时刻在这个格子里出现。 贝西一开始在 
(
0
,
0
)
(0,0)。

请你计算一下，贝茜最少需要多少时间才能到达一个安全的格子。如果不可能到达输出 
−
1
−1。

输入格式
共 
M
+
1
M+1 行，第 
1
1 行输入一个整数 
M
M，接下来的 
M
M 行每行输入三个整数分别为 
X
i
,
Y
i
,
T
i
X 
i
​	
 ,Y 
i
​	
 ,T 
i
​	
 。

输出格式
贝西到达安全地点所需的最短时间，如果不可能，则为 
−
1
−1。
*/
#include <iostream>
#include <queue>
#include <cstring>

int M;
int map[305][305];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int distance[305][305];

std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x <= 301 && y >= 0 && y <= 301;
}

bool peopleIn(int x, int y){

    return x >= 0 && y >= 0;
}


int bfs(int x, int y){

    memset(distance , -1 , sizeof(distance));
    distance[x][y] = 0;
    std::pair<int, int> p(x,y);
    q.push(p);

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(peopleIn(xx,yy) && distance[xx][yy] < 0 && distance[temp.first][temp.second] + 1 < map[xx][yy]){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                std::pair<int, int> p1(xx,yy);
                q.push(p1);

                if(map[xx][yy] > 1e9){

                    return distance[xx][yy];
                }
            }
        }
    }
    return -1;
}
int main(){

    std::cin >> M;
    
    memset(map, 0x3f, sizeof(map));

    for(int i = 1; i <= M; i++){

        int xi,yi,ti;
        std::cin >> xi >> yi >> ti;
        map[xi][yi] = std::min(ti,map[xi][yi]);
        for(int i = 0; i < 4; i++){

            int xx = xi + next[i][0];
            int yy = yi + next[i][1];
            if(in(xx,yy)){

                map[xx][yy] = std::min(ti, map[xx][yy]);
            }
        }
    }

    std::cout << bfs(0,0) << std::endl;

    return 0;
}