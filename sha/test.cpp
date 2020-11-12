#include<string.h>
#include<openssl/sha.h>
#include<iostream>
#include"../base64/base64.hpp"


int main()
{
    char buff[64];
    char a[4] = "abc";
    SHA256((unsigned char*) a, 4, (unsigned char*) buff);
    Base64Encrypt a;
    

    printf("%s\n", buff);
    return 0;
}