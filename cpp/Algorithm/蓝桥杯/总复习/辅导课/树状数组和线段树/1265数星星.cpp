#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 32010;

int n;
int tr[Max], level[Max];

int lowBit(int x){

    return x & -x;
}
int add(int x){

    for(int i = x; i < Max; i += lowBit(i)){

        tr[i]++;
    }
}
int sum(int x){
    
    int res = 0;
    for(int i = x; i; i -= lowBit(i)) res += tr[i];
    return res;
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++){

        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        level[sum(x)]++;
        add(x);
    }

    for(int i = 0; i < n; i++){

        printf("%d\n",level[i]);
    }
    return 0;
}