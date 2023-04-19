#include <iostream>

//继承方式
class Father{

    public:

        int public_data;
    
    protected:

        int protected_data;

    private:

        int private_data;
};

//公开继承
//父类除了private，其他访问权限不变
class Son1 : public Father{

    public:

        Son1(int data1,int data2){

            public_data = data1;
            protected_data = data2;
        }
};

//保护继承
//父类除了private，其他访问权限全部变为protected
class Son2 : protected Father{

    public:

        Son2(int data1, int data2){

            public_data = data1;
            protected_data = data2;
        }
};

//私有继承
//父类中全部访问权限变为private
class Son3 : private Father{

    public:

        Son3(int data1, int data2){

            public_data = data1;
            protected_data = data2;
        }
};

int main(){

    Son1 son1(1,2);
    Son2 son2(3,4);
    Son3 son3(5,6);

    return 0;
}