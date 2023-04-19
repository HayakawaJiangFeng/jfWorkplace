#include <iostream>

int n,k,sum,ans;
int numbers[40];
bool visit[40];

void dfs(int s, int cnt){

    if(cnt == k){
        
        if(s == sum){
            
            ans++;
        }
    }   
    
    for(int i = 0; i < n; i++){

        if(!visit[i]){

            visit[i] = true;
            dfs(s + numbers[i], cnt + 1);
            visit[i] = false;
        }
    }
}

int main(){

    std::cin >> n >> k >> sum;

    for(int i = 0; i < n; i++){

        std::cin >> numbers[i];
    }
    ans = 0;
    dfs(0,0);
    std::cout << ans << std::endl;
    return 0;
}