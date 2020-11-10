#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<openssl/rsa.h>
#include<fstream>
#include<string.h>
#include<cstdlib>



int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
    connect(fd, (sockaddr*) &addr, sizeof(addr));//
    std::fstream file("./timg.jpg", std::ios::in | std::ios::binary);
    file.seekg(0, file.end);
    int n = file.tellp();
    // char buff[n];
    // 
    file.seekg(0, std::ios::beg);
    char buff[n];

    file.read(buff, n);
    std::cout << n;

    char a[8];
    // char b[n];
    bzero(a, 8);
    // bzero(b, n);
    sprintf(a, "%d", n);
    write(fd, a, 8);
    write(fd, buff, n);



    return 0;
}