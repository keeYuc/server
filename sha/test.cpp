#include<string.h>
#include<openssl/sha.h>
#include<iostream>
#include"../cpp-base64/base64.h"


int main()
{
    char buff[64];
    char a[4] = "abc";
    SHA256((unsigned char*) a, 4, (unsigned char*) buff);
    auto str=base64_encode(buff);
    //auto str1=base64_decode(str);
    printf("%s\n", str.data());
    return 0;
}