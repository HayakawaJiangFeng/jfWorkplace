#include <iostream>

std::string str;
int n;
bool visit[100];
int ans[100];
bool flag;

void dfs(int u, int cnt){

    if(flag){

        return;
    }
    if(u == str.size()){

        for(int i = 0; i < cnt; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        flag = true;
        return;
    }   
    int x = str[u] - '0';
    if(x <= n && !visit[x]){

        ans[cnt] = x;
        visit[x] = true;
        dfs(u + 1, cnt + 1);
        visit[x] = false;
    }
    if(u + 1 >= str.size()){

        return;
    }
    x = x * 10 + str[u + 1] - '0';
    if(x <= n && !visit[x]){
 
        ans[cnt] = x;
        visit[x] = true;
        dfs(u + 2, cnt + 1);
        visit[x] = false;
    }
}
int main(){

    std::cin >> str;
    
    n = str.size() <= 9 ? str.size() : (str.size() - 9) / 2 + 9;

    dfs(0,0);

    return 0;
}