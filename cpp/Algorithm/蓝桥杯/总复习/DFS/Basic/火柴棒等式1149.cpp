#include <iostream>

int n;
int res;
int ans[4];
int values[100005] = {6,2,5,5,4,5,6,3,7,6};
bool visit[10];

void dfs(int x, int sum){

    if(sum > n - 4){

        return;
    }
    if(x > 3){

        if(ans[1] + ans[2] == ans[3] && sum == n - 4){

            res++;
        }
        return;
    }

    for(int i = 0; i <= 100000; i++){

        ans[x] = i;
        dfs(x + 1, sum + values[i]);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n;
    for(int i = 10; i <= 100000; i++){

        values[i] = values[i / 10] + values[i % 10];
    }

    dfs(1,0);

    std::cout << res << std::endl;

    return 0;
}