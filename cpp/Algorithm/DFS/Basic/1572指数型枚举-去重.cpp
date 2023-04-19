#include <iostream>
#include <algorithm>

const int Max = 20;

int n;
int values[Max];
bool st[Max];

void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i]) std::cout << values[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    st[x] = true;
    dfs(x + 1);
    st[x] = false;

    if(st[x - 1] && values[x] == values[x - 1]) return;

    st[x] = false;
    dfs(x + 1);
    st[x] = false;
}
int main()
{
    std::cin >> n;

    for(int i = 1; i <= n; i++) std::cin >> values[i];

    //去重记得要排序
    std::sort(values + 1, values + n + 1);
    dfs(1);

    return 0;
}