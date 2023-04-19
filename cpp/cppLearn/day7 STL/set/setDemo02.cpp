#include <iostream>
#include <set>

void printSet(const std::set<int> &s){

    for(std::set<int>::const_iterator it = s.begin(); it != s.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main(){

    std::set<int> s1;
    std::set<int> s2;
    
    //插入
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s2.insert(s1.begin(),s1.end());

    printSet(s2);
    //删除指定元素
    s2.erase(20);
    printSet(s2);

    s2.erase(s2.begin(),s2.end());
    printSet(s2);

    //寻找特定元素，有则返回迭代器
    if(s1.find(10) == s1.begin()){

        std::cout << "yes" << std::endl;
    }else{

        std::cout << "no" << std::endl;
    }

    //判断元素是否存在
    int flag = s1.count(30);
    std::cout << flag << std::endl;

    //获取第一个大于等于某值的迭代器
    std::set<int>::iterator first =  s1.lower_bound(20);

    //计算这个元素中set中的位置
    int pos = std::distance(s1.begin(),first);
    std::cout << pos << std::endl;

    //获取第一个大于某值的迭代器
    std::set<int>::iterator second = s1.upper_bound(20);

    int pos1 = std::distance(s1.begin(), second);
    std::cout << pos1 << std::endl;

    return 0;
}