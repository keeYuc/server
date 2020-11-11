#include"../src/mes.hpp"
#include"../proto/hand.pb.h"
#include<fstream>
#include<string.h>
#include<stdio.h>



int main()
{
    mySocket s;hand hand;







    int fd = accept(s.myListen(), nullptr, nullptr);
    char buff[8];
    bzero(buff, 8);
    read(fd, buff, 8);//!
    int n = atoi(buff);
    std::cout << "proto文件字节数" << n << std::endl;
    char proto[n];
    read(fd, proto, n);//!
    hand.ParseFromString(proto);
    int size = hand.size();
    int xxx = size;
    int have_read = 0;
    int read_max = 1024 * 512;
    auto name = hand.name();
    std::cout << "文件字节数" << size << std::endl;
    std::cout << "文件名" << name << std::endl;
    char pathname[16];
    sprintf(pathname, ".//photo//%s", name.data());
    std::fstream file;
    file.open(pathname, std::ios::out | std::ios::binary);

    //while (xxx > 0)
    {
        char buff[read_max];
        bzero(buff, read_max);
        int n = read(fd, buff, read_max);//!
        have_read += n;
        xxx -= n;
        file.write(buff, n);
        printf("-----剩余[%d]-----这次读了[%d]------一共读了[%d]\n", xxx, n, have_read);
    }
    file.close();
    printf("-----剩余[%d]-----这次读了[%d]------一共读了[%d]\n", xxx, n, have_read);

    return 0;
}