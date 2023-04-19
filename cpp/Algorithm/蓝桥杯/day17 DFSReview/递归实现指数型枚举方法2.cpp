#include <iostream>

int n;
bool st[20];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            if(st[i]){

                std::cout << i << " ";
            }
        }
        std::cout << std::endl;

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

    dfs(1);

    return 0;
}