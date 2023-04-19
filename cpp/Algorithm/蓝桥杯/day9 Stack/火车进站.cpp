#include <iostream>
#include <stack>
#include <vector>

//规定入栈顺序为 1 - n,给出出栈序列，判断是否合法

std::stack<int> s1;
int main(){
    
    int n;
    std::cin >> n;
    std::vector<int> v1(n);

    for(int i = 0; i < n; i++){

        std::cin >> v1[i];
    }

    int cur = 1;
    bool flag = 1;

    for(int i = 0; i < n; i++){

        while((s1.empty() || s1.top() != v1[i]) && cur <= n){

            s1.push(cur);
            cur++;
        }
        if(s1.empty() || s1.top() != v1[i]){

            flag = 0;
            break;
        }else{

            s1.pop();
        }
    }
    if(flag){

        std::cout << "legal" << std::endl;
    }else{

        std::cout << "illegal" << std::endl;
    }

    return 0;
}