/*
4 5
00000
00*00
0*0*0
00*00

1

5 5
*****
*0*0*
**0**
*0*0*
*****

5
*/

#include <iostream>
#include <queue>

int n,m;
int cnt;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool visit[505][505];
char map[505][505];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}
void bfs(int x, int y){

    q.push(std::make_pair(x,y));
    visit[x][y] = true;

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && !visit[xx][yy] && map[xx][yy] != '*'){

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

    bfs(0,0);

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(map[i][j] == '0' && !visit[i][j]){

                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}