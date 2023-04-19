#include <iostream>
#include <queue>

int x1,y1,x2,y2;
int next[12][2] = {{-2,-2},{-2,2},{-2,-1},{-2,1},{-1,-2},{-1,2},{2,2},{2,-2},{2,1},{2,-1},{1,-2},{1,2}};
int distance[100][100];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= 100 && y > 0 && y <= 100;
}
int bfs(int x, int y){

    memset(distance, -1, sizeof(distance));

    distance[x][y] = 0;
    q.push(std::make_pair(x,y));

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 12; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                q.push(std::make_pair(xx,yy));
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                if(xx == 1 && yy == 1){

                    return distance[1][1];
                }
            }
        }
    }
    return distance[1][1];
}

int main(){

    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << bfs(x1,y1) << std::endl;

    while (!q.empty())
    {
        q.pop();
    }
    
    std::cout << bfs(x2,y2) << std::endl;

    return 0;
}