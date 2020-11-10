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
// #define Max 1024
// class myEpoll
// {
//     int tree;
//     int trans_fd;
//     void(*accept_Coll)(void*);
//     void(*trans_Coll)(void*);
//     epoll_event* trans_Event;
//     epoll_event* accept_Event;
//     epoll_event eventList[Max + 1];

// public:
//     myEpoll(int fd, void(*accept_Coll)(void*))
//     {
//         tree = epoll_create(Max);
//         trans_fd = fd;
//         this->accept_Coll = accept_Coll;
//         trans_Event = new epoll_event;
//         trans_Event->events = EPOLLIN;
//         trans_Event->data.fd = fd;
//         trans_Event->data.ptr = (void*) trans_Coll;
//         epoll_ctl(tree, EPOLL_CTL_ADD, fd, trans_Event);
//     }
//     void trans_Coll(void* temp)
//     {
//         printf("one link\n");
//         int message_fd = accept(trans_fd, nullptr, nullptr);
//         accept_Event = new epoll_event;
//         accept_Event->events = EPOLLIN;
//         accept_Event->data.fd = message_fd;
//         accept_Event->data.ptr = (void*) accept_Coll;
//     }
//     //*epoll反应堆连接/传输初始化设置回调函数
//     void wait(int time = -1)
//     {
//         while (1)
//         {
//             int n = epoll_wait(tree, eventList, Max, time);
//             if (n <= 0)
//             {
//                 printf("epoll_wait err!");
//             }
//             for (int i = 0;i < n;i++)
//             {
//                 auto func = (void(*)(void*))eventList[i].data.ptr;
//                 func(nullptr);
//             }
//         }

//     }
//     ~myEpoll()
//     {
//         if (trans_Event != nullptr)
//         {
//             delete trans_Event;
//         }
//         if (accept_Event != nullptr)
//         {
//             delete accept_Event;
//         }

//     }
//     void free_Event(epoll_event* e)
//     {
//         if (e != nullptr)
//         {
//             delete e;
//         }
//     }

// };
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
        //printf("one link");
        listen(fd, maxListen);
        
        return fd;
    }

};
#endif