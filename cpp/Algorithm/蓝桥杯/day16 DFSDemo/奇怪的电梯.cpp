#include <iostream>

int N,A,B;
int res = 1e9;
int value[1000];
bool st[1000];

void dfs(int x, int cnt){

    if(cnt >= res){

        return;
    }
    if(x < 0 || x > N){

        return;
    }
    if(x == B){

        res = std::min(res, cnt);
        return;
    }

    //向上
    if(x + value[x] <= N && !st[x + value[x]]){

        st[x + value[x]] = true;
        dfs(x + value[x], cnt + 1);
        st[x + value[x]] = false;
    }

    //向下
    if(x - value[x] > 0 && !st[x - value[x]]){

        st[x - value[x]] = true;
        dfs(x - value[x], cnt + 1);
        st[x - value[x]] = false;
    }

}
int main(){

    std::cin >> N >> A >> B;

    for(int i = 1; i <= N; i++){

        std::cin >> value[i];
    }

    dfs(A,0);

    if(res == 1e9){

        std::cout << -1 << std::endl;
    }else{

        std::cout << res << std::endl;
    }

    return 0;
}