#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int Max = 1e3 + 10;

int dp[Max][Max];
int v[Max];
int w[Max];
int N,V;

int main()
{
    std::cin >> N >> V;
    
    for(int i = 1; i <= N; i++)
    {
        std::cin >> v[i] >> w[i];
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            for(int k = 0; k * v[i] <= j; k++)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v[i] * k] + w[i] * k);
            }
        }
    }
    std::cout << dp[N][V] << std::endl;

    return 0;
}