#include<iostream>



int main()
{
    int temp;

    while (temp != 99)
    {
        std::cin >> temp;
        int index = temp % 7;
        if (index == 0)
        {
            index = 1;
        }
        std::cout << index << std::endl;
    }

    return 0;
}