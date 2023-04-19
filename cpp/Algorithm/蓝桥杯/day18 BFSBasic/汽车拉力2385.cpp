#include <iostream>
#include <queue>

int M,N;
int x1,y1;
int map[505][505];
int values[505][505];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool st[505][505];
int cnt_1;
std::queue<std::pair<int ,int> > q;

bool in(int x, int y){

    return x > 0 && x <= M && y > 0 && y <= N;
}
bool check(int mid){

    q.push(std::make_pair(x1,y1));
    st[x1][y1] = true;
    int cnt = 1;

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(!st[xx][yy] && in(xx,yy) && abs(values[temp.first][temp.second] - values[xx][yy]) <= mid){

                st[xx][yy] = true;
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
        }
    }
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 1){

                cnt_1++;
            }
        }
    }
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            if(map[i][j] == 1){

                x1 = i;
                y1 = j;
                break;
            }
        }
    }
    
    int left = -1;
    int right = 1e9 + 10;
    while (left + 1 < right)
    {
        
        int mid = (left + right) / 2;
        q = std::queue<std::pair<int, int> >();
        memset(st, false, sizeof(st));
        if(check(mid)){

            right = mid;
        }else{

            left = mid;
        }
    }
    
    printf("%d",right);
    return 0;
}