#include "Person.hpp"

int main(){

    Person<std::string,int> p1("jiangfeng",18);
    p1.showInfo();

    return 0;
}