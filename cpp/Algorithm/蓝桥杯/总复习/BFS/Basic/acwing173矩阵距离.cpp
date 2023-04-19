#include <iostream>
#include <cstring>
#include <queue>

int N,M;
const int Max = 1005;
char map[Max][Max];
int distance[Max][Max];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

std::queue<std::pair<int, int> > q;

int main(){

    memset(distance, -1, sizeof(distance));

    std::cin >> N >> M;
    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            std::cin >> map[i][j];
            if(map[i][j] == '1'){

                q.push(std::make_pair(i,j));
                distance[i][j] = 0;
            }
        }
    }
    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(xx > 0 && xx <= N && yy > 0 && yy <= M && distance[xx][yy] < 0 && map[xx][yy] == '0'){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
    for(int i = 1; i<= N; i++){

        for(int j = 1; j <= M; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}