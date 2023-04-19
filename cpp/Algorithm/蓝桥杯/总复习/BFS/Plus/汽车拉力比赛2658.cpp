#include <iostream>
#include <cstring>
#include <queue>

int M,N; //M * N 的矩阵
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};    //四联通
int values[505][505]; //海拔数组
int map[505][505];    //地图数组
bool visit[505][505];
int cnt; //统计路标数量
int sx,sy; //随便找一个路标的坐标作为开始的坐标
int highest; //找一个最高的海拔
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx > 0 && xx <= M && yy > 0 && yy <= N;
}
bool bfs(int mid){

    int flag = 1;
    visit[sx][sy] = true;
    q.push(std::make_pair(sx,sy));

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp .second + next[i][1];

            if(in(xx,yy) && !visit[xx][yy] && abs(values[xx][yy] - values[temp.first][temp.second]) <= mid){

                visit[xx][yy] = true;
                q.push(std::make_pair(xx,yy));

                if(map[xx][yy] == 1){

                    flag++;
                }
                if(flag == cnt){

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
            highest = std::max(values[i][j], highest); //获取最高的海拔
        }
    }
    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 1){
                
                cnt++;  //统计路标数量
                sx = i;
                sy = j;
            }
        }
    }
    
    //二分找到最大值最小,左可以到0，右可以到highest
    int left = -1;
    int right = highest + 1;

    while (left + 1 < right)
    {
         int mid = (left + right) / 2;
         //!!!!记得清空队列和重置visit数组
         q = std::queue<std::pair<int, int> >();
         memset(visit, false, sizeof(visit));

         if(bfs(mid)){

            right = mid;
         }else{

            left = mid;
         }
    }
    if(bfs(left)){

        std::cout << left << std::endl;
    }else{

        std::cout << right << std::endl;
    }

    return 0;
}