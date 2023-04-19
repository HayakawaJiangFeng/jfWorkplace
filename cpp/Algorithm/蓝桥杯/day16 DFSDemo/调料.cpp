#include <iostream>

int n;
int acid[1000];
int bitter[1000];
int res = 1e9;
int st[1000];
bool has_tl;

void dfs(int x){

    if(x > n){

        int mult = 1;
        int sum = 0;
        for(int i = 1; i <= n; i++){

            if(st[i] == 1){

                has_tl = true;
                mult *= acid[i];
                sum  += bitter[i];
            }
        }
        if(has_tl){

            res = std::min(res,std::abs(mult - sum));
        }
        return;
    }

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

    for(int i = 1; i <= n; i++){

        std::cin >> acid[i];
        std::cin >> bitter[i];
    }

    dfs(1);

    std::cout << res << std::endl;

    return 0;
}