#include <iostream>
#include <map>

void printMap(const std::map<std::string, int> &m1){

    for(std::map<std::string, int>::const_iterator it = m1.begin(); it != m1.end(); it++){

        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
    std::cout << std::endl;
}
int main(){

    std::map<std::string, int> m1;
    std::map<std::string, int> m2;

    for(int i = 0; i < 5; i++){

        char c = 'A' + i;
        std::string key(1,c);
        m1.insert(std::make_pair(key, i));
    }
    for(int i = 5; i < 10; i++){

        char c = 'A' + i;
        std::string key(1,c);
        m2.insert(std::make_pair(key,i));
    }

    printMap(m1);
    std::cout << std::endl;
    printMap(m2);

    std::cout << m1.size() << ' ' << m2.size() << std::endl;

    std::swap(m1, m2);

    printMap(m1);
    std::cout << std::endl;
    printMap(m2);

    return 0;
}