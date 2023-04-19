#include <iostream>
#include <queue>

int R,C;
int res;
int next[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
bool visit[1005][1005];
char map[1005][1005];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= R && y > 0 && y <= C;
}
bool judge(int x, int y){

    int cnt = 0;
    if(map[x][y] == '#')cnt++;
    if(map[x+1][y] == '#')cnt++;
    if(map[x][y+1] == '#')cnt++;
    if(map[x+1][y+1] == '#')cnt++;

    if(cnt == 3) return true;
    return false;
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

            if(in(xx,yy) && map[xx][yy] == '#'){

                q.push(std::make_pair(xx,yy));
                visit[xx][yy] = true;
            }
        }
    }
    
}
int main(){

    std::cin >> R >> C;
    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            std::cin >> map[i][j];
        }
    }
    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            if(judge(i,j)){

                std::cout << "Bad placement." << std::endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            if(!visit[i][j] && map[i][j] == '#'){

                res++;
                bfs(i,j);
            }
        }
    }

    std::cout << "There are " << res << " ships." << std::endl;

    return 0;
}