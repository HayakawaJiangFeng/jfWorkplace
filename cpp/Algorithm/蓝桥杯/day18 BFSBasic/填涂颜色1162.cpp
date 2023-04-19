#include <iostream>
#include <queue>

int n;
int map[35][35];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int > > q;
bool st[35][35];

bool in(int x, int y){

    return x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1;
}

void bfs(int x, int y){

    st[x][y] = true;
    std::pair<int, int> p(x,y);
    q.push(p);

    while (!q.empty())
    {

        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(map[xx][yy] == 0 && in(xx,yy) && !st[xx][yy]){

                std::pair<int, int> p1(xx,yy);
                q.push(p1);
                st[xx][yy] = true;
            }
        }
    }
    
}

int main(){

    std::cin >> n;   

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            std::cin >> map[i][j];
        }
    }

    bfs(0,0);
    
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            if(map[i][j] == 0 && !st[i][j]){

                map[i][j] = 2;
            }
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}