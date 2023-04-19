#include <iostream>

int n;
int sum[100];

int dfs(int x){

    int temp;
    if(sum[x]){

        return sum[x];
    }
    if(x == 1){

        temp = 1;
    }
    else if(x == 2){

        temp = 2;
    }
    else{

        temp = sum[x] = dfs(x - 1) + dfs(x - 2);
    }
    sum[x] = temp;
    return temp;
}
int main(){

    std::cin >> n;

    std::cout << dfs(n) << std::endl;

    return 0;
}