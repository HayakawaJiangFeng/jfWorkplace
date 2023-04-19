#include <iostream>

char ans[105];

int main(){

    int n,m,now,temp;
    temp = 0;
    std::cin >> n >> m;

    if(n < 0){

        std::cout << "-";
        n = -n;
    }
    while(n){

        now = n % m;
        if(now <= 9){

            ans[temp++] = '0' + now;
        }else{

            ans[temp++] = 'A' + now - 10;
        }
        n /= m;
    }
    if(n == 0){
        
        std::cout << 0;
    }
    for(int i = temp - 1; i >= 0; i--){

        std::cout << ans[i];
    }
    std::cout << std::endl;
    return 0;
}