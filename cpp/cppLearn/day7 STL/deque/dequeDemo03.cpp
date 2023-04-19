#include <iostream>
#include <deque>
#include <algorithm>

int main(){

    std::deque<int> d;
    d.push_back(5);
    d.push_back(3);
    d.push_back(7);
    d.push_back(0);

    for(int i = 0; i < d.size(); i++){

        std::cout << d.at(i) << " ";
    }
    std::cout << std::endl;

    std::sort(d.begin(),d.end());

    for(int i = 0; i < d.size(); i++){

        std::cout << d.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}