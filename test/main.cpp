#include"../src/mes.hpp"
#include"../proto/hand.pb.h"
#include<fstream>
#include<string.h>
#include<sys/epoll.h>
#include<stdio.h>



int main()
{

    mySocket s;
    int tree = epoll_create(1024);
    epoll_event event;
    epoll_event events[1024];
    event.events = EPOLLIN;
    int fd = s.myListen();

    event.data.fd = fd;
    epoll_ctl(tree, EPOLL_CTL_ADD, fd, &event);
    while (1)
    {
    abc:
        int n = epoll_wait(tree, events, 1025, -1);
        for (int i = 0;i < n;i++)
        {
            int x = events[i].data.fd;
            if (x == fd)
            {
                printf("one link\n");
                //*test
                int afd = accept(fd, nullptr, nullptr);
                epoll_event event1;
                event1.events = EPOLLIN;
                event1.data.fd = afd;
                epoll_ctl(tree, EPOLL_CTL_ADD, afd, &event1);
                //*accept thread
            } else
            {
                //*test
                mySocket s;hand hand;
                fd = events[i].data.fd;
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
<<<<<<< HEAD
<<<<<<< HEAD
                int read_max = 1024 * 1024;
=======
                int read_max = 1024 * 512;
>>>>>>> d5468c7b703f96d4999820f1f85d5f085c2c965b
=======
                int read_max = 1024 * 512;
>>>>>>> d5468c7b703f96d4999820f1f85d5f085c2c965b
                auto name = hand.name();
                std::cout << "文件字节数" << size << std::endl;
                std::cout << "文件名" << name << std::endl;
                char pathname[16];
                sprintf(pathname, ".//photo//%s", name.data());
                std::fstream file;
                file.open(pathname, std::ios::out | std::ios::binary);

                while (xxx > 0)
                {
                    char buff[read_max];
                    bzero(buff, read_max);
                    int n = read(fd, buff, read_max);//!
                    if (n <= 0)
                    {
                        printf("-----剩余[%d]-----这次读了[%d]------一共读了[%d]\n", xxx, n, have_read);
                        file.close();
                        epoll_ctl(tree, EPOLL_CTL_DEL, x, &events[i]);
                        return 0;
                    }
                    have_read += n;
                    xxx -= n;
                    file.write(buff, n);
                    printf("-----剩余[%d]-----这次读了[%d]------一共读了[%d]\n", xxx, n, have_read);
                }
                file.close();
                //printf("-----剩余[%d]-----这次读了[%d]------一共读了[%d]\n", xxx, n, have_read);
                epoll_ctl(tree, EPOLL_CTL_DEL, x, &events[i]);
                return 0;




                //printf("%s\n", temp);

            //*trans thread

            }
        }
    }


}


