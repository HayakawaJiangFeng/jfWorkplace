#include <iostream>
#include <deque>

void printfDeque(std::deque<int>& dq){

    for(std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::deque<int> dq1;
    
    //尾插法
    dq1.push_back(1);
    dq1.push_back(2);

    //头插法
    dq1.push_front(0);
    
    printfDeque(dq1);

    //头删除
    dq1.pop_front();

    //尾删除
    dq1.pop_back();

    printfDeque(dq1);

    dq1.insert(dq1.begin(),0);
    dq1.insert(dq1.end(),7,7);

    printfDeque(dq1);

    dq1.erase(dq1.erase(dq1.begin()));

    printfDeque(dq1);

    dq1.clear();

    printfDeque(dq1);

    for(int i = 0; i < 10; i++){

        dq1.push_front(i);
    }
    for(int i = 0; i < dq1.size(); i++){

        std::cout << dq1[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < dq1.size(); i++){

        std::cout << dq1.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << dq1.front() << " " << dq1.back() << std::endl;
    return 0;
}