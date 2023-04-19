#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

std::string start;
std::string end;
int res;

void turns(int index){

    if(start[index] == '*'){

        start[index] = 'o';
    }else{

        start[index] = '*';
    }

    if(start[index + 1] == '*'){

        start[index + 1] = 'o';
    }else{

        start[index + 1] = '*';
    }
}
int main(){

    std::cin >> start;
    std::cin >> end;

    int len = start.size();

    for(int i = 0; i <= len - 2; i++){

        if(start[i] != end[i]){

            res++;
            turns(i);
        }
    }

    std::cout << res << std::endl;

    return 0;
}