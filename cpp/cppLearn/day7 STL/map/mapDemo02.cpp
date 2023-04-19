#include <iostream>
#include <map>

class MyCompare{

public :

    bool operator()(int x, int y) const{

        return x > y;
    }
};

int main(){

    std::map<int, int,MyCompare> m1;

    for(int i = 0; i < 10; i++){

        m1.insert(std::make_pair(i,10 + i));
    }
    for(std::map<int, int, MyCompare>::const_iterator it = m1.begin(); it != m1.end(); it++){

        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}