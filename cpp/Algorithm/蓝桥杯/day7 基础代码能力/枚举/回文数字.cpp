#include <iostream>

//输入n，在10000 - 1000000中找到一个每个位数加起来为n的回文数字

int digit[6];
int n;

bool judge(int x){

    int m = 0;
    int sum = 0;

    while(x){

        digit[m++] = x % 10;
        sum += x % 10;
        x /= 10;
    }   

    if(sum != n){

        return false;
    }

    for(int i = 0; i < m / 2; i++){

        if(digit[i] != digit[m - 1 - i]){
            
            return false;
        }
    }
    return true;
}

int main(){

    bool flag = false;
    std::cin >> n;

    for(int i = 10000; i < 1000000; i++){

        if(judge(i)){

            std::cout << i << std::endl;
            flag = true;
        }
    }
    if(!flag){
        
        std::cout << -1 << std::endl;
    }

    return 0;
}