#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e6 * 5 + 10;

int res;
int N,K;
int ans[Max];
int values[Max];

bool is_prime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i < x / i; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int x, int start)
{
    if(x > K)
    {
        int sum = 0;
        for(int i = 1; i <= K; i++)
        {
            sum += ans[i];
        }
        if(is_prime(sum)) res++;
        return;
    }
    for(int i = start; i <= N; i++)
    {
        ans[x] = values[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}

int main()
{
    std::cin >> N >> K;
    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    dfs(1,1);

    std::cout << res << std::endl;
    return 0;
}