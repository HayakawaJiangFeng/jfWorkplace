#include <iostream>
#include <vector>

class transForm
{
public :

  int operator()(int num)
  {
    return num;
  }
};

class myPrint
{
public :

  void operator()(int num)
  {
    std::cout << num << " ";
  }
};

int main()
{
  std::vector<int> v1;
 
  for(int i = 0; i < 10 ; i++)
  {
    v1.push_back(i);
  }
  std::vector<int> v2;
  v2.resize(v1.size());
  std::transform(v1.begin(),v1.end(),v2.begin(),transForm());

  std::for_each(v2.begin(),v2.end(),myPrint());
  std::cout << std::endl;

  return 0;
}
