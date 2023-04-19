#include <iostream>

//全局函数作为友元
class Person{

    friend void visit(Person *person);
    public :
        
        std::string public_room = "public_room";
    
    private :

        std::string private_room = "private_room";
};

void visit(Person *person){

    std::cout << person->public_room << std::endl;
    std::cout << person->private_room << std::endl;
}

int main(){

    Person p1;
    visit(&p1);
    
    return 0;
}