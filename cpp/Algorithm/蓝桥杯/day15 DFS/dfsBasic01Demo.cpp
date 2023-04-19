#include <iostream>

int n;
int st[17];
int ans[17];

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
    //选为1，不选为2，默认为0

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

    std::cin >> n;

    dfs(1);

    return 0;
}