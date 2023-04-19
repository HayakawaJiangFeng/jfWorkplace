#include <iostream>

//输入n个数，输出所有组合

int n;
int st[20];
int value[20];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            if(st[i] == 1){

                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
        return;
    }
    //选为1，不选为2，未知为0
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
}

int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> value[i];
    }

    dfs(1);

    return 0;
}