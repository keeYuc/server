#include<iostream>


int main()
{
   auto a= []()->int
    {
        std::cout << "fuck" << std::endl;
        return 100;
    }();
    std::cout << a << std::endl;;
    return 0;
}