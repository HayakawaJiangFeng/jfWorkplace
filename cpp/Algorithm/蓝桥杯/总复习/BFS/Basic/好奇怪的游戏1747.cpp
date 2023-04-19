#include <iostream>
#include <cstring>
#include <queue>

std::queue<std::pair<int, int> > q;
int distance[1005][1005];
int next[12][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-2,-2},{-2,2},{2,-2},{2,2}};

bool in(int xx, int yy){

    return xx > 0 && xx <= 1005 && yy > 0 && yy <= 1005;
}
int bfs(int x, int y){

    memset(distance, -1, sizeof(distance));

    q.push(std::make_pair(x,y));

    distance[x][y] = 0;
    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 12; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
                if(xx == 1 && yy == 1){

                    return distance[1][1];
                }
            }
        }
    }
    return -1;
}
int main(){

    int x1,y1,x2,y2;

    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << bfs(x1,y1) << std::endl;
    q = std::queue<std::pair<int, int> >();
    std::cout << bfs(x2,y2) << std::endl;

    return 0;
}