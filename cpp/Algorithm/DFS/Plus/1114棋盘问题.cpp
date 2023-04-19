#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 10;

int n,k;
int res;
char map[Max][Max];
bool st[Max];

void dfs(int x, int cnt)
{
    if(cnt == k)
    {
        res++;
        return;
    }
    if(x > n) return;
    
    for(int i = 1; i <= n; i++)
    {
        if(!st[x] && map[x][i] == '#')
        {
            st[x] = true;
            dfs(x + 1, cnt + 1);
            st[x] = false;
        }
    }
}
int main()
{
    while (std::cin >> n >> k, n != -1 && k != -1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                std::cin >> map[i][j];
            }
        }
        res = 0;
        dfs(1,0);
        std::cout << res << std::endl;
    }
    return 0;
}