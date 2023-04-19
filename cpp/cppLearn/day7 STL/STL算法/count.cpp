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

    bool operator==(const Robot &r)
    {
        if(r.id == this->id && r.date == this->date) return true;
        else return false;
    }
    
    int id;
    int date;
};

int main()
{
    std::vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int cnt = std::count(v.begin(), v.end(),5);
    std::cout << cnt << std::endl;

    std::vector<Robot> vR;
    Robot r1(1,2);
    Robot r2(3,4);
    Robot r3(4,5);
    Robot r4(3,4);

    vR.push_back(r1);
    vR.push_back(r2);
    vR.push_back(r3);


    int num = std::count(vR.begin(), vR.end(), r2);
    std::cout << num << std::endl;

    return 0;
}