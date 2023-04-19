#include <iostream>
#include <queue>

int n,m,x,y;
int distance[405][405];
int next[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    q.push(std::make_pair(x,y));
    distance[x][y] = 0;

    while (!q.empty())
    {
    
        std::pair<int, int> temp = q.front();
        q.pop();
        
        for(int i = 0; i < 8; i++){

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

    std::cin >> n >> m;
    std::cin >> x >> y;

    bfs(x,y);

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}