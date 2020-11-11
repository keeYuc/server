#include"../src/mes.hpp"
#include"../proto/hand.pb.h"



int main()
{
    mySocket s;hand hand;
    int fd = accept(s.myListen(), nullptr, nullptr);
    char buff[8];
    bzero(buff, 8);
    read(fd, buff, 8);
    int n = atoi(buff);
    std::cout << "proto文件字节数" << n << std::endl;
    char proto[n];
    read(fd, proto, n);
    hand.ParseFromString(proto);
    int size = hand.size();
    std::cout << "文件字节数" << size << std::endl;









    return 0;
}