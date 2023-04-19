#include <iostream>

int main(){

    //层数
    int n;
    std::cin >> n;
    
    for(int i = 1; i <= n; i++){

        std::string space = std::string(n - i,' ');
        std::string ch    = std::string(2 * i - 1, 'A' + i - 1);
        std::cout << space + ch << std::endl;
    }
    return 0;
}