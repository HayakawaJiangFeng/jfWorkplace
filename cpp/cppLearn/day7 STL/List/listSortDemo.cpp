#include <iostream>
#include <list>

class Product{

public:
    Product(int id, int year){

        this->id = id;
        this->year = year;
    }

    int id;
    int year;
};

void printList(const std::list<Product> &list){

    for(std::list<Product>::const_iterator it = list.begin(); it != list.end(); it++){

        std::cout << "id = " << it->id << " " << "year = " << it->year << std::endl;
    }
    std::cout << std::endl;
}

bool myCompare(const Product &p1, const Product &p2){

    if(p1.id == p2.id){

        return p1.year < p2.year;
    }else{

        return p1.id < p2.id;
    }
}
int main(){

    std::list<Product> list;
    
    list.push_back(Product(1,2001));
    list.push_back(Product(1,2003));
    list.push_back(Product(2,2004));
    list.push_back(Product(3,2001));
    list.push_back(Product(3,2012));
    list.push_back(Product(3,2001));
    list.push_back(Product(7,2013));
    list.push_back(Product(2,2017));

    list.sort(myCompare);

    printList(list);

    return 0;
}