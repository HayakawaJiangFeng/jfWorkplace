#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int value[Max];

struct node
{
    int left;
    int right;
    int sum;
}tree[4 * Max];

void push_up(int index)
{
    tree[index].sum = tree[index * 2].sum + tree[index * 2 + 1].sum;
}
void build_tree(int index, int start, int end)
{
    if(start == end)
    {
        tree[index].left = start;
        tree[index].right = end;
        tree[index].sum = value[end];
    }
    else
    {
        tree[index].left = start;
        tree[index].right = end;
        int mid = (start + end) / 2;

        build_tree(index * 2, start, mid);
        build_tree(index * 2 + 1, mid + 1, end);
        push_up(index);
    }
}
void modify_tree(int index, int idx, int val)
{
    if(tree[index].left == tree[index].right)
    {
        tree[index].sum += val;
        value[index] += val;
    }
    else
    {
        int mid = (tree[index].left + tree[index].right) / 2;
        if(idx <= mid)
        {
            modify_tree(index * 2, idx, val);
        }
        else
        {
            modify_tree(index * 2 + 1, idx, val);
        }
        push_up(index);
    }
}
int query_tree(int index, int start, int end)
{
    if(tree[index].left >= start && tree[index].right <= end)
    {
        return tree[index].sum;
    }
    int mid = (tree[index].left + tree[index].right) / 2;
    int sum = 0;
    if(start <= mid)
    {
        sum = query_tree(index * 2, start, end);
    }
    if(end > mid)
    {
        sum += query_tree(index * 2 + 1, start, end);
    }
    return sum;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i = 1; i <= n; i++) scanf("%d", &value[i]);

    build_tree(1,1,n);

    for(int i = 1; i <= k; i++)
    {
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        if(k == 0) printf("%d\n",query_tree(1,a,b));
        else modify_tree(1,a,b);
    }
    
    return 0;
}
