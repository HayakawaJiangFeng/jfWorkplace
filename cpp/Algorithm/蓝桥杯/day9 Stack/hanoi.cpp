#include <iostream>
#include <stack>

std::stack<int> stack[3];

void move(int A, int B){

    int temp = stack[A].top();
    stack[A].pop();
    stack[B].push(temp);
    std::cout << A << "----->" << B << std::endl;
}
void hanoi(int A, int B, int C, int n){

    if(n == 1){

        move(A, C);
        return;       
    }
    hanoi(A,C,B,n - 1);
    move(A,C);
    hanoi(B,A,C,n - 1);
}
int main(){

    int n;
    std::cin >> n;

    for(int i = n; i >= 1; i--){

        stack[0].push(i);
    }
    hanoi(0,1,2,n);

    while(!stack[2].empty()){

        std::cout << stack[2].top() << " ";
        stack[2].pop();
    }
    
    return 0;
}