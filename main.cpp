#include"./src/mes.hpp"


void abc(void*)
{

}
void bcd(void*)
{

}
int main()
{
    int a1 = 10;
    myEpoll a(a1, abc);
    a.wait();

}


