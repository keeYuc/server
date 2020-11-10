#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<openssl/rsa.h>
#include<fstream>


int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
    connect(fd, (sockaddr*) &addr, sizeof(addr));
    write(fd, "da", 3);







    return 0;
}