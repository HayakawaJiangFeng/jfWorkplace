#include <iostream>
#include <vector>

const int Max = 20;

int n;
bool st[Max];
std::vector<std::vector<int> > v;

void dfs(int x)
{
    if(x > n)
    {
        std::vector<int> temp;
        for(int i = 1; i <= n; i++)
        {
            if(st[i] == true) temp.push_back(i);
        }
        v.push_back(temp);
        return;
    }

    st[x] = false;
    dfs(x + 1);
    st[x] = false;

    st[x] = true;
    dfs(x + 1);
    st[x] = false;
}
int main()
{
    std::cin >> n;

    dfs(1);

    //vector的坐标要从0开始
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++) std::cout << v[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}