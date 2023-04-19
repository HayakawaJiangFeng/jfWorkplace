#include <iostream>
#include <algorithm>

int n;
int values[20];
bool st[20];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            if(st[i]){
                
                std::cout << values[i] << " ";
            }
        }
        std::cout << std::endl;
        return;
    }

    //选
    st[x] = true;
    dfs(x + 1);
    st[x] = false;

    if(values[x] == values[x - 1] && st[x - 1]){

        return;
    }

    //不选
    dfs(x + 1);

}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }
    std::sort(values, values + n + 1);
    dfs(1);

    return 0;
}