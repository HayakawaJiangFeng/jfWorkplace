#include <iostream>
#include <set>

struct Node
{
    int x,y;
    bool operator< (const Node &rhs) const{

        if(x == rhs.x){

            return y < rhs.y; 
        }else{

            return x < rhs.x;
        }
    }  
};

int main(){

    //set自动排序，从下到大
    std::set<int> s1;
    
    s1.insert(3);
    s1.insert(1);
    s1.insert(2);

    for(std::set<int>::iterator it = s1.begin(); it != s1.end(); it++){

        std::cout << *it << std::endl;
    }

    int num;
    std::cin >> num;

    std::set<Node> nodes;
    for(int i = 0; i < num; i++){

        Node node;
        std::cin >> node.x >> node.y;
        nodes.insert(node);
    }

    for(std::set<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){

        std::cout << (*it).x << " " << (*it).y << std::endl;
    }
    return 0;
}