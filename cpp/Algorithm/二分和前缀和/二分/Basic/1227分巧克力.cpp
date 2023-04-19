#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int N,K;
struct map
{
    int x;
    int y;
}maps[Max];

bool check(int mid)
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += (maps[i].x / mid) * (maps[i].y / mid);
    }
    if(sum >= K) return true;
    else return false;
}
int main()
{
    std::cin >> N >> K;

    int cnt = 0;

    for(int i = 0; i < N; i++)
    {
        struct map m;
        std::cin >> m.x >> m.y;
        maps[cnt++] = m;
    }

    int left = 1;
    int right = 1e5;

    while (left < right)
    {
        int mid = (left + right + 1) / 2;
        if(check(mid))
        {
            left = mid;
        } 
        else
        {
            right = mid - 1;
        }
    }
    std::cout << left << std::endl;

    return 0;
}