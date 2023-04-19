#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

int N;
int res;
int value[1000] = {6,2,5,5,4,5,6,3,7,6};
int ans[4];

void dfs(int x,int cnt)
{
    if(cnt > N - 4) return;
    if(x == 3)
    {
        if(ans[0] + ans[1] == ans[2] && cnt == N - 4) res++;
        return;
    }
    for(int i = 0; i < 1000; i++)
    {
        ans[x] = i;
        dfs(x + 1, cnt + value[i]);
        ans[x] = 0;
    }
}
int main()
{
    std::cin >> N;
    for(int i = 10; i < 1000; i++)
    {
        value[i] = value[i / 10] + value[i % 10];
    }
    dfs(0,0);

    std::cout << res << std::endl;

    return 0;
}
