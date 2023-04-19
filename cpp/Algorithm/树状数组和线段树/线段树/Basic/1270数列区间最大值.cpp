#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int values[Max];

struct node
{
    int left;
    int right;
    int sum;
}tree[4 * Max];

void pushup_tree(int index)
{
    tree[index].sum = std::max(tree[index * 2].sum, tree[index * 2 + 1].sum);
}
void build_tree(int index, int start, int end)
{
    if(start == end)
    {
        tree[index].left = start;
        tree[index].right = end;
        tree[index].sum = values[end];
    }
    else
    {
        tree[index].left = start;
        tree[index].right = end;
        int mid = (start + end) / 2;

        build_tree(index * 2, start, mid);
        build_tree(index * 2 + 1, mid + 1, end);
        pushup_tree(index);
    }
}
int query_tree(int index, int start, int end)
{
    if(start <= tree[index].left && tree[index].right <= end)
    {
        return tree[index].sum;
    }
    int mid = (tree[index].left + tree[index].right) / 2;
    int max = - 1e9;
    if(start <= mid)
    {
        max = std::max(max, query_tree(index * 2, start, end));
    }
    if(end > mid)
    {
        max = std::max(max, query_tree(index * 2 + 1, start, end));
    }
    return max;
}

void modify_tree(int index, int idx, int val)
{
    if(tree[index].left == tree[index].right)
    {
        values[index] += val;
        tree[index].sum += val;
    }
    int mid = (tree[index].left + tree[index].right) / 2;
    if(idx <= mid)
    {
        modify_tree(index * 2, idx, val);
    }
    if(idx > mid)
    {
        modify_tree(index * 2 + 1, idx, val);
    }
    pushup_tree(index);
}

int main()
{
    int n,k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++) scanf("%d",&values[i]);

    build_tree(1,1,n);

    for(int i = 1; i <= k; i++)
    {
        int left,right;
        scanf("%d %d", &left,&right);

        printf("%d\n", query_tree(1, left, right));
    }

    return 0;
}