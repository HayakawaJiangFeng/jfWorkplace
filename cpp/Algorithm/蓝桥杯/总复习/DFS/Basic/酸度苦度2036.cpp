#include <iostream>

int n;
int res;
int acid[15];
int bitter[15];
bool visit[15];

void dfs(int x){

    if(x > n){

        int multi = 1;
        int sum = 0;

        for(int i = 1; i <= n; i++){

            if(visit[i]){

                multi *= acid[i];
                sum   += bitter[i];
                res = std::min(res,abs(multi - sum));
            }
        }
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

    res = 1e9;
    for(int i = 1; i <= n; i++){

        std::cin >> acid[i];
        std::cin >> bitter[i];
    }

    dfs(1);

    std::cout << res << std::endl;

    return 0;
}
