#include <vector>
#include <iostream>
#include <algorithm>

//普通函数
void print1(int num)
{
    std::cout << num << " ";
}

//仿函数
class print2
{
public : 
    void operator()(int num)
    {
        std::cout << num << " ";
    }
};

int main()
{
    std::vector<int> v;

    for(int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }

    std::for_each(v.begin(),v.end(),print1);
    std::cout << std::endl;

    std::for_each(v.begin(),v.end(),print2());
    std::cout << std::endl;

    return 0;
}