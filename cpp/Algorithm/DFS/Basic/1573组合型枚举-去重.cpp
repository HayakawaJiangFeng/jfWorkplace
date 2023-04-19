#include <iostream>
#include <algorithm>

const int Max = 30;

int n,k;
int values[Max];
int ans[Max];

void dfs(int x, int start)
{
    if(x > k)
    {
        for(int i = 1; i <= k; i++) std::cout << ans[i] << " ";
        std::cout << std::endl;
        return;
    }
    for(int i = start; i <= n; i++)
    {
        if(values[i] == values[i - 1] && i != start) continue;
        ans[x] = values[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main()
{
    std::cin >> n >> k;
    
    for(int i = 1; i <= n; i++) std::cin >> values[i];
    std::sort(values + 1, values + n + 1);

    dfs(1,1);

    return 0;
}