#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 210;

int res = 1e9;
int N,A,B;
int values[Max];
bool st[Max];

void dfs(int x, int cnt)
{
    if(cnt >= res) return;
    if(x == B && cnt < res)
    {
        res = cnt;
        return;
    }
    if(x + values[x] <= N && !st[x + values[x]])
    {
        st[x + values[x]] = true;
        dfs(x + values[x], cnt + 1);
        st[x + values[x]] = false;
    }
    if(x - values[x] >= 1 && !st[x - values[x]])
    {
        st[x - values[x]] = true;
        dfs(x - values[x], cnt + 1);
        st[x - values[x]] = false; 
    }
}
int main()
{
    std::cin >> N >> A >> B;

    for(int i = 1; i <= N ;i++)
    {
        std::cin >> values[i];
    }
    dfs(A,0);

    if(res == 1e9) std::cout << "-1" << std::endl;
    else std::cout << res << std::endl;
    return 0;
}