#include<string.h>
#include<openssl/sha.h>
#include<iostream>



int main()
{
    char buff[64];
    char a[4] = "abc";
    SHA256((unsigned char*)a, 4, (unsigned char*) buff);
    printf("%s\n", buff);
    return 0;
}