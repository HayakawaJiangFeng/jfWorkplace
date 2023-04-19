#include <iostream>
#include <set>


int n;
int values[105];
int ans[105];
int st[105];
std::set<int> s;

void dfs(int x){

    if(x > n){

        int sum = 0;
        for(int i = 1; i <= n; i++){

            sum += ans[i];
        }
        if(sum > 0){

            s.insert(sum);
        }

        return;
    }

    //不选
    dfs(x + 1);

    //选，左
    ans[x] = -values[x];
    dfs(x + 1);
    ans[x] = 0;

    //选，右    
    ans[x] = values[x];
    dfs(x + 1);
    ans[x] = 0;
}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    dfs(1);

    int res = s.size();
    std::cout << res << std::endl;

    /*
    for(std::set<int>::iterator it = s.begin(); it != s.end(); it++){

        std::cout << *it << std::endl;
    }
    */
    return 0;
}