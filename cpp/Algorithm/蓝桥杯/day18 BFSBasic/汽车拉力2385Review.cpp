#include <iostream>
#include <queue>
#include <cstring>

int M,N;
int cnt_1;
int highest;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int values[505][505];
int map[505][505];
int sx,sy;
bool visit[505][505];
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx > 0 && xx <= M && yy > 0 && yy <= N;
}
bool bfs(int mid){

    q.push(std::make_pair(sx,sy));
    visit[sx][sy] = true;
    int cnt = 1;

    while(!q.empty()){

        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(!visit[xx][yy] && in(xx,yy) && abs(values[temp.first][temp.second] - values[xx][yy]) <= mid){

                visit[xx][yy] = true;
                q.push(std::make_pair(xx,yy));

                if(map[xx][yy] == 1){
                    
                    cnt++;
                }
                if(cnt == cnt_1){

                    return true;
                }
            }
        }
    }
    return false;
}
int main(){

    std::cin >> M >> N;
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> values[i][j];
            highest = std::max(highest,values[i][j]);
        }
    }
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 1){
            
                cnt_1++;
                sx = i;
                sy = j;
            }
        }
    }
    int left = -1;
    int right = highest + 1;

    while(left + 1 < right){

        int mid = (left + right) / 2;
        q = std::queue<std::pair<int, int> >();
        memset(visit, false, sizeof(visit));

        if(bfs(mid)){

            right = mid;
        }else{

            left = mid;
        }
    }

    std::cout << right << std::endl;

    return 0;
}