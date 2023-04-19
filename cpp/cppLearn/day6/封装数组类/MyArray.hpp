//实现一个通用数组
//可以对内置数据类型以及自定义数据类型的数据存储
//将数组中的数据存储到堆区
//构造函数中传入数组的容量
//提供对应的拷贝函数以及operator=防止浅拷贝的问题
//提供尾插法和尾删法对数组中的数据进行增加和删除
//可以通过下标的方式访问数组中的元素
//可以获取数组中当前元素个数和数组的容量
#include <iostream>

template<typename T>
class MyArray{

public :

    MyArray(int capacity){

        this->size = 0;
        this->capacity = capacity;
        this->address = new T[this->capacity];
    }
    MyArray(const MyArray& array){

        this->capacity = array.capacity;
        this->size     = array.size;
        this->address  = new T[array.capacity];

        for(int i = 0; i < array.size; i++){

            this->address[i] = array.address[i];
        }
    }
    ~MyArray(){

        if(this->address != nullptr){

            delete[] address;
        }
        address = nullptr;
    }
    MyArray& operator=(const MyArray& array){

        if(this->address != nullptr){

            delete[] address;
            this->capacity = 0;
            this->size     = 0;
        }
        address = nullptr;
        this->capacity = array.capacity;
        this->size     = array.size;
        this->address  = new T[array.capacity];

        for(int i = 0; i < array.size; i++){

            this->address[i] = array.address[i];
        }

        return *this;
    }

    void push_back(const T& value){

        if(this->size == this->capacity){

            return;
        }
        this->address[this->size] = value;
        this->size++;
    }

    void pop_back(){

        if(this->size == 0){
            
            return;
        }
        this->size--;
    }

    T& operator[](int index){

        return this->address[index];
    }

    int getCapacity(){

        return this->capacity;
    }

    int getSize(){

        return this->size;
    }
private:

    int size;
    int capacity;
    T* address;
};