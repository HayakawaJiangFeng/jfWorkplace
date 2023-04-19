#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 110;

int n;
int level[Max];
int my_cache[Max];

int lowbit(int num)
{
    return num & -num;
}
void add(int index, int value)
{
    for(int i = index; i <= Max; i += lowbit(i))
    {
        my_cache[i] += value;
    }
}
int query(int index)
{
    int sum = 0;
    for(int i = index; i > 0; i -= lowbit(i))
    {
        sum += my_cache[i];
    }
    return sum;
}
int main()
{
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        std::cout << query(x) << " ";
        add(x + 1,1);
    }
    puts("");
    return 0;
}