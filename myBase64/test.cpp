#include"myBase64.hpp"
#include<iostream>
#include<string>


int main()
{

    std::string abc = "      asdas                 dadad          ";
    printf("[%s][%ld]\n", abc.data(), abc.size());
    std::cout << abc.size() << std::endl;
    auto str = base64Encode(abc.data(), abc.size(), false);
    auto str1 = base64Decode(str, strlen(str) + 1, false);//!decode需要strlen+1
    printf("[%s][%ld]\n", str1, strlen(str1));          //*之后【不需要】strlen+1

    return 0;
}