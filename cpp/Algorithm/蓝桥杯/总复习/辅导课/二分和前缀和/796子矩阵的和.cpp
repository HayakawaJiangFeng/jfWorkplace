#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int Max = 1010;

int n,m,q;
int matrix[Max][Max];
int my_cache[Max][Max];

int main(){

    std::cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            scanf("%d", &matrix[i][j]);
            my_cache[i][j] = my_cache[i - 1][j] + my_cache[i][j - 1] - my_cache[i - 1][j - 1] + matrix[i][j];
        }
    }

    while (q--)
    {
        int x1,y1,x2,y2;

        std::cin >> x1 >> y1 >> x2 >> y2;

        int res = my_cache[x2][y2] - my_cache[x1 - 1][y2] - my_cache[x2][y1 - 1] + my_cache[x1 - 1][y1 - 1];
        std::cout << res << std::endl;
    }

    return 0;   
}