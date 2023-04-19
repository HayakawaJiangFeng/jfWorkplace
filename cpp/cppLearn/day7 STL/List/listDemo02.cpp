#include <iostream>
#include <list>
#include <algorithm>

void printList(const std::list<int> &l){

    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::list<int> list;
    for(int i = 0; i < 10; i++){

        list.push_back(i);
    }
    printList(list);

    if(!list.empty()){

        std::cout << list.size() << std::endl;
    }
    list.resize(20,1314);
    printList(list);

    list.resize(4);
    printList(list);

    list.insert(list.begin(),1000);
    printList(list);
    list.insert(list.begin(),10,1000);
    printList(list);
    list.erase(list.begin());
    printList(list);
    list.remove(1000);
    printList(list);
    list.clear();
    std::cout << list.size() << std::endl;
    
    int num1 = 3;
    int num2 = 1;
    std::cout << std::__algo_gcd(num1,num2) << std::endl;
    return 0;
}