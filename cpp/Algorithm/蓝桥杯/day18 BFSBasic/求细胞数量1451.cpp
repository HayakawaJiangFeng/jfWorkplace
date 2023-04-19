#include <iostream>
#include <queue>

int n,m;
int res;
bool visit[105][105];
char map[105][105];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs(int x, int y){

    visit[x][y] = true;
    std::pair<int, int> p(x,y);
    q.push(p);

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != '0' && !visit[xx][yy]){

                visit[xx][yy] = true;
                std::pair<int, int> p1(xx,yy);
                q.push(p1);
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

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(!visit[i][j] && map[i][j] != '0'){

                bfs(i,j);
                res++;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}