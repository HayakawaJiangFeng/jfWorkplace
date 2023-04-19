/*
题目描述

军团是一个 
n
n 行 
m
m 列的矩阵，每个单元是一个血色先锋军的成员。感染瘟疫的人，每过一个小时，就会向四周扩散瘟疫，直到所有人全部感染上瘟疫。你已经掌握了感染源的位置，任务是算出血色先锋军的领主们感染瘟疫的时间，并且将它报告给巫妖王，以便对血色先锋军进行一轮有针对性的围剿。

输入格式

第 
1
1 行：四个整数 
n
n，
m
m，
a
a，
b
b，表示军团矩阵有 
n
n 行 
m
m 列。有 
a
a 个感染源，
b
b 为血色敢死队中领主的数量。

接下来 
a
a 行：每行有两个整数 
x
x，
y
y，表示感染源在第 
x
x 行第 
y
y 列。

接下来 
b
b 行：每行有两个整数 
x
x，
y
y，表示领主的位置在第 
x
x 行第 
y
y 列。

输出格式

第 
1
1 至 
b
b 行：每行一个整数，表示这个领主感染瘟疫的时间，输出顺序与输入顺序一致。如果某个人的位置在感染源，那么他感染瘟疫的时间为 
0
0。
*/

#include <iostream>
#include <queue>
#include <cstring>

int n,m,a,b;

int as[100000][2];
int bs[100000][2];
int distance[505][505];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <=n && y > 0 && y <= m;
}

void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
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

            if(in(xx, yy) && distance[xx][yy] < 0){

                std::pair<int ,int> p1(xx,yy);
                q.push(p1);
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
            }
        }
    }
}

int main(){

    std::cin >> n >> m >> a >> b;

    for(int i = 0 ; i < a; i++){

        std::cin >> as[i][0] >> as[i][1];
    }

    for(int j = 0; j < b; j++){

        std::cin >> bs[j][0] >> bs[j][1];
    }

    bfs(5,4);
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}