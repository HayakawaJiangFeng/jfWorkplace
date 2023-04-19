#include <iostream>

//给一个数n,让你找出一个由0和1组成的十进制数，要求这个十进制数可以被n整除
int n;
bool flag;

void dfs(int num, int cnt){

    if(cnt >= 19){

        return;
    }
    if(flag){
        
        return;
    }
    if(num % n == 0){

        flag = true;
        std::cout << num;
        return;
    }
    dfs(num * 10 + 0, cnt + 1);
    dfs(num * 10 + 1, cnt + 1);
}
int main(){

    std::cin >> n;   
    dfs(1,0);
    return 0;
}