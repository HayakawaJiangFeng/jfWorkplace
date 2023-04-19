#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

long long values[Max];
long long my_cache[Max];
long long cnt[Max];

int main()
{
    int n,k;
    long long res = 0;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&values[i]);
        my_cache[i] = my_cache[i - 1] + values[i];
    }   
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= i; j--)
        {
            if((my_cache[j] - my_cache[i - 1]) % k == 0) cnt++;
        }
    }
    */

    for(int i = 1; i <= n; i++)
    {
        res += cnt[my_cache[i] % k];
        cnt[my_cache[i] % k] ++;
    }
    long long resF = res + cnt[0];
    std::cout << resF << std::endl;

    return 0;
}