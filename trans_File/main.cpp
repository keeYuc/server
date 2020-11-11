#include"../src/mes.hpp"
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
                char buff[1024];

                system("rm ./fuck.png");
                //sleep(2);
                std::fstream file("./fuck.png", std::ios::app | std::ios::binary);
                bzero(buff, 12);
                n = read(x, buff, 12);
                int q = atoi(buff);
                printf("%d\n", q);
                int sum;
                int max = q;
                while (n < q)
                {
                    if (q > 1024 * 256)
                    {
                        max = 1024 * 256;
                    }

                    char temp[max];
                    bzero(temp, max);
                    n = read(x, temp, max);
                    file.write(temp, n);
                    sum += n;
                    printf("[%d]---sum[%d]\n", n, sum);
                    if (n <= 0)
                    {
                        printf("lost link------lost:%d\n", q - sum);
                        epoll_ctl(tree, EPOLL_CTL_DEL, x, &events[i]);
                        file.close();
                        return 0;

                    }

                }
                epoll_ctl(tree, EPOLL_CTL_DEL, x, &events[i]);
                file.close();
                return 0;

                //printf("%s\n", temp);

            //*trans thread

            }
        }
    }


}


