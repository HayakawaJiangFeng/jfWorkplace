#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 * 3 + 2010;

int n;
int tree[Max];
int level[Max];

int lowbit(int num)
{
    return num & -num;
}
void add(int index)
{
    for(int i = index; i < Max; i += lowbit(i))
    {
        tree[i] += 1;
    }
}
int query(int index)
{
    int sum = 0;
    for(int i = index; i > 0; i -= lowbit(i))
    {
        sum += tree[i];
    }
    return sum;
}
int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        x++;
        level[query(x)]++;
        add(x);
    }
    for(int i = 0; i < n; i++) printf("%d\n",level[i]);

    return 0;
}