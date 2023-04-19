#include <iostream>

int calculator(int a,int b, int n){

    if(n == 1 || n == 2){

        return 1;
    }else{

        return a * calculator(a,b,n - 1) + b * calculator(a,b,n - 2);
    }
}
int main(){

    int n,a,b,p;
    std::cin >> n >> a >> b >> p;

    std::cout << calculator(a,b,n) % p << std::endl; 

    return 0;
}