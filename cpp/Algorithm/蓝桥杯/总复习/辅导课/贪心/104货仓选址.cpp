#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int Max = 1e5 + 10;

int values[Max];

int main()
{
    int N;
    std::cin >> N;
    int res = 0;

    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    std::sort(values + 1, values + N + 1);
    int mid = (N + 1) / 2;
    int flag = values[mid];

    for(int i = 1; i <= N; i++)
    {
        res += abs(flag - values[i]);
    }
    std::cout << res << std::endl;

    return 0;
}