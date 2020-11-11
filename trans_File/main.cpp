#include"./src/mes.hpp"
#include<pthread.h>
#include<string.h>
#include<stdio.h>
#include<fstream>



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
                char buff[1024];

                while (1)
                {

                    bzero(buff, 8);
                    n = read(x, buff, 8);
                    int q = atoi(buff);
                    printf("%d\n", q);
                    char temp[q];
                    bzero(temp, q);
                    n = read(x, temp, q);
                    printf("[%d]\n", n);
                    if (n <= 0)
                    {
                        printf("lost link\n");
                        epoll_ctl(tree, EPOLL_CTL_DEL, x, &events[i]);
                        break;

                    }
                    std::fstream file("./fuck.jpg", std::ios::app | std::ios::binary);
                    file.write(temp, q);
                    file.close();
                    printf("%s\n", temp);
                }
                //*trans thread

            }
        }
    }


}


