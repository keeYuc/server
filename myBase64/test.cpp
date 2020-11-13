#include"myBase64.hpp"
#include<iostream>
#include<string>


int main()
{

    std::string abc = "      asdas                 dadad          ";
    std::cout << abc.size() << std::endl;
    auto str=base64Encode(abc.data(), abc.size(), false);
    printf("[%s][%ld]\n",str,strlen(str)+1);

    return 0;
}