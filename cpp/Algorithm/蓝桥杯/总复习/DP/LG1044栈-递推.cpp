#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 20;


int n;
int dp[Max][Max];

int main()
{
    std::cin >> n;

    for(int i = 0; i <= n; i++) dp[0][i] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(i == j) dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    std::cout << dp[n][n] << std::endl;

    return 0;
}