/*
给定一个长度为 n
 的可包含重复数字的序列，请你求出其所有不重复的全排列。

输入格式

第一行包含整数 n
。

第二行包含 n
 个整数。

输出格式

输出所有的不同排列，每种排列占一行。

在确定每种排列的输出顺序时，第一个数较小的先输出，第一个数相同时，第二个数较小的先输出，以此类推。

数据范围

1≤n≤9
,
数组中包含的元素的取值范围 [1,9]


3
1 1 2

1 1 2
1 2 1
2 1 1

*/

#include <iostream>
#include <algorithm>

int n;
int value[11];
int ans[11];
bool st[11];

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
            ans[x] = value[i];
            dfs(x + 1);
            ans[x] = 0;
            st[i] = false;
            
            while(i + 1 <= n && value[i] == value[i + 1]){
                
                i++;
            }
        }
    }
}

int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> value[i];
    }
    std::sort(value, value + n + 1);

    dfs(1);

    return 0;
}