#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

const int Max = 1e3 + 10;

int N;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[Max][Max];
bool st[Max][Max];
bool st1[Max][Max];
std::queue<std::pair<int, int> > q;

bool is_line(int x, int y){

    for(int i = 0; i < 4; i++)
    {
        int xx = x + next[i][0];
        int yy = y + next[i][1];
        
        if(map[xx][yy] == '.') return true;
    }
    return false;
}
bool in(int xx, int yy)
{
    return xx > 0 && xx <= N && yy > 0 && yy <= N;
}
void bfs(int x, int y)
{
    st[x][y] = true;
    q.push(std::make_pair(x,y));

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx, yy) && map[xx][yy] == '#' && !st[xx][yy])
            {
                st[xx][yy] = true;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
}
int main(){

    int cnt1 = 0;
    int cnt2 = 0;

    std::cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(!st[i][j] && map[i][j] == '#')
            {
                cnt1++;
                bfs(i,j);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] == '#' && is_line(i,j))
            {
                st1[i][j] = true;
            }
        }
    }
    
    memset(st,false,sizeof(st));
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(!st[i][j] && map[i][j] == '#' && !st1[i][j])
            {
                cnt2++;
                bfs(i,j);
            }
        }
    }
    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    //std::cout << cnt1 << std::endl;
    //std::cout << cnt2 << std::endl;
    std::cout << cnt1 - cnt2 << std::endl;
    return 0;
}