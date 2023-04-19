#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e4 + 10;

int cnt;
int N,K;
int values[Max];
int ans[Max];
bool st[Max];
bool flag;


void dfs(int x)
{
    if(flag) return;
    if(x > N)
    {
        cnt++;
        if(cnt == K + 1)
        {
            flag = true;
            for(int i = 1; i <= N; i++)
            {
                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(cnt == 0) i = values[x];
        if(!st[i])
        {
            st[i] = true;
            ans[x] = i;
            dfs(x + 1);
            ans[x] = 0;
            st[i] = false;
        }
    }
}
int main()
{
    std::cin >> N >> K;

    for(int i = 1; i <= N; i++) scanf("%d",&values[i]);

    dfs(1);

    return 0;
}