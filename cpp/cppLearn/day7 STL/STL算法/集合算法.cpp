#include <algorithm>
#include <iostream>
#include <vector>

class myPrint
{
public:

    void operator()(int num)
    {
        std::cout << num << " ";
    }
};
int main()
{
    //要求两个集合是有序的
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3; //交集
    std::vector<int> v4; //并集
    std::vector<int> v5; //差集

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    v3.resize(std::min(v1.size(),v2.size()));
    v4.resize(v1.size(),v2.size());
    v5.resize(std::max(v1.size(),v2.size()));

    std::vector<int>::iterator end1 = std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    std::vector<int>::iterator end2 = std::set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v4.begin());
    std::vector<int>::iterator end3 = std::set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v5.begin());


    std::for_each(v3.begin(),end1,myPrint());
    puts("");

    std::for_each(v4.begin(),end2,myPrint());
    puts("");

    std::for_each(v5.begin(),end3,myPrint());
    puts("");

    return 0;
}