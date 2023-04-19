#include <iostream>
#include <vector>

std::vector<int> son[10005];
bool f[10005];
int ans[10005];

int dfs(int u){

    int ret = 0;
    for(int i = 0; i < son[u].size(); i++){

        ret += dfs(son[u][i]);
    }
    ans[u] = ret;
    return ret + 1;
}
int main(){

    int number;
    std::cin >> number;

    int x,y;
    for(int i = 0; i < number - 1; i++){

        std::cin >> x >> y;
        son[x].push_back(y);
        f[y] = true;
    }

    int u = 0;
    for(int i = 1; i <= number; i++){

        if(!f[i]){

            u = i;
            break;
        }
    }
    dfs(u);
    for(int i = 1; i <= number; i++){
        
        std::cout << ans[i] << std::endl;
    }
}