#include <iostream>
#include <queue>

int main(){

    int n,m;
    std::cin >> n >> m;

    std::queue<int> q;

    for(int i = 0; i < n; i++){

        q.push(i + 1);
    }

    int cur = 1;
    while(q.size() > 1){

        int temp = q.front();
        q.pop();

        if(cur == m){

            cur = 1;
        }else{

            q.push(temp);
            cur++;
        }
    }
    std::cout << q.front() << std::endl;
}