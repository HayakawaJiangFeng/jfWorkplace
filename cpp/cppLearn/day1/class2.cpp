#include <iostream>

//成员属性私有化,可以控制读写权限
//写权限可以控制数据的有效性

class People{

    private:
        std::string people_name;
        int people_id;
    public:
        void set_name(std::string name){

            people_name = name;
        }
        std::string get_name(){

            return people_name;
        }
        void set_id(int id){

            if(id < 0 || id > 150){

                std::cout << "ERROR" << std::endl;
            }else{

                people_id = id;
            }
        }
        int get_id(){

            return people_id;
        }
};

int main(){

    People p;
    p.set_id(160);
    p.set_id(18);
    std::cout << p.get_id() << std::endl;

    p.set_name("luna");
    std::cout << p.get_name() << std::endl;

}