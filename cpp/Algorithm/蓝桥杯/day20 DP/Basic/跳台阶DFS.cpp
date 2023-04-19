#include <iostream>

int n;
//利用记忆数组降低时间复杂度
int memory[1000];

int dfs(int x){

    if(memory[x]){

        return memory[x];
    }

    int temp = 0;
    if(x == 1){

        temp = 1;
    }
    else if(x == 2){

        temp = 2;
    }
    else{

        temp = dfs(x - 1) + dfs(x - 2);
    }

    memory[x] = temp;

    return temp;
}

int main(){

    std::cin >> n;

    std::cout << dfs(n) << std::endl;

    return 0;
}