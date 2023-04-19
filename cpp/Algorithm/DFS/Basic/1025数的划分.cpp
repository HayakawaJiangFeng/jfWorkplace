#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

int n,k;
int res;
int ans[8];

void dfs(int x, int start)
{
    if(x > k)
    {
        int sum = 0;
        for(int i = 1; i <= k; i++)
        {
            sum += ans[i];
        }
        if(sum == n)
        {
            res++;
        }
        return;
    }
    for(int i = start; i <= n; i++)
    {
        ans[x] = i;
        dfs(x + 1, i);
        ans[x] = 0;
    }
}
int main()
{
    std::cin >> n >> k;

    dfs(1,1);
    std::cout << res << std::endl;

    return 0;
}