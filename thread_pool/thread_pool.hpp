#pragma once
#include<thread>
#include<mutex>
#include<queue>
template<typename T>
class news_queue
{
    int news_max;
    int news_current;
    std::queue<T>* news_queue;
public:
    news_queue(int max=1024):news_max(max),news_current(0)
    {
        news_queue = new std::queue<T>;
    }



};



class thread_pool
{
    int thread_max;
    int thread_current;
    bool is_run;
public:
    thread_pool(int max = 16) :thread_max(max), thread_current(6), is_run(false) {};


};