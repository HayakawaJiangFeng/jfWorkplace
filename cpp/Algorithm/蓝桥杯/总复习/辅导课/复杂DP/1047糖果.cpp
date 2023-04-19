#include <iostream>
#include <cstring>
#include <cstdio>   
#include <algorithm>
#include <cmath>

const int Max = 1e2 + 10;

int N,K;
int dp[Max][Max];

int main()
{
    std::cin >> N >> K;

    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        int w;
        std::cin >> w;
        for(int j = 0; j < K; j++)
        {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][((j + K - w % K)) % K] + w);
        }
    }
    std::cout << dp[N][0] << std::endl;

    return 0;
}