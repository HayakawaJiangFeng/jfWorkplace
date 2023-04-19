#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 15;

int dp[Max][Max];
int m,n;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> m >> n;
        dp[0][0] = 1;

        for(int i = 0; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if(i >= j) dp[i][j] += dp[i - j][j];
            }
        }
        std::cout << dp[m][n] << std::endl;
    }
    return 0;
}