#include<iostream>
#include<mutex>
#include<vector>
#include<thread>
#include<unistd.h>


int main()
{

    auto t1 = std::thread([]()
        {
            sleep(1);
            std::cout << "test1" << std::endl;
            std::cout << std::this_thread::get_id() << std::endl;
            std::this_thread::yield();
            std::cout << "test1" << std::endl;

        });

    std::cout << t1.get_id() << std::endl;
    auto t2 = std::thread([]()
        {
            std::cout << "test2" << std::endl;
        });
    t2.join();
    auto t3 = std::thread([]()
        {
            sleep(2);
            std::cout << "test3" << std::endl;
        });
    t3.detach();
    t1.join();





    // t1.join();
    // t2.join();
    // t3.join();


    return 0;
}