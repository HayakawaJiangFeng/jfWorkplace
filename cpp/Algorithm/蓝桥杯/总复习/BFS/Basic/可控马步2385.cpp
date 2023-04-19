#include <iostream>
#include <cstring>
#include <queue>

int main(){

    int map[35][35];
    int distance[35][35];

    memset(distance, -1, sizeof(distance));

    int M,N,M1,M2;

    std::cin >> M >> N >> M1 >> M2;
    std::queue<std::pair<int, int> > q;

    int next[8][2] = {{M1,M2},{-M1,-M2},{M1,-M2},{-M1,M2},{M2,M1},{-M2,-M1},{M2,-M1},{-M2,M1}};

    int sx,sy;
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 2){

                map[i][j] = 0;
            }
            if(map[i][j] == 3){

                sx = i;
                sy = j;
            }
        }
    }
    q.push(std::make_pair(sx,sy));

    distance[sx][sy] = 0;

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(xx > 0 && xx <= M && yy > 0 && yy <= N && distance[xx][yy] < 0 && map[xx][yy] != 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
                if(map[xx][yy] == 4){

                    std::cout << distance[xx][yy] << std::endl;
                    return 0;
                }
            } 
        }
    }
    
    return 0;
}