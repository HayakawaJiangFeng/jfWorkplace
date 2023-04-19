#include <iostream>
#include <queue>
#include <cstring>

int n,m,a,b;
int distance[505][505];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs(){

    while (!q.empty())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
}
int main(){

    memset(distance, -1, sizeof(distance));

    std::cin >> n >> m >> a >> b;

    for(int i = 1; i <= a; i++){

        int x,y;
        std::cin >> x >> y;
        distance[x][y] = 0;
        q.push(std::make_pair(x,y));
    }

    bfs();

    for(int i = 1; i <= b; i++){

        int x,y;
        std::cin >> x >> y;
        std::cout << distance[x][y] << std::endl;
    }
    
    return 0;
}