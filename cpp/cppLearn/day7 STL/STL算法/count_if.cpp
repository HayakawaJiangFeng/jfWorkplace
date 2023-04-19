#include <vector>
#include <iostream>
#include <algorithm>

class Robot
{
public : 

    Robot(int id, int date)
    {
        this->id = id;
        this->date = date;
    }
    int id;
    int date;
};
class BiggerThenZero1
{
public :

    bool operator()(const Robot &r)
    {
        return r.date > 0;
    }
};

class BiggerThenZero
{
public : 

    bool operator()(int num)
    {
        return num > 0;
    }
};

int main()
{
    std::vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    int num = std::count_if(v1.begin(), v1.end(), BiggerThenZero());
    std::cout << num << std::endl;

    std::vector<Robot> v2;
    Robot r1(1,2);
    Robot r2(3,4);
    Robot r3(5,6);
    Robot r4(7,8);
    v2.push_back(r1);
    v2.push_back(r2);
    v2.push_back(r3);
    v2.push_back(r4);

    int num1 = std::count_if(v2.begin(), v2.end(), BiggerThenZero1());
    std::cout << num1 << std::endl;

    return 0;
}