/*
把 1∼n
 这 n
 个整数排成一行后随机打乱顺序，输出所有可能的次序。

输入格式

一个整数 n
。

输出格式

按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。

数据范围

1≤n≤9
*/

#include <iostream>

int n;
int ans[15];
bool st[15];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for(int i = 1; i <= n; i++){

        if(!st[i]){

            st[i] = true;
            ans[x] = i;
            dfs(x + 1);
            ans[x] = 0;
            st[i] = false;
        }
    }
}

int main(){

    std::cin >> n;

    dfs(1);

    return 0;
}
