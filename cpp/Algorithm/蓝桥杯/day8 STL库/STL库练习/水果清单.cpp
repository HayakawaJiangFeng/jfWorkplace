#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::map<std::string, int> > m1;

int main(){

    int num,d;
    std::cin >> num;
    std::string s1,s2;

    for(int i = 0; i < num; i++){

        std::cin >> s1 >> s2 >> d;

        m1[s2][s1] += d;
    }
    for(std::map<std::string, std::map<std::string, int> >::iterator it = m1.begin(); it != m1.end(); it++){

        std::cout << it->first << std::endl;
        
        for(std::map<std::string, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++){

            std::cout << "\t|----" << it1->first << "(" << it1->second << ")" << std::endl;
        }
    }

    return 0;
}