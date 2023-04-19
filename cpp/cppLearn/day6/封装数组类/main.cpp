#include "MyArray.hpp"

void test01(){

    MyArray<int> array(5);
    MyArray<int> array1(array);
    MyArray<int> array2(100);
    array2 = array1;
}

void test02(){

    MyArray<int> array3(5);

    for(int i = 0; i < 5; i++){

        array3.push_back(i);
    }
    for(int i = 0; i < 5; i++){
        
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "capacity : " << array3.getCapacity() << std::endl;
    std::cout << "size     : " << array3.getSize() << std::endl;

    array3.pop_back();

    std::cout << "capacity : " << array3.getCapacity() << std::endl;
    std::cout << "size     : " << array3.getSize() << std::endl;
}
int main(){

    //test01();
    test02();

    return 0;
}