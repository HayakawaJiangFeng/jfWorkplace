#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int Max = 5010;

int map[Max][Max];
int N,R;
int n,m;

int main(){

    std::cin >> N >> R;

    R = std::min(R,5001);

    n = m = R;

    for(int i = 0; i < N; i++){

        int x,y,w;

        std::cin >> x >> y >> w;

        x++,y++;

        n = std::max(x, n);
        m = std::max(y, m);

        map[x][y] += w;
    }
    for(int i = 1 ; i <= n; i ++){

        for(int j = 1; j <= m; j++){

            map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1]; 
        }
    }

    int res = 0;

    for(int i = R; i <= n; i++){

        for(int j = R; j <= m; j++){

            res = std::max(map[i][j] - map[i - R][j] - map[i][j - R] + map[i - R][j - R] ,res);
        }
    }

    std::cout << res << std::endl;

    return 0;
}