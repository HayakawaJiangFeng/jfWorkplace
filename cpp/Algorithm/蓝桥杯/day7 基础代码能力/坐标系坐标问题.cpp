#include <iostream>

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
char op[15];

int main(){

    int num, x,d;
    int nowX = 0, nowY = 0;
    std::cin >> num;
    d = 3;
    for(int i = 0; i < num; i++){

        std::cin >> op >> x;
        if(op[0] == 'b'){

            d = (d + 2) % 4;
        }else if(op[0] == 'l'){

            d = (d + 1) % 4;
        }else if(op[0] == 'r'){

            d = (d + 3) % 4;
        }
        nowX += dx[d] * x;
        nowY += dy[d] * x;
    }
    std::cout << nowX << " " << nowY << std::endl;
    return 0;
}