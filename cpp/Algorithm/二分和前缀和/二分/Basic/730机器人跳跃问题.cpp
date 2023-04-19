#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int N;
int values[Max];

bool check(int mid)
{
    int temp = mid;
    for(int i = 0; i < N; i++)
    {
        temp = 2 * temp - values[i + 1];
        if(temp < 0) return false;
    }
    return true;
}
int main()
{
    std::cin >> N;
    for(int i = 1; i <= N; i++) scanf("%d",&values[i]);

    int left = 0;
    int right = Max;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if(check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << left << std::endl;

    return 0;   
}