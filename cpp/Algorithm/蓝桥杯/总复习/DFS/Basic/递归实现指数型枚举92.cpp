#include <iostream>

int n;
bool visit[17];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            if(visit[i]){

                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
        return;
    }

    //不选
    dfs(x + 1);

    //选
    visit[x] = true;
    dfs(x + 1);
    visit[x] = false;
}
int main(){

    std::cin >> n;
    
    dfs(1);

    return 0;
}