#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class Person{

public :    

    Person(std::string name, int score){

        this->name = name;
        this->score = score;
    }

    std::string name;
    int score;
};

int main(){

    Person A("A",100);
    Person B("B",90);
    Person C("C",10);
    Person D("D",70);
    Person E("E",60);

    std::vector<Person> v1;
    v1.push_back(A);
    v1.push_back(B);
    v1.push_back(C);
    v1.push_back(D);
    v1.push_back(E);

    std::deque<int> d1;
    for(std::vector<Person>::iterator it = v1.begin(); it != v1.end(); it++){

        d1.push_back(it->score);
    }

    std::sort(d1.begin(),d1.end());
    d1.pop_back();
    d1.pop_front();

    int sum = 0;
    for(std::deque<int>::iterator it = d1.begin(); it != d1.end(); it++){

        sum += *it;
    }

    std::cout << sum / 3 << std::endl;

    return 0;
}