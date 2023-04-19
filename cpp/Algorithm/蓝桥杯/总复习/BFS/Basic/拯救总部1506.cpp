#include <iostream>
#include <queue>

int n,m;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[505][505];
int visit[505][505];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}

void bfs(int x,int y){

    q.push(std::make_pair(x,y));
    visit[x][y] = 1;

    while (q.size())
    {

        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != '*' && !visit[xx][yy]){

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
    bfs(0,0);
    int res = 0;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(visit[i][j] == 0 && map[i][j] == '0'){

                res++;
            }
        }
    }
    /*for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            std::cout << visit[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    std::cout << res << std::endl;
    return 0;
}