#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int Max = 100010;

int n,m;
int w[Max];

struct Node
{
    int l,r;
    int sum;
}tr[Max * 4];

void pushup(int u){

    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}

void build(int u, int l, int r){

    if(l == r){

        tr[u].l = l;
        tr[u].r = r;
        tr[u].sum = w[r];
    }else{

        tr[u].l = l;
        tr[u].r = r;
        int mid = (l + r) / 2;
        build(u * 2, l, mid), build((u + 1) * 2, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r){

    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = (tr[u].l + tr[u].r) / 2;
    int sum = 0;
    if(l <= mid) sum = query(u * 2, l, r);
    if(r > mid) sum += query((u + 1) * 2, l, r);

    return sum;
}

void modify(int u, int x, int v){
    
    if(tr[u].l == tr[u].r) tr[u].sum += v;
    else{

        int mid = (tr[u].l + tr[u].r) / 2;
        if(x <= mid) modify(u * 2, x,v);
        else modify((u + 1) * 2, x, v);
        pushup(u);
    }
}
int main(){

    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
    build(1,1,n);

    int k,a,b;
    while (m--)
    {
        scanf("%d%d%d",&k, &a, &b);
        if(k == 0) printf("%d\n", query(1, a, b));
        else modify(1, a, b);
    }
    
    return 0;
}