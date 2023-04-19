/*
从 1∼n
 这 n
 个整数中随机选取任意多个，输出所有可能的选择方案。

输入格式
输入一个整数 n。

输出格式
每行输出一种方案。

同一行内的数必须升序排列，相邻两个数用恰好 1
 个空格隔开。

对于没有选任何数的方案，输出空行。
本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。

数据范围
1≤n≤15
*/

#include <iostream>

int n;
int st[17];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n ;i++){

            if(st[i] == 1){

                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
        return;
    }
    
    //不选
    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;

    //选
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;


}

int main(){

    scanf("%d", &n);

    dfs(1);

    return 0;
}