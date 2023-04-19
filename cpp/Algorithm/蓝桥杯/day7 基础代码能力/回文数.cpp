#include <iostream>

int numbers[1005];
int digit[1005];

bool judge(int number){

    int cnt = 0;
    while(number){

        digit[cnt++] = number % 10;
        number /= 10;
    }
    for(int i = 0; i < cnt / 2; i++){

        if(digit[i] != digit[cnt - 1 - i]){

            return false;
        }
    }
    return true;
}
int reverse(int number){

    int ret = 0;
    while(number){

        ret = ret * 10 + number % 10;
        number /= 10;
    }
    return ret;
}
int main(){

    int number, ans;
    std::cin >> number;
    ans = 0;

    numbers[ans++] = number;

    while(!judge(number)){

        number += reverse(number);
        numbers[ans++] = number;
    }
    std::cout << ans - 1 << std::endl;
    for(int i = 0; i < ans; i++){

        if(i != ans - 1){

            std::cout << numbers[i] << "--->";
        }else{

            std::cout << numbers[i] << std::endl;
        }
    }
    return 0;
}