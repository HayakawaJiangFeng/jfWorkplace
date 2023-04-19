#include <iostream>
#include <list>

bool myCompare(int x,int y){

    return x > y;
}
void printList(const std::list<int> &list){

    for(std::list<int>::const_iterator it = list.begin(); it != list.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main(){

    std::list<int> list;
    list.push_back(40);
    list.push_back(20);
    list.push_back(10);
    list.push_back(30);

    printList(list);
    list.reverse();
    printList(list);

    list.sort();
    printList(list);
    list.sort(myCompare);
    printList(list);

    return 0;
}