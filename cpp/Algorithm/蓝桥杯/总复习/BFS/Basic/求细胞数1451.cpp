#include <iostream>
#include <queue>

int n,m;
char map[105][105];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
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

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && !visit[xx][yy] && map[xx][yy] != '0'){

                visit[xx][yy] = visit[temp.first][temp.second];
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

            if(!visit[i][j] && map[i][j] != '0'){

                res++;
                bfs(i,j);
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}