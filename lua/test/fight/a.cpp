#include<iostream>
#include<tuple>
#include<string>

// std::tuple<int, double, std::string>fo()
// {
//     return std::make_tuple(1, 1.2, "ssss");
// }
// int main()
// {

//     auto [x, y, z] = fo();
//     std::cout << x << y << z << std::endl;
//     return 0;
// }


// decltype(auto) test(){
//     return 10;
// }
// int main(){

//     std::cout << test()<<std::endl;
// }

// template<typename T,typename... T1>
// auto print2(T t,T1...t1)
// {
//     std::cout << t << std::endl;
//     if constexpr (sizeof...(t1) > 0)print2(t1...);
// }
auto add = [](auto x, auto y)
{
    return x + y;
};
int main()
{
    add(1, 2);
    add(1.1, 2.2);
}


