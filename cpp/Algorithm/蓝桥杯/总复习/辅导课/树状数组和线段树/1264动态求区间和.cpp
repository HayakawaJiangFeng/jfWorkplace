#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 100010;

int n,m;
int values[Max];
int my_cache[Max];

int lowBit(int num){

    return num & -num;
}
void add(int num, int v){

    for(int i = num; i <= n; i += lowBit(i)){

        my_cache[i] += v;
    }
}
int query(int num){

    int res = 0;
    for(int i = num; i; i -= lowBit(i)){

        res += my_cache[i];
    }
    return res;
}
int main(){

    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n; i++) scanf("%d", &values[i]);
    for(int i = 1; i <= n; i++) add(i, values[i]);

    while (m--)
    {
        int k,x,y;
        scanf("%d%d%d", &k,&x,&y);
        if(k == 0) printf("%d\n",query(y) - query(x - 1));
        else add(x,y);
    }
    return 0;
}