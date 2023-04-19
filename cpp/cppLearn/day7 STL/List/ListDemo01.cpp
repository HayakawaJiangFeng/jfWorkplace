#include <iostream>
#include <list>

void printList(std::list<int> &list){
    
    for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){

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

    std::list<int> list2(list.begin(),list.end());
    printList(list2);

    std::list<int> list3(list2);
    printList(list3);

    std::list<int> list4(13,1314);
    printList(list4);

    list4 = list;
    printList(list4);

    list4.assign(14,902);
    printList(list4);

    list4.assign(list.begin(),list.end());
    printList(list4);

    list.assign(10,1);
    list2.assign(10,2);
    printList(list);
    printList(list2);
    list.swap(list2);
    printList(list);
    printList(list2);

    return 0;
}