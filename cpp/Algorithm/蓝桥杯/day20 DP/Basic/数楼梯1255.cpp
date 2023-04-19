#include <iostream>

long long n;
long long cache[5005];

long long dfs(long long x){

    if(cache[x]){

        return cache[x];
    }
    long long temp = 0;
    if(x == 1){

        temp = 1;
    }
    else if(x == 2){

        temp = 2;
    }else{

        temp = dfs(x - 1) + dfs(x - 2);
    }
    cache[x] = temp;
    return temp;
}
int main(){

    std::cin >> n;

    std::cout << dfs(n) << std::endl;

    return 0;
}