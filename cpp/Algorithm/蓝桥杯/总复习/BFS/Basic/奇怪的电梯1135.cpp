#include <iostream>
#include <cstring>
#include <queue>

int n,a,b;
int step[205];
int values[205];
std::queue<int> q;

int bfs(int x){

    memset(step, -1, sizeof(step));
    q.push(x);
    step[x] = 0;

    while (q.size())
    {
        
        int temp = q.front();
        q.pop();

        if(temp == b){
            
            return step[b];
        }

        if(temp + values[temp] <= n && step[temp + values[temp]] < 0){

            step[temp + values[temp]] = step[temp] + 1;
            q.push(temp + values[temp]);
        }
        if(temp - values[temp] >= 1 && step[temp - values[temp]] < 0){

            step[temp - values[temp]] = step[temp] + 1;
            q.push(temp - values[temp]);
        }
    }
    return step[b];
}
int main(){

    std::cin >> n >> a >> b;

    for(int i = 1; i <= n; i++){
        
        std::cin >> values[i];
    }

    int res = bfs(a);

    if(res == -1){

        std::cout << -1 << std::endl;
    }else{

        std::cout << res << std::endl;
    }

    return 0;
}