#include <iostream>
#include <queue>

int n,m;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int distance[1010][1010];
bool flag[1010][1010];

void bfs(){

    std::queue<std::pair<int, int> > q;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(flag[i][j]){

                q.push(std::make_pair(i,j));
            }
        }
    }
    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(xx < 1 || xx > n || yy < 1 || yy > m || distance[xx][yy] || flag[xx][yy]) continue;

            distance[xx][yy] = distance[temp.first][temp.second] + 1;
            q.push(std::make_pair(xx,yy));
        }
    }
}
int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            char ch;
            std::cin >> ch;
            flag[i][j] = ch - '0';
        }
    }

    bfs();

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}