#include <iostream>

int N,V;
int values[105];

int dfs(int x, int cnt){
    
    if(x > N){

        return 0;
    }

    return std::max(dfs(x + 1, cnt), dfs(x + 2, cnt + values[x]));
}
int main(){

    std::cin >> N >> V;

    for(int i = 1; i <= N; i++){
        
        std::cin >> values[i];
    }

    std::cout << dfs(1,0) << std::endl;

    return 0;
}