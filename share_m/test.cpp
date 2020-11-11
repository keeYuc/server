#include<sys/ipc.h>
#include<sys/shm.h>
#include<iostream>
#include<string.h>



int main()
{

    key_t key = ftok("/home/keeyu/mycode/server/", 88);
    // std::cout << key << std::endl;
    int mid = shmget(key, 1024, IPC_CREAT | 0664);
    std::cout << mid << std::endl;
    auto ptr = shmat(mid, nullptr, 0);
    memcpy(ptr, "abc", 3);


    getchar();
    shmid_ds* buf;
    shmctl(mid, IPC_STAT, buf);
    shmdt(ptr);
    std::cout << buf->shm_nattch;
    shmctl(mid, IPC_RMID, nullptr);
}