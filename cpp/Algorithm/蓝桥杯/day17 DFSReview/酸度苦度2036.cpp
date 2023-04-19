/*题目描述

Perket 是一种流行的美食。为了做好 Perket，厨师必须谨慎选择食材，以在保持传统风味的同时尽可能获得最全面的味道。你有 
n
n 种可支配的配料。对于每一种配料，我们知道它们各自的酸度 
s
s 和苦度 
b
b。当我们添加配料时，总的酸度为每一种配料的酸度总乘积；总的苦度为每一种配料的苦度的总和。

众所周知，美食应该做到口感适中，所以我们希望选取配料，以使得酸度和苦度的绝对差最小。

另外，我们必须添加至少一种配料，因为没有任何食物以水为配料的。

输入格式

第一行一个整数 
n
n，表示可供选用的食材种类数。

接下来 
n
n 行，每行 
2
2 个整数 
s
i
s 
i
​	
  和 
b
i
b 
i
​	
 ，表示第 
i
i 种食材的酸度和苦度。

输出格式

一行一个整数，表示可能的总酸度和总苦度的最小绝对差。*/

#include <iostream>

int n;
int acid[15];
int bitter[15];
int res = 1e9;
bool st[15];
bool flag;

void dfs(int x){

    if(x == n){

        int acids = 1;
        int bitters = 0;

        for(int i = 0; i < n; i++){

            if(st[i]){

                flag = true;
                acids *= acid[i];
                bitters += bitter[i];
            }
        }
        if(flag){

            res = std::min(res, abs(acids - bitters));
        }
        return;
    }

    //不选
    st[x] = false;
    dfs(x + 1);
    st[x] = false;

    //选
    st[x] = true;
    dfs(x + 1);
    st[x] = false;
}

int main(){

    std::cin >> n;
    for(int i = 0; i < n; i++){

        std::cin >> acid[i] >> bitter[i];
    }

    dfs(0);

    std::cout << res << std::endl;
    return 0;
}