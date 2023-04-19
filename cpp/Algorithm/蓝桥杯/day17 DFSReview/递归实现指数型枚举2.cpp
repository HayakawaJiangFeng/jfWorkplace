/*
给定一个长度为 n
 的可包含重复数字的序列，从中随机选取任意多个数字，输出所有可能的选择方案。

输入格式

第一行包含一个整数 n
，表示序列长度。

第二行包含 n
 个正整数。

输出格式

每行输出一种方案。

同一行内的数必须升序排列，相邻两个数用恰好1个空格隔开。

对于没有选任何数的方案，输出空行。

本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。

数据范围

1≤n≤15
,
序列内所有元素均不大于 n
。
*/

#include <iostream>
#include <algorithm>

int n;
int numbers[25];
bool st[25];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            if(st[i]){

                std::cout << numbers[i] << " ";
            }
        }
        std::cout << std::endl;
        return;
    }


    //选
    st[x] = true;
    dfs(x + 1);
    st[x] = false;

    if(numbers[x] == numbers[x - 1] && st[x - 1]){
        
        return;
    }

    //不选
    st[x] = false;
    dfs(x + 1);
    st[x] = false;

}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> numbers[i];
    }

    std::sort(numbers, numbers + n + 1);

    dfs(1);

    return 0;
}