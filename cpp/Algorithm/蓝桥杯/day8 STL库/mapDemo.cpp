#include <iostream>
#include <map>
#include <utility>

//map是按照关键字的字典序进行从小到大遍历的

int main(){

    std::map<std::string, int> dict;
    
    dict.insert(std::make_pair("luna",1));
    dict.insert(std::make_pair("jiangfeng",2));
    dict.insert(std::make_pair("kisara",3));

    if(dict.count("luna")){

        std::cout << "luna num = " << dict["luna"] << std::endl;
    }

    for(std::map<std::string, int>::iterator it = dict.begin(); it != dict.end(); it++){

        std::cout << it->first << "--->" << it->second << std::endl;
    }
    return 0;
}