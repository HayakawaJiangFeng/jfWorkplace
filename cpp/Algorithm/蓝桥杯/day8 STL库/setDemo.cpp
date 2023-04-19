#include <iostream>
#include <set>

//集合不存在重复元素
int main(){

    std::set<char> ch;

    for(int i = 0; i < 26; i++){

        ch.insert((char)i + 65);
    }

    ch.insert('A');
    //删除Z
    ch.erase('Z');

    for(std::set<char>::iterator it = ch.begin(); it != ch.end(); it ++){

        std::cout << *it << " ";
    }
    int flag = ch.count('B');
    if(flag){

        std::cout << "y" << std::endl;
    }else{

        std::cout << "n" << std::endl;
    }
    std::cout << std::endl;
    ch.clear();
    return 0;
}