#include <queue>
#include <iostream>

int n,m;
int next[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char map[105][105];
bool visit[105][105];
std::queue<std::pair<int, int> > q;


bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs(int x, int y){

    q.push(std::make_pair(x,y));
    visit[x][y] = true;

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] == 'W' && !visit[xx][yy]){

                visit[xx][yy] = true;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
}
int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(map[i][j] == 'W' && !visit[i][j]){

                res++;
                bfs(i,j);
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}