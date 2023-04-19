#include <iostream>
#include <cstring>
#include <queue>

int n,m,a,b;
int distance[505][505];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx > 0 && xx <= n && yy > 0 && yy <= m;
}
void bfs(){

    while (q.size())
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
        distance[x][y] = 0; //记得赋值前要把distance初始化
        q.push(std::make_pair(x,y));
    }

    bfs();

    /*for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){
            
            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    for(int i = 1; i <= b; i++){

        int x,y;
        std::cin >> x >> y;
        std::cout << distance[x][y] << std::endl; 
    }

    return 0;
}