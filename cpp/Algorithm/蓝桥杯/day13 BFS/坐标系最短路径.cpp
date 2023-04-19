#include <iostream>
#include <queue>

int n,A,B;
bool visit[1000];

int main(){

    std::cin >> n >> A >> B;

    std::queue<std::pair<int,int> > nums;

    nums.push(std::make_pair(A,0));

    visit[A] = true;

    while (!nums.empty())
    {
        
        int now = nums.front().first;
        int step = nums.front().second;
        nums.pop();

        if(now == B){
            
            std::cout << step << std::endl;
            break;
        }
        if(now + 1 <= n && !visit[now + 1]){

            nums.push(std::make_pair(now + 1, step + 1));
            visit[now + 1] = true;
        } 
        if(now - 1 >= n && !visit[now - 1]){

            nums.push(std::make_pair(now - 1, step + 1));
            visit[now - 1] = true;
        }
        if(now * 2 <= n && !visit[now * 2]){

            nums.push(std::make_pair(now * 2, step + 1));
            visit[now * 2] = true;
        }
    }
    
    return 0;
}