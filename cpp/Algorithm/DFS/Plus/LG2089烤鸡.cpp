#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

int N;
int ans[15];
int cnt;
int res[10000][15];

void dfs(int x)
{
    if(x > 10)
    {
        int sum = 0;
        for(int i = 1; i <= 10; i++)
        {
            sum += ans[i];
        }
        if(sum == N)
        {
            cnt++;
            for(int i = 1; i <= 10; i++)
            {
                res[cnt][i] = ans[i];
            }
        }
        return;
    }
    for(int i = 1; i <= 3; i++)
    {
        ans[x] = i;
        dfs(x + 1);
        ans[x] = 0; 
    }
}
int main()
{
    std::cin >> N;
    
    dfs(1);
    std::cout << cnt << std::endl;

    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}