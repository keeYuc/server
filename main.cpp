// #include<iostream>
// #include<sys/socket.h>
// #include<netinet/in.h>
// #include<arpa/inet.h>
// #include<unistd.h>


// int main()
// {
//     // int fd = socket(AF_INET, SOCK_STREAM, 0);
//     // int a = 1;
//     // setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(int));
//     // sockaddr_in addr;
//     // addr.sin_port = htons(18888);
//     // inet_pton(AF_INET, "192.168.233.129", &addr.sin_addr.s_addr);
//     // addr.sin_family = AF_INET;
//     // int a1 = bind(fd, (sockaddr*) &addr, sizeof(addr));
//     // if (a1 != 0)
//     // {
//     //     std::cout << "bind err![" << a1 << "]\n";
//     //     return -1;
//     // }
//     int fd = socket(AF_INET, SOCK_STREAM, 0);
//     sockaddr_in addr;
//     addr.sin_family = AF_INET;
//     addr.sin_port = htons(8888);
//     inet_pton(AF_INET, "127,0,0.1", &addr.sin_addr.s_addr);
//     //port overuse
//     int a = 1;
//     setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(int));
//     int a1 = bind(fd, (sockaddr*) &addr, sizeof(addr));
//     if (a1 != 0)
//     {
//         std::cout << "bind err![" << a1 << "]\n";
//         return -1;
//     }

//     listen(fd, 5);
//     int xfd = accept(fd, nullptr, nullptr);
//     while (1)
//     {
//         char buff[1024];
//         int a = read(fd, buff, 1024);
//         if (a <= 0)
//         {
//             return 0;
//         }
//         printf("[%s\n]", buff);
//     }


//     return 0;
// }
// #include"/home/keeyu/mycode/server/classSocket/src/mySocket.hpp"
// #include<iostream>

// int main()
// {
//     mySocket a;


// }
#include<fstream>
#include<string>
#include"/home/keeyu/mycode/server/classSocket/src/mySocket.hpp"
#include<string.h>


int main()
{
    std::fstream rfd("./abc.jpg", std::ios::in | std::ios::binary);
    //std::fstream wfd("./abc1.jpg", std::ios::app | std::ios::binary);
    mySocket socket;
    int fd = accept(socket.myListen(), nullptr, nullptr);
    char buff[1024];
    while (1)
    {
        bzero(buff, 1024);
        int n = read(fd, buff, 1024);
        printf("%s", buff);
    }


}


