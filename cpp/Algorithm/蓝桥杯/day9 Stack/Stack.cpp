#include <iostream>
#include <stack>

int main(){

    std::stack<int> s1;

    for(int i = 1; i <= 10; i++){

        s1.push(i);
    }

    while(!s1.empty()){

        std::cout << "s1.size = " << s1.size() << std::endl;
        std::cout << s1.top() << std::endl;
        s1.pop();
    }

    return 0;
}