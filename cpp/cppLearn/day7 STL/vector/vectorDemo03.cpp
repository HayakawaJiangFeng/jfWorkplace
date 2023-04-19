#include <iostream>
#include <vector>

int main(){

    std::vector<std::vector<int> > v1;

    std::vector<int> vv1;
    std::vector<int> vv2;
    std::vector<int> vv3;

    for(int i = 0; i <= 3; i++){

        vv1.push_back(i);
        vv2.push_back(i);
        vv3.push_back(i);
    }
    v1.push_back(vv1);
    v1.push_back(vv2);
    v1.push_back(vv3);

    for(std::vector<std::vector<int> >::iterator it = v1.begin(); it != v1.end(); it++){

        for(std::vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++){

            std::cout << *it1 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}