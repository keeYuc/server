
#include<sys/shm.h>
#include<iostream>
#include<string.h>


int main()
{
    key_t key = ftok("/home/keeyu/mycode/server/", 88);
    auto a = shmget(key, 1024, IPC_CREAT|0664);
    void* ptr = shmat(a, nullptr, 0);
    char b[3];
    memcpy(b, ptr, 3);
    printf("%s\n", b);


    getchar();
}