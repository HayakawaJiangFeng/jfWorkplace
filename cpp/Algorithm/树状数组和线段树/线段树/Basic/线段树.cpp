#include <algorithm>
#include <iostream>
#include <cstring>  
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int n;
int array[Max];
int tree[Max];

void build_tree(int array[], int tree[], int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = array[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        build_tree(array, tree, left_node, start, mid);
        build_tree(array, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}
void update_tree(int array[], int tree[], int node, int start, int end, int index, int val)
{
    if(start == end)
    {
        array[node] = val;
        tree[node]  = val;
    }
    else
    {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        if(index >= start && index <= mid)
        {
            update_tree(array, tree, left_node, start, mid, index, val);
        }
        else
        {
            update_tree(array, tree, right_node, mid + 1, end, index, val);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
}
int query_tree(int array[], int tree[], int node, int start, int end, int left, int right)
{
    std::cout << start << " " << end << std::endl;
    if(right < start || left > end)
    {
        return 0;
    }
    else if(left <= start && end <= right)
    {
        return tree[node];
    }
    else if(start == end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        int sum_left = query_tree(array, tree, left_node, start, mid, left, right);
        int sum_right = query_tree(array, tree, right_node, mid + 1, end, left, right);
        return sum_left + sum_right;
    }
}
int main()
{
    std::cin >> n;

    for(int i = 0; i < n; i++) scanf("%d", &array[i]);
    
    build_tree(array, tree, 0, 0, n - 1);

    for(int i = 0; i <= 14; i++) printf("%d ",tree[i]);
    puts("");

    update_tree(array, tree, 0, 0, n - 1, 4, 6);
    for(int i = 0; i <= 14; i++) printf("%d ",tree[i]);
    puts("");

    int res = query_tree(array, tree, 0, 0, n - 1, 2, 4);
    std::cout << res << std::endl;
    
    return 0;
}