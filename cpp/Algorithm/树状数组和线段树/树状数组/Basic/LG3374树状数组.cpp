#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 * 5 + 10;

int n,m;
int values[Max];
int my_cache[Max];

int lowbit(int num)
{
    return num & -num;
}

void add(int index, int value)
{
    for(int i = index; i <= n; i += lowbit(i))
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
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) scanf("%d", &values[i]);
    for(int i = 1; i <= n; i++) add(i, values[i]);

    for(int i = 1; i <= m; i++)
    {
        int id, index, value;
        scanf("%d %d %d", &id, &index, &value);

        if(id == 1)
        {
            add(index, value);
            values[index] += value;
        }
        else
        {
            int res = query(value) - query(index - 1);
            printf("%d\n", res);
        }
    }
    return 0;
}