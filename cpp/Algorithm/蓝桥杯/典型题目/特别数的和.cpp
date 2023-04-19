#include <iostream>

int n;

bool check(int num){

    while (num)
    {
        int res = num % 10;
        if(res == 2 || res == 0 || res == 1 || res == 9){

            return true;
        }
        num /= 10;
    }
    return false;
}
int main(){

    std::cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++){

        if(check(i)){

            sum += i;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}