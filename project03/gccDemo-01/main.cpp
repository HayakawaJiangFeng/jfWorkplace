#include <swap.h>
#include <iostream>

int main()
{
  int num1 = 0;
  int num2 = 0;
  
  std::cout << "please enter two number : " << std::endl;

  std::cin >> num1 >> num2;

  std::cout << "before : " << std::endl << "num1 : " << num1 << std::endl  << "num2 : " << num2 << std::endl;

  swap(num1, num2);

  std::cout << "after : " << std::endl << "num1 : " << num1 << std::endl  << "num2 : " << num2 << std::endl;

  return 0;
}