#include <iostream>
#include <deque>

void printfDeque(std::deque<int>& d){

    for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::deque<int> d;
    for(int i = 0; i < 10; i++){

        d.push_back(i);
    }
    printfDeque(d);

    std::deque<int> d1;
    d1 = d;
    printfDeque(d1);

    std::deque<int> d2;
    d2.assign(d.begin(),d.end());
    printfDeque(d2);

    if(!d1.empty()){

        std::cout << "d1 is not empty" << std::endl;
    }
    std::cout << "d1 size : " << d1.size() << std::endl;

    d1.resize(15,7);

    printfDeque(d1);

    return 0;
}