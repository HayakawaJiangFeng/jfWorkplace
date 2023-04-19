#include <iostream>
#include <functional>


void test01()
{
    std::negate<int> n;
    std::cout << n(10) << std::endl;

    std::plus<int> p;
    std::cout << p(10,20) << std::endl;

    std::minus<int> j;
    std::cout << j(20,10) << std::endl;

    std::multiplies<int> m;
    std::cout << m(10,20) << std::endl;

    std::divides<int> d;
    std::cout << d(20,10) << std::endl;

    std::modulus<int> mo;
    std::cout << mo(1314,100) << std::endl;
}
int main()
{
    test01();

    return 0;
}