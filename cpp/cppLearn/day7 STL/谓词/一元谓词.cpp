#include <iostream>
#include <vector>

struct BiggerThenFive
{
    bool operator()(int num)
    {
        return num > 5;
    }
};


int main()
{
    std::vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    std::vector<int>::iterator it = std::find_if(v.begin(),v.end(),BiggerThenFive());

    if(it == v.end())
    {
        std::cout << "cant find" << std::endl;
    }
    else
    {
        std::cout << "first bigger then 5 number is " << *it << std::endl;
    }

    return 0;
}