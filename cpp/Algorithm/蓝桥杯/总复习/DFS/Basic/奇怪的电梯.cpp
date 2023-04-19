#include <iostream>

int n,a,b;
int res;
bool visit[205];
int values[205];

void dfs(int x,int cnt){

    if(x == b){

        res = std::min(res, cnt);
        return;
    }

    //向上
    if(x + values[x] <= 5 && !visit[x + values[x]]){

        dfs(x + values[x],cnt + 1);
    }
    
    //向下
    if(x - values[x] >= 1 && !visit[x - values[x]]){

        dfs(x - values[x], cnt + 1);
    }
}
int main(){

    std::cin >> n >> a >> b;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    res = 1e9;
    dfs(a,0);

    if(res == 1e9){

        std::cout << -1 << std::endl;
    }else{

        std::cout << res << std::endl;
    }
    return 0;
}