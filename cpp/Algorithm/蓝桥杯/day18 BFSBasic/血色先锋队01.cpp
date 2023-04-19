#include <iostream>
#include <cstring>
#include <queue>

int n,m,a,b;
int distance[505][505];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;
std::pair<int, int> as[100005];
std::pair<int, int> bs[100005];

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

                std::pair<int, int> p(xx,yy);
                q.push(p);
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
            }
        }
    }
    
}
int main(){

    memset(distance, -1, sizeof(distance));

    std::cin >> n >> m >> a >> b;

    for(int i = 0; i < a; i++){

        int x,y;
        std::cin >> x >> y;
        distance[x][y] = 0;
        std::pair<int, int> temp(x,y);
        as[i] = temp;
        q.push(as[i]);
    }
    
    bfs();

    for(int i = 0; i < b; i++){

        int x,y;
        std::cin >> x >> y;
        std::cout << distance[x][y] << std::endl;
    }
    
    return 0;
}

/*
5 4 2 3
1 1
5 4
3 3
5 3
2 4
*/