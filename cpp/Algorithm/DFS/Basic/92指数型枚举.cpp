#include <iostream>

int n;
bool st[20];

void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i]) std::cout << i << " ";
        }
        std::cout << std::endl;
        return;
    }

    //在这个递归深度中不选
    st[x] = false;
    //进入下一个递归深度
    dfs(x + 1);
    //还原到本来的状态
    st[x] = false;

    //在这个递归深度中选
    st[x] = true;
    dfs(x + 1);
    st[x] = false;
}
int main()
{
    std::cin >> n;

    dfs(1);

    return 0;
}