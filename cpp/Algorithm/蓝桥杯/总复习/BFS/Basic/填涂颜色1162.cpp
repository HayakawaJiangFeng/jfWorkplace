#include <iostream>
#include <queue>

int n;
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int map[35][35];
bool visit[35][35];
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx >= 0 && xx <= n + 1 && yy >= 0 && yy <= n + 1;
}
void bfs(int x, int y){

    q.push(std::make_pair(x,y));
    visit[x][y] = true;

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] == 0 && !visit[xx][yy]){

                visit[xx][yy] = true;
                q.push(std::make_pair(xx,yy));
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

            if(map[i][j] == 0 && !visit[i][j]){

                map[i][j] = 2;
            }
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
