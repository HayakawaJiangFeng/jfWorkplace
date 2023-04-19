#include <iostream>
#include <vector>
#include <cstdio>

//动态数组vector
//push_back 插入元素

int main(){

    std::vector<int> vec;

    //使用构造函数初始化vector,第一个参数是长度，第二个参数是值
    std::vector<int> vec1(10,1);
    
    for(int i = 1; i <= 10; i++){

        vec.push_back(i);
    }

    for(int i = 0; i < vec.size(); i++){

        std::cout << vec[i] << std::endl; 
    }

    for(int i = 0; i < vec1.size(); i++){

        std::cout << vec1[i] << std::endl;
    }

    //清空vector但是不能清空vector的内存
    vec.clear();

    //清空vector的内存
    std::vector<int>().swap(vec);

    return 0;
}