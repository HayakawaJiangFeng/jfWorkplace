#include <iostream>

const int Max = 15;

int n;
int ans[Max];
bool st[Max];

void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++) std::cout << ans[i] << " ";
        std::cout << std::endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            ans[x] = i;
            st[i]  = true;
            dfs(x + 1);
            st[i]  = false;
            ans[x] = 0;
        }
    }
}
int main()
{
    std::cin >> n;

    dfs(1);

    return 0;
}