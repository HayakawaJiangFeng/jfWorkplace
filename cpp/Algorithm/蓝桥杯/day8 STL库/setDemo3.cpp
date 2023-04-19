#include <iostream>
#include <set>

struct People
{
    int p_height;
    int p_weight;
    int p_age;

    People(int height, int weight, int age) : p_height(height), p_weight(weight), p_age(age){

    }

    bool operator<(const People& people) const{

        if(p_height == people.p_height){

            if(p_weight == people.p_weight){

                return p_age < people.p_age;
            }else{
                
                return p_weight < people.p_weight;
            }
        }else{

            return p_height < people.p_height;
        }
    }
};

std::set<People> peoples;
int main(){

    int n, m;
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++){

        int height;
        int weight;
        int age;
        std::cin >> height >> weight >> age;

        peoples.insert(People(height,weight,age));
    }

    for(int i = 0; i < m; i++){

        int height;
        int weight;
        int age;
        std::cin >> height >> weight >> age;

        if(peoples.count(People(height,weight,age))){

            std::cout << "yes" << std::endl;
        }else{

            std::cout << "no" << std::endl;
        }
    }
    return 0;
}