#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e3 + 10;

int map[Max][Max];
int my_cache[Max][Max];

int main()
{
    int n,m,q;
    std::cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
            my_cache[i][j] = my_cache[i - 1][j] + my_cache[i][j - 1] - my_cache[i - 1][j - 1] + map[i][j];
        }
    }

    for(int i = 1; i <= q; i++)
    {
        int x1,y1,x2,y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int res = my_cache[x2][y2] - my_cache[x2][y1 - 1] - my_cache[x1 - 1][y2] + my_cache[x1 - 1][y1 - 1];
        std::cout << res << std::endl;
    }
    return 0;
}
