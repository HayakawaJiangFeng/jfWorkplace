#include<algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 110;

int v[Max];
int w[Max];
int n[Max];
int dp[Max][Max];
int N,V;

int main()
{
    std::cin >> N >> V;
    for(int i = 1; i <= N; i++) std::cin >> v[i] >> w[i] >> n[i];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            for(int k = 0; k <= n[i] && k * v[i] <= j; k++)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    std::cout << dp[N][V] << std::endl;

    return 0;
}
