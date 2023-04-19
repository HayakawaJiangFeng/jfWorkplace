#include <iostream>
#include <queue>
#include <cstring>

int N,A,B;
int value[205];
int cnt[205];

std::queue<int> q;

int bfs(int x){

    memset(cnt, -1 , sizeof(cnt));
    cnt[x] = 0;
    q.push(x);   

    while (!q.empty())
    {
        
        int temp = q.front();
        q.pop();

        if(temp == B){

            return cnt[B];
        }
        if(temp - value[temp] > 0 && cnt[temp - value[temp]] < 0){

            q.push(temp - value[temp]);
            cnt[temp - value[temp]] = cnt[temp] + 1;
        }
        if(temp + value[temp] <= N && cnt[temp + value[temp]] < 0){

            q.push(temp + value[temp]);
            cnt[temp + value[temp]] = cnt[temp] + 1;
        } 
    }
    return cnt[B];
}

int main(){

    std::cin >> N >> A >> B;

    for(int i = 1; i <= N; i++){

        std::cin >> value[i];
    }

    if(bfs(A) == -1){

        std::cout << -1 << std::endl;
    }else{

        std::cout << bfs(A) << std::endl;
    }

    return 0;
}