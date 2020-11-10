#ifndef MYSOCKET_HPP
#define MYSOCTET_HPP
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<openssl/rsa.h>
#include<sys/epoll.h>
//*epoll支持的最大连接数
#define Max 1024
class myEpoll
{
    int tree;
    int trans_fd;
    void(*accept_Coll)(void*);
    void(*trans_Coll)(void*);
    epoll_event* trans_Event;
    epoll_event* accept_Event;
    epoll_event eventList[Max + 1];

public:
    myEpoll()
    {
        tree = epoll_create(Max);
    }
    //*epoll反应堆连接/传输初始化设置回调函数
    void init(int fd, void(*accept_Coll)(void*), void(*trans_Coll)(void*))
    {
        trans_fd = fd;
        void(*accept_Coll)(void*) = accept_Coll;
        void(*trans_Coll)(void*) = trans_Coll;
    }
    int wait(int time = -1)
    {
        int temp = 0;
        int n = epoll_wait(tree, eventList, Max, time);
        if (n <= 0)
        {
            temp = n;
        }
        return temp;

    }
    ~myEpoll()
    {
        if (trans_Event != nullptr)
        {
            delete trans_Event;
        }
        if (accept_Event != nullptr)
        {
            delete accept_Event;
        }

    }
    void free_Event(epoll_event* e)
    {
        if (e != nullptr)
        {
            delete e;
        }
    }

};
class mySocket
{
    int unKnow = 1;
    int fd;
    int err;
    int maxListen;
    sockaddr_in addr;

public:
    //*默认ipv4 tcp 127.1 5888 1024(最大连接数)   参数依次为ipv4/ipv6 tcp/udp IP port listen_Max
    mySocket(int __domain = AF_INET, int __type = SOCK_STREAM, std::string ip = "127.0.0.1", int port = 5555, int max = 1024, int __protocol = 0)
    {
        this->maxListen = max;
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
        listen(fd, maxListen);
        return fd;
    }

};
#endif