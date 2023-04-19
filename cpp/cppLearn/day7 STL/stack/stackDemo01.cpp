#include <iostream>
#include <stack>

int main(){

    std::stack<int> s1;
    for(int i = 0; i < 9; i++){

        s1.push(i);
    }
    if(!s1.empty()){

        std::cout << s1.size() << std::endl;
    }
    std::cout << "top : " << s1.top() << std::endl;

    s1.pop();

    std::cout << "top : " << s1.top() << std::endl;

    return 0;
}