#include <iostream>
#include <queue>
#include <cstring>

/*
5 5

0 1 0 0 0 
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

*/
int n,m;

typedef std::pair<int, int> PII;
std::queue<PII> q;

int map[405][405];
int distance[405][405];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x >= 1 && x <= n && y > 1 && y <= m;
}

int bfs(int x1, int y1){

    memset(distance, -1, sizeof(distance));

    PII p(x1,y1);
    q.push(p);

    distance[x1][y1] = 0;

    while (!q.empty())
    {
        PII temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != 1 && distance[xx][yy] < 0){

                PII p1(xx,yy);
                q.push(p1);
                distance[xx][yy] = distance[temp.first][temp.second] + 1;

                if(xx == n && yy == m){

                    return distance[n][m];
                }
            }
        }
    }
    return distance[n][m];
}
int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }

    std::cout << bfs(1,1) << std::endl;

    return 0;
}