#include<string.h>
#include<openssl/sha.h>
#include<iostream>
#include"../cpp-base64/base64.h"


int main()
{
    char buff[64];
    char a[] = "a1b22sdadafafafewrwrwrwrwr";
    SHA512((unsigned char*) a, 27, (unsigned char*) buff);
    auto str = base64_encode(buff);
    //auto str1=base64_decode(str);
    printf("%s编码前长度[%ld]编码后长度[%ld]\n", str.data(), strlen(buff), str.size());
    auto str1 = base64_decode(str);
    printf("%s\n长度[%ld]", str1.data(), str1.size());
    return 0;
}