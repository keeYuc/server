
#include<sys/shm.h>
#include<iostream>



int main()
{
    key_t key = ftok("/home/keeyu/mycode/server/share_m/", 88);
    if (shmget(key, 1024 * 4, IPC_CREAT) == -1)
    {
        std::cout << "shmget err!\n";
    }
    void* ptr = shmat(key, nullptr, 0);
    if (*((int*) (ptr)) == -1)
    {
        std::cout << "shmat err!\n";
    }
    
}