/*
给定一个长度为 n
 的可包含重复数字的序列，从中随机选取 m
 个数字，输出所有可能的选择方案。

输入格式

第一行包含两个整数 n,m
。

第二行包含 n
 个正整数。

输出格式

按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如1 3 5 7排在1 3 6 8前面）。

数据范围

n>0
,
0≤m≤n
,
n+(n−m)≤25
,
序列内所有元素均不大于 n
。
*/

#include <iostream>
#include <algorithm>

int n,m;
int numbers[30];
int ans[30];

void dfs(int x, int start){

    if(x > m){

        for(int i = 1; i <= m; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;

        return;
    }
    for(int i = start; i <= n; i++){
        
        if(i != start && numbers[i] == numbers[i - 1]){
            
            continue;
        }
        ans[x] = numbers[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){

        std::cin >> numbers[i];
    }
    std::sort(numbers, numbers + n + 1);
    dfs(1,1);
}