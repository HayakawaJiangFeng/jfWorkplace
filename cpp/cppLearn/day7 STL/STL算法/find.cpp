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

  bool operator==(const Robot &r1) const
  {
    if(r1.id == this->id && r1.date == this->date)
    {
      return true;
    }
    return false;
  }

  int id;
  int date;
};

void test01()
{
  std::vector<int> v;
  for(int i = 0; i < 10; i++)
  {
    v.push_back(i);
  }
  std::vector<int>::iterator it = std::find(v.begin(),v.end(),5);
  if(it == v.end())
  {
    std::cout << "cant find" << std::endl;
  }
  else
  {
    std::cout << "index = " << *it << std::endl;
  }
}

void test02()
{
  std::vector<Robot> v1;
  Robot r1(1,2);
  Robot r2(3,4);
  Robot r3(5,6);

  v1.push_back(r1);
  v1.push_back(r2);
  v1.push_back(r3);
  Robot r4(3,4);

  std::vector<Robot>::iterator it = std::find(v1.begin(), v1.end(), r4);
  if(it == v1.end())
  {
    std::cout << "cant find" << std::endl;
  }
  else
  {
    std::cout << (*it).id << " " << (*it).date << std::endl;
  }
}

int main()
{
  // test01();
  test02();

  return 0;
}
