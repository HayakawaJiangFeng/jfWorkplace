#include <cstdio>
#include <cstring>  
#include <iostream>
#include <algorithm>

int cnt;
int M,N;
int ans[15];

void dfs(int x, int start)
{
    if(x > N)
    {
        int sum = 0;
        for(int i = 1; i <= N; i++) sum += ans[i];
        if(sum == M) cnt++;
        return;
    }
    for(int i = start; i <= M; i++)
    {
        ans[x] = i;
        dfs(x + 1, i);
        ans[x] = 0;
    }
}

int main()
{

    int n;
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> M >> N;

        cnt = 0;

        dfs(1,0);

        std::cout << cnt << std::endl;
    }
    
    return 0;
}