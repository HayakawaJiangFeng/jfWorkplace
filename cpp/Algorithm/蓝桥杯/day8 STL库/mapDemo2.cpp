#include <iostream>
#include <map>

int main(){

    std::map<int, std::map<std::string, int> >info;

    int number;
    std::cin >> number;

    for(int i = 0; i < number; i++){

        int class_id;
        std::string name;

        std::cin >> class_id >> name;
        info[class_id][name]++;
    }

    for(std::map<int, std::map<std::string, int> >::iterator it = info.begin(); it != info.end(); it++){

        for(std::map<std::string, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++){
            
            std::cout << "There are " << it1->second << "people name " << it1->first << "in class " << it->first << std::endl;  
        }
    } 
}