/*
猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 
10
10 种配料（芥末、孜然等），每种配料可以放 
1
1 到 
3
3 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 
n
n ，请输出这 
10
10 种配料的所有搭配方案。

输入格式

一个正整数 
n
n，表示美味程度。

输出格式

第一行，方案总数。

第二行至结束，
10
10 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 
0
0。
*/

#include <iostream>

int n;
int res;
int ans[15];
int function[60000][15];
int add[3] = {1,2,3};

void dfs(int x, int cnt){

    if(cnt > n){
        
        return;
    }
    if(x > 10){

        if(cnt == n){

            res++;
            for(int i = 1; i <= 10; i++){

                function[res][i] = ans[i];
            }
        }
        return;
    }
    for(int i = 0; i < 3; i++){

        ans[x] = add[i];
        dfs(x + 1, cnt + add[i]);
        ans[x] = 0;
    }
    
}
int main(){

    std::cin >> n;
    
    dfs(1, 0);

    std::cout << res << std::endl;

    for(int i = 1; i <= res; i++){

        for(int j = 1; j <= 10; j++){

            std::cout << function[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}