#include"../src/mes.hpp"
#include"../proto/hand.pb.h"
#include<fstream>
#include"myBase64.hpp"
int main()
{
    int  fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
    connect(fd, (sockaddr*) &addr, sizeof(addr));

    std::fstream file("./abc.txt", std::ios::in | std::ios::binary);//!------------

    file.seekg(0, std::ios::end);
    int size = file.tellg();
    std::cout << size << std::endl;
    file.seekg(0, std::ios::beg);
    // //*-------------------------------------------
    hand hand;

    hand.set_name("ff.png");//!--------------------------------------------
    hand.set_size(size);
    std::string string_Hand;//*文件头
    hand.SerializeToString(&string_Hand);
    int size_hand = string_Hand.size();
    std::cout << "proto文件字节数" << size_hand << std::endl;
    char hand1[size_hand];//*proto 数据
    memcpy(hand1, string_Hand.data(), size_hand);                 //*pro文件里面有真实文件长度               
    //printf("%d\n", size_hand);                      //*pro文件长度/pro文件/真实文件                       
    char protostring[8];//*proto 告诉服务器文件的长度     xxxxppppppdddddddddd
    sprintf(protostring, "%d", size_hand);
    write(fd, protostring, 8);//!写xxxx
    write(fd, hand1, size_hand);//!写ppppp
    //sleep(1);
    // //!写真实文件

    int max = 9000;

    int sum = 0;        //总传送数
    int xxx = size;
    int size_n = 0;
    //剩余字符数
    printf("sum[%d]---xxx[%d]\n", sum, xxx);
    std::fstream file1("./abc1.txt", std::ios::out | std::ios::binary);
    while (max < xxx)
    {

        char buff[max];
        bzero(buff, max);
        file.read(buff, max);
        auto a = base64Encode(buff, sizeof(buff), false);
        auto b = base64Decode(a, strlen(a), false);
        file1.write(b, strlen(b) + 1);
        size_n += strlen(a);
        write(fd, buff, max);
        sum += max;
        xxx -= max;
        //sleep(1);
        printf("----原始总字符总数[%d]--编码后字符总数[%d]--sum[%d]-----剩余[%d]\n", size, size_n, sum, xxx);


    }

    char buff[xxx];
    bzero(buff, xxx);
    file.read(buff, xxx);
    auto a = base64Encode(buff, sizeof(buff), false);
    auto b = base64Decode(a, strlen(a), false);
    file1.write(b, strlen(b) + 1);
    size_n += strlen(a);
    write(fd, buff, xxx);
    sum += xxx;
    xxx -= xxx;
    printf("----原始总字符总数[%d]--编码后字符总数[%d]--sum[%d]-----剩余[%d]\n", size, size_n, sum, xxx);
    file1.close();
    file.close();
}