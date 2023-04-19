#include <iostream>
#include <algorithm>

const int Max = 15;

int n;
int values[Max];
int ans[Max];
bool st[Max];

void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i])   std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            if(st[i - 1] && values[i - 1] == values[i]) continue;
            st[i] = true;
            ans[x] = values[i];
            dfs(x + 1);
            st[i] = false;
            ans[x] = 0;
        }   
    }
}
int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> values[i];

    std::sort(values + 1, values + n + 1);
    dfs(1);

    return 0;
}