#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1e3 + 10;

int v[Max];
int w[Max];
int dp[Max][Max];

int N,V;
int main()
{
    std::cin >> N >> V;

    for(int i = 1;i <= N; i++)
    {
        std::cin >> v[i] >> w[i];
    }

    dp[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            if(j < v[i]) dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    std::cout << dp[N][V] << std::endl;
    return 0;
}