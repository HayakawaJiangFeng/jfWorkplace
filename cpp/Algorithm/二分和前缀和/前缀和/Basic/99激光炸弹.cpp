#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 5100;

int map[Max][Max];
int my_cache[Max][Max];

int main()
{
    int n,m;
    int N,R;
    std::cin >> N >> R;
    R = std::min(5001, R);
    n = m = R;

    for(int i = 1; i <= N; i++)
    {
        int x,y,w;
        std::cin >> x >> y >> w;
        x++,y++;
        n = std::max(x,n),m = std::max(y,m);
        map[x][y] += w;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            my_cache[i][j] = my_cache[i - 1][j] + my_cache[i][j - 1] - my_cache[i - 1][j - 1] + map[i][j];          
        }
    }

    int max = 0;

    for(int i = R; i <= n; i++)
    {
        for(int j = R; j <= m; j++)
        {
            max = std::max(max, my_cache[i][j] - my_cache[i][j - R] - my_cache[i - R][j] + my_cache[i - R][j - R]);          
        }
    }
    std::cout << max << std::endl;

    return 0;
}
