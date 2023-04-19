#include <iostream>

int n,k,sum,ans;
int value[110];
bool visit[110];

void dfs(int s, int cnt, int step){

    if(s > sum || cnt > k){

        return;
    }
    if(s == sum && cnt == k){
        
        ans++;
        return;
    }
    for(int i = step; i < n; i++){

        if(!visit[i]){

            visit[i] = true;
            dfs(s + value[i], cnt + 1, i + 1);
            visit[i] = false;
        }
    }
}

int main(){

    std::cin >> n >> k >> sum;
    for(int i = 0; i < n; i++){

        value[i] = i + 1;
    }
    ans = 0;
    dfs(0,0,0);

    std::cout << ans << std::endl;

    return 0;
}