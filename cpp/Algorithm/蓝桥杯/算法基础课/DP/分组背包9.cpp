#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 110;

int N,V;
int g[Max];
int v[Max][Max];
int w[Max][Max];
int dp[Max][Max];

int main()
{
    std::cin >> N >> V;

    for(int i = 1; i <= N; i++)
    {
        std::cin >> g[i];
        for(int j = 1; j <= g[i]; j++) std::cin >> v[i][j] >> w[i][j];
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for(int k = 1; k <= g[i]; k++)
            {
                if(v[i][k] <= j)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    std::cout << dp[N][V] << std::endl;
    return 0;
}