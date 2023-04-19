/*
一个楼梯共有 n
 级台阶，每次可以走一级或者两级，问从第 0
 级台阶走到第 n
 级台阶一共有多少种方案。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示方案数。

数据范围
1≤n≤15
*/

#include <iostream>

int n;

int dfs(int x){

    if(x == 0 || x == 1){

        return 1;
    }
    return dfs(x - 1) + dfs(x - 2);

}

int main(){

    scanf("%d",&n);

    printf("%d\n",dfs(n));
}