#ifndef MYSOCKET_HPP
#define MYSOCTET_HPP
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<openssl/rsa.h>

class mySocket
{
    int unKnow = 1;
    int fd;
    int err;
    int max;
    sockaddr_in addr;

public:
    //*默认ipv4 tcp 127.1 5888 1024(最大连接数)   参数依次为ipv4/ipv6 tcp/udp IP port listen_Max
    mySocket(int __domain = AF_INET, int __type = SOCK_STREAM, std::string ip = "127.0.0.1", int port = 5555, int max = 1024, int __protocol = 0)
    {
        this->max = max;
        fd = socket(__domain, __type, __protocol);
        addr.sin_family = __domain;
        addr.sin_port = htons(port);
        inet_pton(__domain, ip.data(), &addr.sin_addr.s_addr);
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &unKnow, sizeof(int));
        int temp = bind(fd, (sockaddr*) &addr, sizeof(addr));
        if (temp != 0)
        {
            err = temp;
        }
    }
    int myListen()
    {
        listen(fd, max);
        return fd;
    }
    int getFd()
    {
        return fd;
    }

};
#endif