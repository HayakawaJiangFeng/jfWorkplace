#include <iostream>
#include <set>

void printSet(const std::set<int> &set){

    for(std::set<int>::const_iterator it = set.begin(); it != set.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::set<int> s1;
    
    s1.insert(20);
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);

    printSet(s1);
    std::cout << s1.size() << std::endl;

    std::set<int> s2;
    for(int i = 0; i < 4; i++){

        s2.insert(i);
    }
    printSet(s2);

    s1.swap(s2);
    printSet(s1);
    printSet(s2);

    return 0;
}