#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 15;
int acid[Max];
int bitter[Max];
int res;
int n;
bool st[Max];
bool flag;

void dfs(int x)
{
    if(x > n)
    {
        int acids = 1;
        int bitters = 0;
        for(int i = 1; i <= n; i++)
        {
            if(st[i])
            {
                acids *= acid[i];
                bitters += bitter[i];
                res = std::min(res,abs(acids - bitters));
            }
        }
        return;
    }
    //不选
    dfs(x + 1);

    //选
    st[x] = true;
    dfs(x + 1);
    st[x] = false;
}
int main()
{
    res = 1e8;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> acid[i] >> bitter[i];
    }

    dfs(1);

    std::cout << res << std::endl;

    return 0;
}