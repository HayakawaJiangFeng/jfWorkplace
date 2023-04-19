#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e6 + 10;

int N;
int res;
int ans[Max];
bool st[10];

// n = a + b / c 可以改写为 cn = ac + b
//abc三个位置，枚举每个位置放的数的个数,最少为1个

int calc(int left, int right)
{
    int sum = 0;
    for(int i = left; i <= right; i++)
    {
        sum = sum * 10 + ans[i];
    }
    return sum;
}
void dfs(int x)
{
    if(x > 9)
    {
        for(int i = 1; i <= 9; i++)
        {
            for(int j = i + 1; j <= 9; j++)
            {
                int a = calc(1,i);
                int b = calc(i + 1,j);
                int c = calc(j + 1,9);
                if(N * c == a * c + b) res++;
            }
        }
        return;
    }
    for(int i = 1; i <= 9; i++)
    {
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
    std::cin >> N;   

    //1~9都只能用一次，全排列列出所有可能
    dfs(1);

    std::cout << res << std::endl;

    return 0;
}