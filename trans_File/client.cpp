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
    std::fstream file("./fucker.png", std::ios::in | std::ios::binary);
    file.seekg(0, file.end);
    int n = file.tellg();
    // char buff[n];
    // 
    file.seekg(0, std::ios::beg);
    char a[12];
    // char b[n];
    bzero(a, 12);
    // bzero(b, n);
    sprintf(a, "%d", n);
    write(fd, a, 12);std::cout << n;
    int sum;
    int trans_max = 1024 * 256;
    for (;file.tellg() < n;)
    {

        if (trans_max < (n - file.tellg()))
        {
            char buff[trans_max];
            bzero(buff, trans_max);
            file.read(buff, trans_max);
            write(fd, buff, trans_max);
            sum += trans_max;
            printf("----send[%d]-----sum:%d\n", trans_max, sum);

        } else
        {
            int last = n - file.tellg();
            sum += last;
            char buff[last];
            bzero(buff, last);
            file.read(buff, last);
            write(fd, buff, last);
            printf("----send[%d]-----sum:%d\n", last, sum);

        }
    }

    return 0;
}